
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
			(ICharacter, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

	ING_END_REFLECTED_CLASS
		()



	/**
	 *	Constructor
	 */
	void ICharacter::Constructor(const String& name)
	{

		IPawn::Constructor(name);

	}



	/**
	 *	Release Methods
	 */
	void ICharacter::Release()
	{

		IPawn::Release();

	}

}