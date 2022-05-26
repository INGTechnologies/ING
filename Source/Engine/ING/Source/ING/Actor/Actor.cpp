
/**
 *	Include Header
 */
#include "Actor.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	ING_BEGIN_REFLECTED_CLASS
		(IActor, Reflection::IObject)

		ING_CLASS_CONSTRUCTOR
			(IActor)
			.ACCESS	(Reflection::CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(Reflection::CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

	ING_END_REFLECTED_CLASS
		()



	/**
	 *	Constructor
	 */
	void IActor::Constructor()
	{



	}



	/**
	 *	Release Methods
	 */
	void IActor::Release()
	{

		delete this;
	}

}