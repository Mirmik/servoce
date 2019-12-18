#ifndef SERVOCE_EDGE_H
#define SERVOCE_EDGE_H

#include <servoce/topo.h>
#include <servoce/curve3.h>

#include <BRepAdaptor_Curve.hxx>

#include <servoce/curve_algo.h>

namespace servoce {
	class edge_shape : public shape, public curve_algo<edge_shape, servoce::point3>
	{
	public:
		using crvalgo = curve_algo<edge_shape, servoce::point3>;

		//edge_shape(TopoDS_Edge& arg) : shape(arg) {}
		edge_shape(){}
		edge_shape(const TopoDS_Edge& arg) : shape((const TopoDS_Shape&)arg) {}

		std::pair<double,double> range();

		BRepAdaptor_Curve AdaptorCurve() const;

		//curve3::curve3& adaptor_curve
	};

	edge_shape make_edge(const servoce::curve3::curve3& crv);
	edge_shape make_edge(const servoce::curve3::curve3& crv, double strt, double fini);

	edge_shape make_segment(const point3& a, const point3& b);
	
	edge_shape make_interpolate(const std::vector<point3>& pnts, bool closed = false);
	edge_shape make_interpolate(const std::vector<point3>& pnts, const vector3& atang, const vector3& btang, bool closed = false);
	edge_shape make_interpolate(const std::vector<point3>& pnts, const std::vector<vector3>& tang, bool closed = false);

	//shape make_arc_by_points(const point3& a, const point3& b, const point3& c);

	edge_shape bezier(const std::vector<point3>& pnts);
	edge_shape bezier(const std::vector<point3>& pnts, const std::vector<double>& weights);

	edge_shape bspline(
		const std::vector<point3>& poles,
		const std::vector<double>& knots,
		const std::vector<int>& multiplicities,
		int degree,
		bool periodic=false
	);

	edge_shape bspline(
		const std::vector<point3>& poles,
		const std::vector<double>& weights,
		const std::vector<double>& knots,
		const std::vector<int>& multiplicities,
		int degree,
		bool periodic=false,
		bool check_rational=true 
	);

	edge_shape circle_arc(const point3& p1, const point3& p2, const point3& p3);
}

#endif