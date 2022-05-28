
/**
 *	Include Header
 */
#include "DemoActor.h"



#include <functional>



ING_BEGIN_REFLECTED_CLASS	
	(DemoActor, ING::IActor)

	ING_CLASS_CONSTRUCTOR	
		(DemoActor)
		.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
		.TAG	(CLASS_MEMBER_TAG_NO_EDIT);

ING_END_REFLECTED_CLASS		
	()

void DemoActor::Constructor() {

	IActor::Constructor();

}

void DemoActor::Release() {

	IActor::Release();

}