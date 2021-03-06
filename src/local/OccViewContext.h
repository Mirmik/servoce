#ifndef SERVOCE_OCCVIEWCONTEXT_H
#define SERVOCE_OCCVIEWCONTEXT_H

#include <string>

#include <OpenGl_GraphicDriver.hxx>

#include <V3d_View.hxx>
#include <V3d_AmbientLight.hxx>
#include <V3d_DirectionalLight.hxx>

#include <Aspect_Handle.hxx>
#include <Aspect_DisplayConnection.hxx>

#if defined(WNT) || defined(_MSC_VER)
#include <WNT_Window.hxx>
#elif defined(__APPLE__) && !defined(MACOSX_USE_GLX)
#include <Cocoa_Window.hxx>
#else
#undef Bool
#undef CursorShape
#undef None
#undef KeyPress
#undef KeyRelease
#undef FocusIn
#undef FocusOut
#undef FontChange
#undef Expose
#include <Xw_Window.hxx>
#include <X11/Xlib.h>
#endif

#include <AIS_InteractiveContext.hxx>
#include <AIS_Shape.hxx>
#include <AIS_Axis.hxx>
#include <Geom_Axis1Placement.hxx>

#include <mutex>

extern Handle(Aspect_DisplayConnection) g_displayConnection;
extern Handle(Graphic3d_GraphicDriver) g_graphicDriver;
Handle(Aspect_DisplayConnection) GetDisplayConnection();
Handle(Graphic3d_GraphicDriver) GetGraphicDriver();

extern std::recursive_mutex viewrecursive_mutex;

class OccViewerContext;

class OccViewWindow
{
public:
	Handle(V3d_View) m_view;

#if defined(WNT) || defined(_MSC_VER)
	Handle(WNT_Window) m_window;
#elif defined(__APPLE__) && !defined(MACOSX_USE_GLX)
	Handle(Cocoa_Window) m_window;
#else
	Handle(Xw_Window) m_window;
#endif

	OccViewerContext* parent;
#if defined(__APPLE__)
	void* winddesc;
#else
	int winddesc;
#endif

public:
	OccViewWindow(Handle(V3d_View) view, OccViewerContext* parent)
		: m_view(view), parent(parent)
	{}

	void set_virtual_window(int w, int h)
	{
		std::lock_guard<std::recursive_mutex> lock(viewrecursive_mutex);
		static int i = 0;

#if defined(WNT) || defined(_MSC_VER)
		//m_window = new WNT_Window ((std::string("virtual") + std::to_string(i++)).c_str(), 0, 0, w, h);
		throw std::runtime_error("set_virtual_window::windows not supported");
#elif defined(__APPLE__) && !defined(MACOSX_USE_GLX)
		m_window = new Cocoa_Window ((std::string("virtual") + std::to_string(i++)).c_str(), 0, 0, w, h);
		m_window->SetVirtual  (Standard_True);
		winddesc = (void*)m_window->NativeHandle();
		m_view->SetWindow  (m_window);
#else
		m_window = new Xw_Window (GetDisplayConnection(), (std::string("virtual") + std::to_string(i++)).c_str(), 0, 0, w, h);
		m_window->SetVirtual  (Standard_True);
		winddesc = m_window->NativeHandle();
		m_view->SetWindow  (m_window);
#endif
	}

#if defined(__APPLE__)
	void set_window(void* window_handle)
#else
	void set_window(int  window_handle)
#endif
	{
		std::lock_guard<std::recursive_mutex> lock(viewrecursive_mutex);
		winddesc = window_handle;

#if defined(WNT) || defined(_MSC_VER)
		m_window = new WNT_Window((Aspect_Handle) window_handle);
#elif defined(__APPLE__) && !defined(MACOSX_USE_GLX)
		m_window = new Cocoa_Window((NSView *) window_handle);
#else
		m_window = new Xw_Window(GetDisplayConnection(), (Window) window_handle);
#endif

		m_view->SetWindow(m_window);
		//if (!m_window->IsMapped()) m_window->Map();
		//m_window->DoResize();
		//m_view.ReSize(800,600);
	}

	void fit_all()
	{
		std::lock_guard<std::recursive_mutex> lock(viewrecursive_mutex);
		m_view->FitAll();
	}

	void dump(const std::string& path)
	{
		std::lock_guard<std::recursive_mutex> lock(viewrecursive_mutex);
		m_view->Dump(path.c_str());
	}

	void redraw()
	{
		std::lock_guard<std::recursive_mutex> lock(viewrecursive_mutex);
		m_view->Redraw();
	}

