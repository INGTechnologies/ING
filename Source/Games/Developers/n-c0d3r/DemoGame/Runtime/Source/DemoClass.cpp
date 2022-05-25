
/**
 *	Include Header
 */
#include "DemoClass.h"



#include <functional>



namespace Demo {

	ING_BEGIN_REFLECTED_CLASS(DemoClass, IObject)

		ING_CLASS_FUNCTION(DemoClass::Fn, DemoClass, void)
			.ACCESS(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG(CLASS_MEMBER_TAG_EDIT_EVERYWHERE);

	ING_END_REFLECTED_CLASS ()

	void DemoClass::Fn() {

		Debug::Log("DemoClass Fn Log");

	}

}