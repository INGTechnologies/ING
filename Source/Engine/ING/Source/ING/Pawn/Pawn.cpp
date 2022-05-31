
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
		(C_Pawn, C_Actor)

		/**
		 *	Constructor
		 */
		ING_CLASS_CONSTRUCTOR
			(C_Pawn, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

	ING_END_REFLECTED_CLASS
		()



	/**
	 *	Constructor
	 */
	void C_Pawn::Constructor(const String& name)
	{

		C_Actor::Constructor(name);

	}



	/**
	 *	Release Methods
	 */
	void C_Pawn::Release()
	{

		C_Actor::Release();

	}

}