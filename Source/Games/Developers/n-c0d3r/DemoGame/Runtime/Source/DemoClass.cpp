
/**
 *	Include Header
 */
#include "DemoClass.h"



#include <functional>



namespace Demo {

	ING_BEGIN_REFLECTED_CLASS(DemoClass, IObject)

		ING_CLASS_CONSTRUCTOR(DemoClass, int)
			.ACCESS(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG(CLASS_MEMBER_TAG_NO_EDIT);

		ING_CLASS_PROPERTY(DemoClass, a)
			.ACCESS(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG(CLASS_MEMBER_TAG_EDIT_EVERYWHERE);

		ING_CLASS_PROPERTY(DemoClass, b)
			.ACCESS(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG(CLASS_MEMBER_TAG_EDIT_EVERYWHERE);

		ING_CLASS_FUNCTION(DemoClass, Fn, int)
			.ACCESS(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG(CLASS_MEMBER_TAG_EDIT_EVERYWHERE);

	ING_END_REFLECTED_CLASS ()



	void DemoClass::Constructor(int a) {

		this->a = a;

	}

	int DemoClass::Fn() {

		return 3;
	}

}