
/**
 *	Include Header
 */
#include "Pawn.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Actor Component
 */
#include <ING/Actor/Component/Component.h>



namespace ING {

	ING_BEGIN_REFLECTED_CLASS
		(IPawn, IActor)

		/**
		 *	Constructor
		 */
		ING_CLASS_CONSTRUCTOR
			(IPawn)
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

	ING_END_REFLECTED_CLASS
		()



	/**
	 *	Constructor
	 */
	void IPawn::Constructor()
	{

		IActor::Constructor();

		SetName("NewPawn");

	}



	/**
	 *	Release Methods
	 */
	void IPawn::Release()
	{

		IActor::Release();

	}

}