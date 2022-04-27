
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





namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	IApplication::IApplication(const std::string& configPath) :
		name("INGApplication"),
		configPath(configPath),
		configuration(0),
		windowManager(0)
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

		ApplicationManager::GetInstance()->RemoveApplication(this);

		delete this;
	}



	/**
	 *	Methods
	 */
	void	IApplication::Start() {



	}

	void	IApplication::PreUpdate() {



	}

	void	IApplication::Update() {



	}

	void	IApplication::LateUpdate() {



	}

	void	IApplication::PreRender() {



	}

	void	IApplication::Render() {



	}

	void	IApplication::LateRender() {



	}
	
}