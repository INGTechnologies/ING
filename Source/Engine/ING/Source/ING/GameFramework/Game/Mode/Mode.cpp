
/**
 *	Include Header
 */
#include "Mode.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Game
 */
#include <ING/GameFramework/Game/Game.h>



namespace ING {

	ING_BEGIN_REFLECTED_CLASS
		(C_GameMode, Reflection::C_Object)

		/**
		 *	Constructor
		 */
		ING_CLASS_CONSTRUCTOR
			(C_GameMode, C_Game*)
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

	ING_END_REFLECTED_CLASS
		()



	/**
	 *	Constructor
	 */
	void C_GameMode::Constructor(C_Game* game)
	{

		this->game = game;

	}



	/**
	 *	Release Methods
	 */
	void C_GameMode::Release()
	{

		Reflection::C_Object::Release();

	}



	/**
	 *	Methods
	 */
	void C_GameMode::Play() {



	}

	void C_GameMode::Stop() {



	}

}