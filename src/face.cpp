#include <servoce/face.h>
#include <servoce/wire.h>

#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <GC_MakeCircle.hxx>
#include <GC_MakeEllipse.hxx>

#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>
#include <BRepFilletAPI_MakeFillet2d.hxx>
#include <BRepTools_WireExplorer.hxx>
#include <TopExp_Explorer.hxx>

#include <BRepAdaptor_Curve.hxx>

#include <BRepOffsetAPI_MakePipe.hxx>
#include <Font_BRepTextBuilder.hxx>

servoce::shape servoce::circle(double r, bool wire)
{
	gp_Circ EL ( gp::XOY(), r );
	Handle(Geom_Circle) anCircle = GC_MakeCircle(EL).Value();
	TopoDS_Edge aEdge = BRepBuilderAPI_MakeEdge( anCircle );
	TopoDS_Wire aCircle = BRepBuilderAPI_MakeWire( aEdge );
	if (wire)
		return aCircle;
	return BRepBuilderAPI_MakeFace(aCircle).Shape();
}

servoce::shape servoce::circle(double r, double angle, bool wire)
{
	gp_Circ EL ( gp::XOY(), r );
	Handle(Geom_Circle) anCircle = GC_MakeCircle(EL).Value();
	TopoDS_Edge aEdge = BRepBuilderAPI_MakeEdge( anCircle, 0, angle );
	if (wire)
		return BRepBuilderAPI_MakeWire( aEdge ).Shape();
	TopoDS_Edge aEdge1 = BRepBuilderAPI_MakeEdge( gp_Pnt(0, 0, 0), gp_Pnt(r, 0, 0) );
	TopoDS_Edge aEdge2 = BRepBuilderAPI_MakeEdge( gp_Pnt(0, 0, 0), gp_Pnt(r * cos(angle), r * sin(angle), 0)  );
	TopoDS_Wire aCircle = BRepBuilderAPI_MakeWire( aEdge, aEdge1, aEdge2 );
	return BRepBuilderAPI_MakeFace(aCircle).Shape();
}

servoce::shape servoce::circle(double r, double a1, double a2, bool wire)
{
	gp_Circ EL ( gp::XOY(), r );
	Handle(Geom_Circle) anCircle = GC_MakeCircle(EL).Value();
	TopoDS_Edge aEdge = BRepBuilderAPI_MakeEdge( anCircle, a1, a2 );
	if (wire)
		return BRepBuilderAPI_MakeWire( aEdge ).Shape();
	TopoDS_Edge aEdge1 = BRepBuilderAPI_MakeEdge( gp_Pnt(0, 0, 0), gp_Pnt(r * cos(a1), r * sin(a1), 0) );
	TopoDS_Edge aEdge2 = BRepBuilderAPI_MakeEdge( gp_Pnt(0, 0, 0), gp_Pnt(r * cos(a2), r * sin(a2), 0)  );
	TopoDS_Wire aCircle = BRepBuilderAPI_MakeWire( aEdge, aEdge1, aEdge2 );
	return BRepBuilderAPI_MakeFace(aCircle).Shape();
}


servoce::shape servoce::ellipse(double r1, double r2, bool wire)
{
	gp_Elips EL ( gp::XOY(), r1, r2 );
	Handle(Geom_Ellipse) anCircle = GC_MakeEllipse(EL).Value();
	TopoDS_Edge aEdge = BRepBuilderAPI_MakeEdge( anCircle );
	TopoDS_Wire w = BRepBuilderAPI_MakeWire( aEdge );
	if (wire)
		return w;
	return BRepBuilderAPI_MakeFace(w).Shape();
}

servoce::shape servoce::ellipse(double r1, double r2, double a1, double a2, bool wire)
{
	gp_Elips EL ( gp::XOY(), r1, r2 );
	Handle(Geom_Ellipse) anCircle = GC_MakeEllipse(EL).Value();
	TopoDS_Edge aEdge = BRepBuilderAPI_MakeEdge( anCircle, a1, a2 );
	if (wire)
		return BRepBuilderAPI_MakeWire( aEdge ).Shape();

	BRepAdaptor_Curve curve(aEdge);
	gp_Pnt p1, p2;
	curve.D0(a1, p1);
	curve.D0(a2, p2);

	TopoDS_Edge aEdge1 = BRepBuilderAPI_MakeEdge( gp_Pnt(0, 0, 0), p1 );
	TopoDS_Edge aEdge2 = BRepBuilderAPI_MakeEdge( gp_Pnt(0, 0, 0), p2 );
	TopoDS_Wire aCircle = BRepBuilderAPI_MakeWire( aEdge, aEdge1, aEdge2 );
	return BRepBuilderAPI_MakeFace(aCircle).Shape();
}





