
/**
 *	Include Header
 */
#include "DemoClass.h"



#include <functional>



namespace Demo {

	ING_BEGIN_REFLECTED_CLASS(DemoClass, IObject)

		ING_CLASS_PROPERTY(DemoClass::a, CLASS_MEMBER_ACCESS_PUBLIC)

		ING_CLASS_PROPERTY(DemoClass::b, CLASS_MEMBER_ACCESS_PUBLIC)

	ING_END_REFLECTED_CLASS ()

	void DemoClass::Fn() {

		a = 5;

	}

}