	void must_be_resized()
	{
		std::lock_guard<std::recursive_mutex> lock(viewrecursive_mutex);
		m_view->MustBeResized();
	}

	void set_triedron(bool en = true)
	{
		std::lock_guard<std::recursive_mutex> lock(viewrecursive_mutex);

		if (en)
			m_view->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.08, V3d_ZBUFFER);
		else
			m_view->TriedronErase();
	}

	gp_Lin viewline(double x, double y, Handle(V3d_View) view)
	{
		std::lock_guard<std::recursive_mutex> lock(viewrecursive_mutex);
		Standard_Real Xp = x, Yp = y;
		Standard_Real Xv, Yv, Zv;
		Standard_Real Vx, Vy, Vz;

		view->Convert( Xp, Yp, Xv, Yv, Zv );
		view->Proj( Vx, Vy, Vz );

		return gp_Lin(gp_Pnt(Xv, Yv, Zv), gp_Dir(Vx, Vy, Vz));
	}

};


class OccViewerContext
{
public:
	Handle(AIS_InteractiveContext) m_context;
	Handle(V3d_Viewer) m_viewer;

	Handle(AIS_Axis) axX;
	Handle(AIS_Axis) axY;
	Handle(AIS_Axis) axZ;

public:
	OccViewerContext(bool pretty)
	{
		std::lock_guard<std::recursive_mutex> lock(viewrecursive_mutex);

		if (pretty)
		{
			//static Quantity_Color c1(0.5, 0.5, 0.5, Quantity_TOC_RGB);
			//static Quantity_Color c2(0.3, 0.3, 0.3, Quantity_TOC_RGB);

			axX = new AIS_Axis(new Geom_Axis1Placement(gp_Pnt(0, 0, 0), gp_Vec(1, 0, 0)));
			axY = new AIS_Axis(new Geom_Axis1Placement(gp_Pnt(0, 0, 0), gp_Vec(0, 1, 0)));
			axZ = new AIS_Axis(new Geom_Axis1Placement(gp_Pnt(0, 0, 0), gp_Vec(0, 0, 1)));

			axX->SetColor(Quantity_NOC_RED);
			axY->SetColor(Quantity_NOC_GREEN);
			axZ->SetColor(Quantity_NOC_BLUE1);

			m_viewer = new V3d_Viewer(GetGraphicDriver());

			m_viewer->SetDefaultLights();
			m_viewer->SetLightOn();

			m_context = new AIS_InteractiveContext (m_viewer);
			m_context->SetDisplayMode(AIS_Shaded, false);
			m_context->DefaultDrawer()->SetFaceBoundaryDraw(true);
			
			//Quantity_Color clr(0,0,0,Quantity_TOC_RGB );
			//auto aspect = m_context->DefaultDrawer()->FaceBoundaryAspect();
			//Handle(Prs3d_LineAspect) aspect = new Prs3d_LineAspect(clr, Aspect_TOL_SOLID, 10);
			//m_context->DefaultDrawer()->SetFaceBoundaryAspect(aspect);
		} 

		else 
		{
			m_viewer = new V3d_Viewer(GetGraphicDriver());
			m_context = new AIS_InteractiveContext (m_viewer);
		}
	} 

	OccViewWindow* create_view_window()
	{
		std::lock_guard<std::recursive_mutex> lock(viewrecursive_mutex);
		auto ret = new OccViewWindow( m_viewer->CreateView(), this );
		return ret;
	}

//	void set_scene(const servoce::scene& scn)
//	{
//		std::lock_guard<std::recursive_mutex> lock(viewrecursive_mutex);
//		for (auto& shp : scn.shapes)
//		{
//			m_context->Display (shp.m_ashp, false);
//		}
//	}

	void set_triedron_axes()
	{
		std::lock_guard<std::recursive_mutex> lock(viewrecursive_mutex);
		Handle(AIS_Axis) axX = new AIS_Axis(new Geom_Axis1Placement(gp_Pnt(0, 0, 0), gp_Vec(1, 0, 0)));
		Handle(AIS_Axis) axY = new AIS_Axis(new Geom_Axis1Placement(gp_Pnt(0, 0, 0), gp_Vec(0, 1, 0)));
		Handle(AIS_Axis) axZ = new AIS_Axis(new Geom_Axis1Placement(gp_Pnt(0, 0, 0), gp_Vec(0, 0, 1)));

		axX->SetColor(Quantity_NOC_RED);
		axY->SetColor(Quantity_NOC_GREEN);
		axZ->SetColor(Quantity_NOC_BLUE1);

		m_context->Display(axX, false);
		m_context->Display(axY, false);
		m_context->Display(axZ, false);
	}
};

#endif
