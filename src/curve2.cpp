#include <servoce/curve2.h>
#include <Geom2d_Curve.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <Geom2d_Ellipse.hxx>
#include <gp_Ax2d.hxx>
#include <GCE2d_MakeSegment.hxx>
#include <BinTools_Curve2dSet.hxx>

#include <nos/trace.h>
#include <nos/print.h>

using namespace servoce::curve2;

trimmed_curve2::trimmed_curve2(Handle(Geom2d_TrimmedCurve) tcrv) : curve2(tcrv) {}

trimmed_curve2::trimmed_curve2(const curve2& crv, double start, double stop) 
	: curve2(new Geom2d_TrimmedCurve(crv.crv, start, stop)) {}

curve2 servoce::curve2::ellipse(double major, double minor)
{
	return Handle(Geom2d_Curve)(new Geom2d_Ellipse(gp_Ax2d(gp_Pnt2d(0,0), gp_Dir2d(1,0)), major, minor));
}

Handle(Geom2d_TrimmedCurve) servoce::curve2::trimmed_curve2::TrimmedCurve() 
{
	return Handle(Geom2d_TrimmedCurve)::DownCast(crv);
}

const Handle(Geom2d_TrimmedCurve) servoce::curve2::trimmed_curve2::TrimmedCurve() const 
{
	return Handle(Geom2d_TrimmedCurve)::DownCast(crv);
}

Handle(Geom2d_Curve) servoce::curve2::curve2::Curve() 
{
	return crv;
}

const Handle(Geom2d_Curve) servoce::curve2::curve2::Curve() const 
{
	return crv;
}

servoce::point2 servoce::curve2::curve2::value(double arg) 
{
	return crv->Value(arg);
}

//servoce::curve2::curve2::curve2(const Geom2d_Curve& crv) 
//{
//	crv = new Geom2d_Curve(crv);
//}

servoce::curve2::curve2 servoce::curve2::segment(servoce::point2 a, servoce::point2 b) 
{
	return Handle(Geom2d_Curve)(GCE2d_MakeSegment(a.Pnt(), b.Pnt()).Value());
}

servoce::curve2::curve2::curve2(Handle(Geom2d_Curve) crv) : crv(crv) {}

servoce::curve2::curve2 servoce::curve2::curve2::rotate(double angle) 
{
	gp_Trsf2d trsf;
	trsf.SetRotation(gp_Pnt2d(0,0), angle);
	return Handle(Geom2d_Curve)::DownCast(crv->Transformed(trsf));
}

void servoce::curve2::curve2::dump(std::ostream& out) const
{
	TRACE();
	BinTools_Curve2dSet instrument;

	Handle(Geom2d_Curve) h = Handle(Geom2d_Curve)::DownCast(crv);
	//instrument.Add(h);
	//instrument.Write(out);
	BinTools_Curve2dSet::WriteCurve2d(h, out);

	//if (crv->IsNull())
	//{
		//instrument.Add(crv);
		//instrument.Write(out);
	//	theShapeSet.Add(*m_shp);
	//	theShapeSet.Write(out);
	//	BinTools::PutInteger(out, -1);
	//	BinTools::PutInteger(out, -1);
	//	BinTools::PutInteger(out, -1);
	//}
	//else
	//{
	//	instrument.Add(*crv);
	//	instrument.Write(out);
	//	Standard_Integer shapeId = theShapeSet.Add(*m_shp);
	//	Standard_Integer locId = theShapeSet.Locations().Index(m_shp->Location());
	//	Standard_Integer orient = static_cast<int>(m_shp->Orientation());

	//	theShapeSet.Write(out);
	//	BinTools::PutInteger(out, shapeId);
	//	BinTools::PutInteger(out, locId);
	//	BinTools::PutInteger(out, orient);
	//}
}

void servoce::curve2::curve2::load(std::istream& in)
{
	TRACE();
	//BinTools_Curve2dSet instrument;
	//instrument.Read(in);
	Handle(Geom2d_Curve) h;
	BinTools_Curve2dSet::ReadCurve2d (in, h);
	crv = Handle(Geom2d_Curve)::DownCast(h);
	//theShapeSet.Read(in);
	//Standard_Integer shapeId = 0, locId = 0, orient = 0;
	//BinTools::GetInteger(in, shapeId);
//
	//if (shapeId <= 0 || shapeId > theShapeSet.NbShapes())
	//	return;
//
	//BinTools::GetInteger(in, locId);
	//BinTools::GetInteger(in, orient);
	//TopAbs_Orientation anOrient = static_cast<TopAbs_Orientation>(orient);
//
	//*m_shp = theShapeSet.Shape(shapeId);
	//m_shp->Location(theShapeSet.Locations().Location (locId));
	//m_shp->Orientation (anOrient);
}
//
//
//std::string servoce::shape::string_dump() const
//{
//	std::stringstream sstrm;
//	dump(sstrm);
//	return sstrm.str();
//}
//
//servoce::shape servoce::shape::restore_string_dump(const std::string& in)
//{
//	std::stringstream sstrm(in);
//	servoce::shape shp;
//	shp.m_shp = new TopoDS_Solid;
//	shp.load(sstrm);
//	return shp;
//}//