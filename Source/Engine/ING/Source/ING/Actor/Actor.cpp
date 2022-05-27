
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
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_PROPERTY		
			(IActor, name)
			.ACCESS	(CLASS_MEMBER_ACCESS_PRIVATE)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION		
			(IActor, GetName, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_CLASS_FUNCTION		
			(IActor, SetName, RType::Void, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PUBLIC)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

	ING_END_REFLECTED_CLASS
		()



	/**
	 *	Constructor
	 */
	RType::Void IActor::Constructor()
	{

		name = "NewActor";

		return 0;
	}



	/**
	 *	Release Methods
	 */
	void IActor::Release()
	{

		delete this;
	}

}