/**
	Python bind for servoce::shape
*/

#include <pybind11/pybind11.h>
#include <local/pywrap_util.h>

#include <servoce/util.h>
#include <servoce/util/b64.h>
#include <servoce/shape.h>
#include <servoce/solid.h>
#include <servoce/shell.h>
#include <servoce/wire.h>
#include <servoce/compsolid.h>
#include <servoce/compound.h>
#include <servoce/face.h>
#include <servoce/edge.h>
#include <servoce/trans.h>
#include <servoce/geomprops.h>

#include <pywrap/transformable.h>

namespace py = pybind11;
using namespace servoce;

void registry_shape(py::module & m)
{
	auto cls = py::class_<shape>(m, "Shape");
	
	pywrap_transformable<servoce::shape>(cls);

	cls
	.def("__add__", (shape(shape::*)(const shape&))&shape::operator+, ungil())
	.def("__sub__", &shape::operator-, ungil())
	.def("__xor__", &shape::operator^, ungil())
	.def(py::pickle(
	[](const shape & self) { return b64::base64_encode(string_dump(self)); },
	[](const std::string & in) { return restore_string_dump<shape>(b64::base64_decode(in)); }), ungil())
	.def("is_nullshape", &shape::is_nullshape)
	.def("fill", &shape::fill)
	.def("center", &shape::center, ungil())
	.def("extrude", (shape(shape::*)(const vector3&, bool)) &shape::extrude, ungil(), py::arg("vec"), py::arg("center") = false)
	.def("extrude", (shape(shape::*)(double, double, double, bool)) &shape::extrude, ungil(), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("center") = false)
	.def("extrude", (shape(shape::*)(double, bool)) &shape::extrude, ungil(), py::arg("z"), py::arg("center") = false)
	.def("is_closed", &shape::is_closed, ungil())
	.def("sfvertex", &shape::sfvertex, ungil())
	.def("endpoints", &shape::sfvertex, ungil())

	.def("vertices", &shape::vertices, ungil())
	.def("solids", &shape::solids, ungil())
	.def("faces", &shape::faces, ungil())
	.def("edges", &shape::edges, ungil())
	.def("wires", &shape::wires, ungil())
	.def("shells", &shape::shells, ungil())
	.def("compounds", &shape::compounds, ungil())
	.def("compsolids", &shape::compsolids, ungil())

	.def("as_vertex", &shape::as_vertex, ungil())
	.def("as_solid", &shape::as_solid, ungil())
	.def("as_face", &shape::as_face, ungil())
	.def("as_edge", &shape::as_edge, ungil())
	.def("as_wire", &shape::as_wire, ungil())
	.def("as_shell", &shape::as_shell, ungil())
	.def("as_compound", &shape::as_compound, ungil())
	.def("as_compsolid", &shape::as_compsolid, ungil())

	.def("shapetype", &shape::shapetype_as_string, ungil())
	.def("print_topo_dump", &shape::print_topo_dump, ungil())

	.def("fillet", (shape(shape::*)(double, const std::vector<point3>&))&shape::fillet, ungil(), py::arg("r"), py::arg("refs"))
	.def("fillet", (shape(shape::*)(double))&shape::fillet, ungil(), py::arg("r"))
	.def("chamfer", (shape(shape::*)(double, const std::vector<point3>&))&shape::chamfer, ungil(), py::arg("r"), py::arg("refs"))
	.def("chamfer", (shape(shape::*)(double))&shape::chamfer, ungil(), py::arg("r"))

	.def("fillet2d", (shape(shape::*)(double, const std::vector<point3>&))&shape::fillet2d, ungil(), py::arg("r"), py::arg("refs"))
	.def("fillet2d", (shape(shape::*)(double))&shape::fillet2d, ungil(), py::arg("r"))
	.def("chamfer2d", (shape(shape::*)(double, const std::vector<point3>&))&shape::chamfer2d, ungil(), py::arg("r"), py::arg("refs"))
	.def("chamfer2d", (shape(shape::*)(double))&shape::chamfer2d, ungil(), py::arg("r"))

	.def("fillet", [](const shape & shp, double r, const py::list & arr) { return fillet(shp, r, points(arr)); }, ungil(), py::arg("r"), py::arg("refs"))
	.def("chamfer", [](const shape & shp, double r, const py::list & arr) { return fillet(shp, r, points(arr)); }, ungil(), py::arg("r"), py::arg("refs"))
	.def("chamfer2d", [](const shape & shp, double r, const py::list & arr) { return fillet(shp, r, points(arr)); }, ungil(), py::arg("r"), py::arg("refs"))
	.def("fillet2d", [](const shape & shp, double r, const py::list & arr) { return fillet(shp, r, points(arr)); }, ungil(), py::arg("r"), py::arg("refs"))

	.def("cmradius", &shape::cmradius, ungil())
	.def("mass", &shape::mass, ungil())
	.def("matrix_of_inertia", &shape::matrix_of_inertia, ungil())
	.def("static_moments", &shape::static_moments, ungil())
	.def("principal_inertia_axes", &shape::principal_inertia_axes, ungil())
	.def("principal_inertia_moments", &shape::principal_inertia_moments, ungil())
	.def("inertia_frame", &shape::inertia_frame, ungil())

	.def("bbox", &servoce::shape::bounding_box, ungil())
	//.def("moment_of_inertia", &shape::moment_of_inertia, ungil()) //TODO
	//.def("radius_of_gyration", &shape::radius_of_gyration, ungil()) //TODO


	.def("props1", &servoce::shape::props1, ungil())
	.def("props2", &servoce::shape::props2, ungil())
	.def("props3", &servoce::shape::props3, ungil())
	;

	m.def("fill", &servoce::fill, ungil());
}