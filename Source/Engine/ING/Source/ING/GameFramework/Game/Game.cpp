
/**
 *	Include Header
 */
#include "Game.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Game Mode
 */
#include <ING/GameFramework/Game/Mode/Mode.h>



namespace ING {

	ING_BEGIN_REFLECTED_CLASS
		(C_Game, Reflection::C_Object)

		/**
		 *	Constructor
		 */
		ING_CLASS_CONSTRUCTOR
			(C_Game, const String&)
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

	ING_END_REFLECTED_CLASS
		()



	/**
	 *	Constructor
	 */
	void C_Game::Constructor(const String& name)
	{

		this->name = name;

		modeClass = 0;

	}



	/**
	 *	Release Methods
	 */
	void C_Game::Release()
	{

		Reflection::C_Object::Release();

	}



	/**
	 *	Methods
	 */
	void C_Game::Play() {

		mode = (C_GameMode*)modeClass->RCreateInstance(this);

		mode->Play();

	}

	void C_Game::Stop() {

		mode->Stop();

		mode->Release();

	}

}