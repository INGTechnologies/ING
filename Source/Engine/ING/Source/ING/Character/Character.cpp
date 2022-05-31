
/**
 *	Include Header
 */
#include "Character.h"



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
		(C_Character, C_Pawn)

		/**
		 *	Constructor
		 */
		ING_CLASS_CONSTRUCTOR
			(C_Character, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

	ING_END_REFLECTED_CLASS
		()



	/**
	 *	Constructor
	 */
	void C_Character::Constructor(const String& name)
	{

		C_Pawn::Constructor(name);

	}



	/**
	 *	Release Methods
	 */
	void C_Character::Release()
	{

		C_Pawn::Release();

	}

}