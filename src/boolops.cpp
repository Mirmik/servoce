#include <servoce/boolops.h>
#include <servoce/topo.h>

#include <local/util.h>

#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepAlgoAPI_Common.hxx>
#include <BRepAlgoAPI_Cut.hxx>

#include <gxx/print.h>
#include <chrono>
#include <iostream>

static inline TopoDS_Shape __make_union(const TopoDS_Shape& a, const TopoDS_Shape& b) {
	return BRepAlgoAPI_Fuse(a, b).Shape();
}

servoce::solid servoce::boolops::make_union(const solid& a, const solid& b) {
	return __make_union(a.Shape(), b.Shape());
}

servoce::solid servoce::boolops::make_difference(const solid& a, const solid& b) {
	return BRepAlgoAPI_Cut(a.Shape(), b.Shape()).Shape();
}

servoce::solid servoce::boolops::make_intersect(const solid& a, const solid& b) {
	return BRepAlgoAPI_Common(a.Shape(), b.Shape()).Shape();
}

/*TopoDS_Shape __make_union(const TopoDS_Shape* vec, size_t size) {
	/*if (size == 1) return vec[0];
	
	int rsize = size / 2 + size % 2;
	TopoDS_Shape narr[rsize];
	
	gxx::println("here", rsize);
	for (int i = 0; i < size; ++i)
		narr[i] = vec[i] + vec[size-i-1];
	if (size % 2) 
		narr[rsize-1] = vec[size/2];
	return make_union(narr, rsize);*/
//}

servoce::solid servoce::boolops::make_union(const std::vector<const servoce::solid*>& vec) {
	if (vec.size() == 1) return *vec[0];
	
	int nrsize;
	int rsize = vec.size() / 2 + vec.size() % 2;
	TopoDS_Shape narr[rsize];

	for (int i = 0; i < vec.size() / 2; ++i) {
		narr[i] = __make_union(vec[i]->Shape(), vec[vec.size()-i-1]->Shape());
	}
	if (vec.size() % 2) {
		narr[rsize-1] = vec[vec.size()/2]->Shape();
	}
		
	while (rsize != 1) {
		nrsize = rsize/2 + rsize%2;;
		for (int i = 0; i < rsize / 2; ++i)
			narr[i] = __make_union(narr[i], narr[rsize-i-1]);
		if (rsize % 2) 
			narr[nrsize-1] = narr[rsize/2];
		rsize = nrsize; 
	}

	return narr[0];
}