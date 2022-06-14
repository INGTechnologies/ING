#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include GameMode
 */
#include <ING/GameFramework/Game/Mode/Mode.h>



/**
 *	Include ObjectId
 */
#include <ING/Object/Id.h>



namespace ING {

	class C_Pawn;



	class ING_API C_BasicGameMode : public C_GameMode
	{

		ING_REFLECT_CLASS(C_BasicGameMode, C_GameMode)



		/**
		 *	Constructor
		 */
	protected:
		void			Constructor(C_Game* game);



		/**
		 *	Properties
		 */
	private:
		IClass*			playerPawnClass;

		C_Pawn*			playerPawn;

		ObjectId		playerPawnId;		

	public:
		IClass*			GetPlayerPawnClass () { return playerPawnClass; }
		void			SetPlayerPawnClass (IClass* playerPawnClass) { this->playerPawnClass = playerPawnClass; }

		C_Pawn*			GetPlayerPawn () { return playerPawn; }

		ObjectId		GetPlayerPawnId () { return playerPawnId; }



		/**
		 *	Release Methods
		 */
	public:
		virtual void	Release() override;



		/**
		 *	Methods
		 */
	public:
		virtual void Play() override;
		virtual void Stop() override;

	};

}