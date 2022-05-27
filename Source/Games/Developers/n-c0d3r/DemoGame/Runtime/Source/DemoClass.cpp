
/**
 *	Include Header
 */
#include "DemoClass.h"



#include <functional>



namespace Demo {

	ING_BEGIN_REFLECTED_CLASS	
		(DemoClassA, IObject)

		ING_CLASS_CONSTRUCTOR	
			(DemoClassA, int)
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_NO_EDIT);

		ING_CLASS_PROPERTY		
			(DemoClassA, b)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_EDIT_EVERYWHERE);

		ING_CLASS_FUNCTION		
			(DemoClassA, Test, Reflection::RType::Void)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_EDIT_EVERYWHERE);

	ING_END_REFLECTED_CLASS	
		()

	Reflection::RType::Void DemoClassA::Constructor(int b) {

		this->b = b;

		return 0;

	}

	Reflection::RType::Void DemoClassA::Test() {

		Debug::Log("TestA");

		return 0;

	}



	ING_BEGIN_REFLECTED_CLASS	
		(DemoClass, DemoClassA)

		ING_CLASS_CONSTRUCTOR	
			(DemoClass, int)
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_NO_EDIT);

		ING_CLASS_PROPERTY		
			(DemoClass, a)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_EDIT_EVERYWHERE);

		ING_CLASS_FUNCTION		
			(DemoClass, Test, RType::Void)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_EDIT_EVERYWHERE);

		ING_CLASS_FUNCTION		
			(DemoClass, Test2, DemoClass*)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_EDIT_EVERYWHERE);

	ING_END_REFLECTED_CLASS		
		()

	Reflection::RType::Void DemoClass::Constructor(int a) {

		DemoClassA::Constructor(a + 5);

		this->a = a;

		return 0;

	}

	Reflection::RType::Void DemoClass::Test () {

		Debug::Log("Test");

		return 0;

	}

	DemoClass* DemoClass::Test2() {

		Debug::Log("Test2");

		return 0;
	}

}