servoce::shape servoce::polygon(const servoce::point3* pnts, size_t size)
{
	BRepBuilderAPI_MakePolygon mk;
	for (uint i = 0; i < size; ++i) mk.Add(pnts[i].Pnt());
	mk.Close();
	return BRepBuilderAPI_MakeFace(mk).Shape();
}

servoce::shape servoce::polygon(const std::vector<servoce::point3>& pnts)
{
	return polygon(pnts.data(), pnts.size());
}

servoce::shape servoce::ngon(double r, int n, bool wire)
{
	double angle;
	servoce::point3* pnts = (servoce::point3*) alloca(sizeof(servoce::point3) * n);
	for (int i = 0; i < n; ++i)
	{
		angle = 2 * M_PI / n * i;
		pnts[i] = servoce::point3(r * cos(angle), r * sin(angle), 0);
	}
	if (wire)
	{
		std::vector<servoce::point3> pntsvec;
		for (int i = 0; i < n; ++i) pntsvec.push_back(pnts[i]);
		return servoce::make_polysegment(pntsvec, true);
	}
	return polygon(pnts, n);
}

servoce::shape servoce::rectangle(double a, double b, bool center, bool wire)
{
	if (center)
	{
		double x = a / 2;
		double y = b / 2;
		if (wire)
			return make_polysegment({{ -x, -y}, {x, -y}, {x, y}, { -x, y}}, true);
		return polygon({{ -x, -y}, {x, -y}, {x, y}, { -x, y}});
	}
	else
	{
		if (wire)
			return make_polysegment({{0, 0}, {0, b}, {a, b}, {a, 0}}, true);
		return polygon({{0, 0}, {0, b}, {a, b}, {a, 0}});
	}
}

servoce::shape servoce::square(double a, bool center, bool wire)
{
	return rectangle(a, a, center, wire);
}

servoce::shape servoce::textshape(const std::string& text, const std::string fontpath, size_t size)
{
	Font_BRepTextBuilder builder;
	Font_BRepFont font;

	bool okfont = font.Init(fontpath.c_str(), size);
	if (!okfont)
	{
		throw std::runtime_error("Wrong font path.");
	}

	NCollection_String collection(text.c_str());
	TopoDS_Shape textshp = builder.Perform (font, collection);
	return textshp;
}

servoce::shape servoce::fill(const std::vector<servoce::shape*>& arr)
{
	BRepBuilderAPI_MakeFace mk(arr[0]->Wire_orEdgeToWire());

	for (unsigned int i = 1; i < arr.size(); i++)
	{
		mk.Add(arr[i]->Wire_orEdgeToWire());
	}
	return mk.Face();
}

servoce::shape servoce::fillet2d(const servoce::shape& shp, double r, const std::vector<servoce::point3>& refs)
{
	BRepFilletAPI_MakeFillet2d mk(shp.Face());

	for (auto& p : refs)
	{
		mk.AddFillet(near_vertex(shp, p).Vertex(), r);
	}

	return mk.Shape();
}


servoce::shape servoce::fillet2d(const servoce::shape& shp, double r)
{
	BRepFilletAPI_MakeFillet2d mk(shp.Face());

	for (TopExp_Explorer expWire(shp.Shape(), TopAbs_WIRE); expWire.More(); expWire.Next())
	{
		BRepTools_WireExplorer explorer(TopoDS::Wire(expWire.Current()));

		while (explorer.More())
		{
			const TopoDS_Vertex& vtx = explorer.CurrentVertex();
			mk.AddFillet(vtx, r);

			explorer.Next();
		}
	}

	return mk.Shape();
}

servoce::shape servoce::chamfer2d(const servoce::shape& shp, double r, const std::vector<servoce::point3>& refs)
{
	throw std::runtime_error("chamfer2d. TODO.");
}


servoce::shape servoce::chamfer2d(const servoce::shape& shp, double r)
{
	throw std::runtime_error("chamfer2d. TODO.");
}
