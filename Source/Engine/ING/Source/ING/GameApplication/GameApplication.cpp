
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

		mode(mode)
	{

		Debug::Log("Start Creating Game Application");



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

		Debug::Log("Finished Initializing Game Application");

	}
	void	IGameApplication::Release() {

		Debug::Log("Start Releasing Game Application");

		IApplication::Release();

		Debug::Log("Finished Releasing Game Application");

	}



	/**
	 *	Methods
	 */
	void	IGameApplication::Start() {

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