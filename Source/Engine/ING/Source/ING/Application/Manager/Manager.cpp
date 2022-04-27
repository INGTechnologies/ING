
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationManager::ApplicationManager()
	{

		Debug::Log("Start Creating ApplicationManager");



		Debug::Log("ApplicationManager Created");

	}

	ApplicationManager::~ApplicationManager()
	{



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool ApplicationManager::Init()
	{

		Debug::Log("Start Initializing ApplicationManager");



		Debug::Log("ApplicationManager Initialized");

		return true;
	}

	bool ApplicationManager::Run()
	{

		Debug::Log("Start Running ApplicationManager");

		return true;
	}

	bool ApplicationManager::Release()
	{

		Debug::Log("Start Releasing ApplicationManager");

		for (auto item = name2ApplicationMap.begin(); item != name2ApplicationMap.end();) {

			auto nextItem = item;

			++nextItem;

			item->second->Release();

			item = nextItem;

		}

		delete this;

		Debug::Log("Finished Releasing ApplicationManager");

		return true;
	}



	/**
	 *	Methods
	 */
	void	ApplicationManager::AddApplication(IApplication* app) {

		if (name2ApplicationMap.find(app->GetName()) != name2ApplicationMap.end()) return;

		name2ApplicationMap[app->GetName()] = app;

	}

	void	ApplicationManager::RemoveApplication(IApplication* app) {

		if (name2ApplicationMap.find(app->GetName()) == name2ApplicationMap.end()) return;

		name2ApplicationMap.erase(app->GetName());

	}

	void	ApplicationManager::Start() {

		for (auto item = name2ApplicationMap.begin(); item != name2ApplicationMap.end();) {

			auto nextItem = item;

			++nextItem;

			item->second->Start();

			item = nextItem;

		}

	}

	void	ApplicationManager::PreUpdate() {

		for (auto item = name2ApplicationMap.begin(); item != name2ApplicationMap.end();) {

			auto nextItem = item;

			++nextItem;

			item->second->PreUpdate();

			item = nextItem;

		}

	}

	void	ApplicationManager::Update() {

		for (auto item = name2ApplicationMap.begin(); item != name2ApplicationMap.end();) {

			auto nextItem = item;

			++nextItem;

			item->second->Update();

			item = nextItem;

		}

	}

	void	ApplicationManager::LateUpdate() {

		for (auto item = name2ApplicationMap.begin(); item != name2ApplicationMap.end();) {

			auto nextItem = item;

			++nextItem;

			item->second->LateUpdate();

			item = nextItem;

		}

	}

	void	ApplicationManager::PreRender() {

		for (auto item = name2ApplicationMap.begin(); item != name2ApplicationMap.end();) {

			auto nextItem = item;

			++nextItem;

			item->second->PreRender();

			item = nextItem;

		}

	}

	void	ApplicationManager::Render() {

		for (auto item = name2ApplicationMap.begin(); item != name2ApplicationMap.end();) {

			auto nextItem = item;

			++nextItem;

			item->second->Render();

			item = nextItem;

		}

	}

	void	ApplicationManager::LateRender() {

		for (auto item = name2ApplicationMap.begin(); item != name2ApplicationMap.end();) {

			auto nextItem = item;

			++nextItem;

			item->second->LateRender();

			item = nextItem;

		}

	}

}