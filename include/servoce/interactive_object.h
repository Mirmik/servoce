#ifndef SERVOCE_INTERACTIVE_OBJECT_H
#define SERVOCE_INTERACTIVE_OBJECT_H

#include <servoce/shape.h>
#include <servoce/color.h>
#include <servoce/boundbox.h>

#include <AIS_InteractiveObject.hxx>
#include <AIS_InteractiveContext.hxx>

#include <servoce/transformable.h>
#include <servoce/transformable_impl.h>
#include <servoce/self_transformable.h>

#include <cassert>

namespace servoce
{
	class scene;

	class interactive_object : public transformable<interactive_object, std::shared_ptr<interactive_object>>, public std::enable_shared_from_this<interactive_object>
	//class interactive_object : public self_transformable
	{
		Handle(AIS_InteractiveObject) m_ais = nullptr;
		Handle(AIS_InteractiveContext) m_context = nullptr;
		scene * scn = nullptr;

		friend servoce::scene;

	public:
		interactive_object(Handle(AIS_InteractiveObject) ais) : m_ais(ais) {}
		interactive_object(const shape& shp);
		interactive_object(const shape& shp, const servoce::color& clr);

		servoce::color color() const;
		void set_color(const servoce::color&);
		void set_color(float r, float g, float b, float a = 0);

		Handle(AIS_InteractiveObject) native() { return m_ais; }
		Handle(AIS_InteractiveObject) const native() const { return m_ais; }

		void set_location(const servoce::transformation& trans);
		void relocate(const servoce::transformation& trans);

		void hide(bool en);
		bool is_shape();

		servoce::shape shape();

		void set_context(Handle(AIS_InteractiveContext) cntxt) { m_context = cntxt; }

		boundbox bounding_box();

		transformation location()
		{
			//assert(m_context);
			//assert(m_ais);

			return m_context->Location(m_ais).Transformation();
		}

		/*void self_transform(const transformation& trans) override
		{
			assert(m_context);
			assert(m_ais);

			relocate(location() * trans);
		}*/

		std::shared_ptr<interactive_object> self_transform(const transformation& trans)
		{
			//assert(m_context);
			//assert(m_ais);

			relocate(location() * trans);
			return shared_from_this();
		}

		// Биндим на метод трансформации изменение самого себя.
		std::shared_ptr<interactive_object> transform(const transformation& trans) const
		{
			//assert(m_context);
			//assert(m_ais);

			return ((interactive_object*)this)->self_transform(trans);
		}

		std::shared_ptr<interactive_object>  transform(const general_transformation& trans) const 
		{ 
			(void)trans; throw std::runtime_error("general transformation not supported"); 
		}
	
		std::shared_ptr<interactive_object> copy(bool bind_to_scene = true);
	};
}

#endif