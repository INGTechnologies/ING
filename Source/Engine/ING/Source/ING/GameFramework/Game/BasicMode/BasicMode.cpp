
/**
 *	Include Header
 */
#include "BasicMode.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Game
 */
#include <ING/GameFramework/Game/Game.h>



/**
 *	Include Pawn
 */
#include <ING/Pawn/Pawn.h>



/**
 *	Include Object Manager
 */
#include <ING/Object/Manager/Manager.h>



namespace ING {

	ING_BEGIN_REFLECTED_CLASS
		(C_BasicGameMode, C_GameMode)

		/**
		 *	Constructor
		 */
		ING_CLASS_CONSTRUCTOR
			(C_BasicGameMode, C_Game*)
			.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
			.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

	ING_END_REFLECTED_CLASS
		()



	/**
	 *	Constructor
	 */
	void C_BasicGameMode::Constructor(C_Game* game)
	{

		C_GameMode::Constructor(game);



		playerPawnClass = 0;

		playerPawn = 0;

		playerPawnId = 0;

	}



	/**
	 *	Release Methods
	 */
	void C_BasicGameMode::Release()
	{

		C_GameMode::Release();

	}



	/**
	 *	Methods
	 */
	void C_BasicGameMode::Play() {

		C_GameMode::Play();



		playerPawn = (C_Pawn*)playerPawnClass->RCreateInstance(ToString("Player"));

		playerPawnId = playerPawn->GetId();



	}

	void C_BasicGameMode::Stop() {



		if (ObjectManager::GetInstance()->IsHasObject(playerPawnId)) {

			playerPawn = (C_Pawn*)playerPawnClass->RCreateInstance(ToString("Player"));

		}



		C_GameMode::Stop();

	}

}