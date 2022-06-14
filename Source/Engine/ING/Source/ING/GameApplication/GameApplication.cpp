
/**
 *	Include Header
 */
#include "GameApplication.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include ApplicationWindowSystem
 */
#include <ING/Application/WindowSystem/WindowSystem.h>



/**
 *	Include ApplicationManager
 */
#include <ING/Application/Manager/Manager.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Application Module
 */
#include <ING/Application/Module/Module.h>



/**
 *	Include Game
 */
#include <ING/GameFramework/Game/Game.h>



/**
 *	Include Game Mode
 */
#include <ING/GameFramework/Game/Mode/Mode.h>



/**
 *	Include Basic Game Mode
 */
#include <ING/GameFramework/Game/BasicMode/BasicMode.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	IGameApplication::IGameApplication() :
		IApplication(L""),
		Singleton()
	{}

	IGameApplication::IGameApplication(const WString& configPath, const String& mode) :
		IApplication(configPath),

		mode(mode),
		gameClass(0),
		game(0)
	{

		Debug::Log("Start Creating Game Application");



		IApplicationModule* module = new IApplicationModule("ING.GameFramework", this);

		module->RegisterType<C_Game>(0);
		module->RegisterType<C_GameMode>(0);
		module->RegisterType<C_BasicGameMode>(0);

		module->AddDependency("ING.Actor");



		GetModule("ING")->AddDependency("ING.GameFramework");



		Debug::Log("Game Application Created");

	}

	IGameApplication::~IGameApplication() {



	}



	/**
	 *	Init, Release Methods
	 */
	bool	IGameApplication::Init() {

		Debug::Log("Start Initializing Game Application");

		if(!IApplication::Init())return false;

		gameClass = C_Game::GetType(0);

		Debug::Log("Finished Initializing Game Application");

	}
	void	IGameApplication::Release() {

		Debug::Log("Start Releasing Game Application");

		if (game != 0) {

			game->Release();

		}

		IApplication::Release();

		Debug::Log("Finished Releasing Game Application");

	}



	/**
	 *	Methods
	 */
	void	IGameApplication::Start() {

		game = (C_Game*)gameClass->RCreateInstance(GetName());

		IApplication::Start();

	}

	void	IGameApplication::PreUpdate() {

		IApplication::PreUpdate();

	}

	void	IGameApplication::Update() {

		IApplication::Update();

	}

	void	IGameApplication::LateUpdate() {

		IApplication::LateUpdate();

	}

	void	IGameApplication::PreRender() {

		IApplication::PreRender();

	}

	void	IGameApplication::Render() {

		IApplication::Render();

	}

	void	IGameApplication::LateRender() {

		IApplication::LateRender();

	}

}