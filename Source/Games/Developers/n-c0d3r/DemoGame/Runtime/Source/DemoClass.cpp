
/**
 *	Include Header
 */
#include "DemoClass.h"



#include <functional>



namespace Demo {

	ING_BEGIN_REFLECTED_CLASS(DemoClass, IObject)

		ING_CLASS_CONSTRUCTOR(DemoClass::Constructor, DemoClass, int)
			.ACCESS(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG(CLASS_MEMBER_TAG_EDIT_EVERYWHERE);

		ING_CLASS_FUNCTION(DemoClass::Fn, DemoClass, int)
			.ACCESS(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG(CLASS_MEMBER_TAG_EDIT_EVERYWHERE);

	ING_END_REFLECTED_CLASS ()



	void DemoClass::Constructor(int a) {

		Debug::Log(a);

	}

	int DemoClass::Fn() {

		return 3;
	}

}