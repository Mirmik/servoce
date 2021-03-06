#ifndef SERVOCE_GEOMPROPS_H
#define SERVOCE_GEOMPROPS_H

#include <servoce/shape.h>
#include <BRepGProp.hxx>
#include <GProp_GProps.hxx>

namespace servoce 
{
	class geomprops : public GProp_GProps
	{
		 // _props;

	public:	
		static geomprops linear_properties(const servoce::shape& shp, double density=1);
		static geomprops surface_properties(const servoce::shape& shp, double density=1);
		static geomprops volume_properties(const servoce::shape& shp, double density=1);

		geomprops(const GProp_GProps& props) : GProp_GProps(props) {}
		geomprops(const geomprops& props) = default;

		//void add(const GProp_GProps& oth);

		//Returns the mass of the current system. If no density is attached to the components of the current system the returned value corresponds to : More...
		double mass () const;
 
		//Returns the center of mass of the current system. If the gravitational field is uniform, it is the center of gravity. The coordinates returned for the center of mass are expressed in the absolute Cartesian coordinate system. More...
 		//servoce::vector3 center_of_mass () const;
 		servoce::vector3 cmradius () const 
 		{ 
 			auto pnt = CentreOfMass();
 			return gp_Vec(pnt.X(), pnt.Y(), pnt.Z()); 
 		}

 		servoce::point3 center () const 
 		{ 
 			auto pnt = CentreOfMass();
 			return gp_Pnt(pnt.X(), pnt.Y(), pnt.Z()); 
 		}
 	
		//returns the matrix of inertia. It is a symmetrical matrix. The coefficients of the matrix are the quadratic moments of inertia. More...
 		servoce::matrix33 matrix_of_inertia () const;

		//Returns Ix, Iy, Iz, the static moments of inertia of the current system; i.e. the moments of inertia about the three axes of the Cartesian coordinate system. More... 	
		std::tuple<double,double,double> static_moments () const;
 
		//computes the moment of inertia of the material system about the axis A. More...
 		double moment_of_inertia(const servoce::vector3& axis) const;
		 
		//Returns the radius of gyration of the current system about the axis A. More...
		double radius_of_gyration(const servoce::vector3& axis) const;

		//GProp_PrincipalProps 	PrincipalProperties () const
		// 	Computes the principal properties of inertia of the current system. There is always a set of axes for which the products of inertia of a geometric system are equal to 0; i.e. the matrix of inertia of the system is diagonal. These axes are the principal axes of inertia. Their origin is coincident with the center of mass of the system. The associated moments are called the principal moments of inertia. This function computes the eigen values and the eigen vectors of the matrix of inertia of the system. Results are stored by using a presentation framework of principal properties of inertia (GProp_PrincipalProps object) which may be queried to access the value sought. More...
	

		std::tuple<servoce::vector3, servoce::vector3, servoce::vector3> principal_inertia_axes() const;
		servoce::transformation inertia_frame() const;
		std::tuple<double, double, double> principal_inertia_moments() const;		
	};
}

#endif