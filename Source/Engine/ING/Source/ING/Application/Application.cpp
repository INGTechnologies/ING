
/**
 *	Include Header
 */
#include "Application.h"



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Application
 */
#include <ING/Application/Manager/Manager.h>



/**
 *	Include ApplicationWindowManager
 */
#include <ING/Application/Window/Manager/Manager.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Rendering System
 */
#include <ING/Rendering/System/System.h>





namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	IApplication::IApplication(const std::string& configPath) :
		name("INGApplication"),
		configPath(configPath),
		configuration(0),
		windowManager(0),
		renderingSystem(0)
	{



	}

	IApplication::~IApplication()
	{



	}



	/**
	 *	Init, Release Methods
	 */
	bool IApplication::Init()
	{

		Debug::Log(String("Start Creating An Application ") + configPath);

		if (!std::filesystem::exists(Path::GetAbsolutePath(configPath))) {

			Debug::Error(configPath + String(" Not Found, Cant Create Application"));

			Release();

			return false; 
		}

		configuration = new Configuration();

		configuration->LoadFromFile(configPath);

		if (!configuration->Exist("ING.Application.name")) {

			name = configuration->Get<std::string>("ING.Application.name");

		}

		windowManager = new ApplicationWindowManager(this);

		renderingSystem = new Rendering::System(this);

		if (!renderingSystem->Init()) {

			Debug::Error(String("Cant Create ") + String('"') + name + String('"') + String(" Application Rendering System"));

			Release();

			return false;

		}

		ApplicationManager::GetInstance()->AddApplication(this);

		Debug::Log(String("Finished Creating An Application ") + configPath);

		return true;

	}
	void IApplication::Release()
	{

		if(configuration != 0)
			delete configuration;

		if (windowManager != 0)
			delete windowManager;

		if (renderingSystem != 0)
			delete renderingSystem;

		ApplicationManager::GetInstance()->RemoveApplication(this);

		delete this;
	}



	/**
	 *	Methods
	 */
	void	IApplication::Start() {

		renderingSystem->Start();

	}

	void	IApplication::PreUpdate() {



	}

	void	IApplication::Update() {



	}

	void	IApplication::LateUpdate() {



	}

	void	IApplication::PreRender() {

		renderingSystem->PreRender();

	}

	void	IApplication::Render() {

		renderingSystem->Render();

	}

	void	IApplication::LateRender() {

		renderingSystem->LateRender();

	}
	
}