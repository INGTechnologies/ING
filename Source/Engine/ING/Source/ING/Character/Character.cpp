
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
		(ICharacter, IPawn)

		/**
		 *	Constructor
		 */
		ING_CLASS_CONSTRUCTOR
			(ICharacter)
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

	ING_END_REFLECTED_CLASS
		()



	/**
	 *	Constructor
	 */
	void ICharacter::Constructor()
	{

		IPawn::Constructor();

		SetName("NewCharacter");

	}



	/**
	 *	Release Methods
	 */
	void ICharacter::Release()
	{

		IPawn::Release();

	}

}