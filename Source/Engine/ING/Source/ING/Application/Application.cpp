
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
#include <ING/Application/WindowSystem/WindowSystem.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Rendering System
 */
#include <ING/Application/RenderingSystem/RenderingSystem.h>



/**
 *	Include UI System
 */
#include <ING/Application/UISystem/UISystem.h>



/**
 *	Include Reflection System
 */
#include <ING/Application/ReflectionSystem/ReflectionSystem.h>



/**
 *	Include Actor System
 */
#include <ING/Application/ActorSystem/ActorSystem.h>



/**
 *	Include ApplicationComponent
 */
#include <ING/Application/Component/Component.h>



/**
 *	Include Application Module
 */
#include <ING/Application/Module/Module.h>



/**
 *	Include Transform
 */
#include <ING/Transform/Transform.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	IApplication::IApplication(const WString& configPath) :
		name("INGApplication"),
		configPath(configPath),
		configuration(0),
		windowSystem(0),
		renderingSystem(0),
		reflectionSystem(0)
	{

		IApplicationModule* module = new IApplicationModule("ING", this);

		module->RegisterType<S_TransformM>(0);
		module->RegisterType<S_TransformS>(0);



		reflectionSystem = new ApplicationReflectionSystem(this);
		AddComponent(reflectionSystem);

		windowSystem = new ApplicationWindowSystem(this);
		AddComponent(windowSystem);

		renderingSystem = new ApplicationRenderingSystem(this);
		AddComponent(renderingSystem);

		uiSystem = new ApplicationUISystem(this);
		AddComponent(uiSystem);

		actorSystem = new ApplicationActorSystem(this);
		AddComponent(actorSystem);

	}

	IApplication::~IApplication()
	{



	}



	/**
	 *	Init, Release Methods
	 */
	bool IApplication::Init()
	{

		Debug::Log(ToWString("Start Initializing Application ") + configPath);

		if (!std::filesystem::exists(Path::GetAbsolutePath(configPath))) {

			Debug::Error(configPath + ToWString(" Not Found, Cant Create Application"));

			Release();

			return false; 
		}

		configuration = new Configuration();

		configuration->LoadFromFile(configPath);

		if (configuration->Exist("ING.Application.name")) {

			name = configuration->Get<String>("ING.Application.name");

		}

		SortModuleVector();

		for (unsigned int i = 0; i < componentVector.size(); ++i) {

			if (!componentVector[i]->Init()) {

				Debug::Error(ToString("Cant Init ") + ToString('"') + componentVector[i]->GetName() + ToString('"') + ToString(" Application Component"));

				Release();

				return false;

			}

			if (componentVector[i] == reflectionSystem) {

				for (auto module : sortedModuleVector) {

					module->Load();

				}

			}

		}

		ApplicationManager::GetInstance()->AddApplication(this);

		Debug::Log(ToWString("Finished Initializing Application ") + configPath);

		return true;

	}
	void IApplication::Release()
	{

		for (unsigned int i = sortedModuleVector.size() - 1; ; --i) {

			sortedModuleVector[i]->Unload();

			if (i == 0) {

				break;

			}

		}

		for (unsigned int j = componentVector.size(); j >= 1; --j) {

			unsigned int i = j - 1;

			componentVector[i]->Release();

		}

		if (configuration != 0)
			delete configuration;

		name2ComponentIndexMap.clear();
		componentVector.clear();

		for (unsigned int i = sortedModuleVector.size() - 1; ; --i) {

			sortedModuleVector[i]->Release();

			if (i == 0) {

				break;

			}

		}

		ApplicationManager::GetInstance()->RemoveApplication(this);

		delete this;
	}



	/**
	 *	Methods
	 */
	void	IApplication::AddComponent(IApplicationComponent* component) {

		name2ComponentIndexMap[component->GetName()] = componentVector.size();

		componentVector.resize(componentVector.size() + 1);

		componentVector[componentVector.size() - 1] = component;

	}

	void	IApplication::RemoveComponent(IApplicationComponent* component) {

		unsigned int index = name2ComponentIndexMap[component->GetName()];

		componentVector.erase(componentVector.begin() + index);

		name2ComponentIndexMap.erase(component->GetName());

		for (auto& item : name2ComponentIndexMap) {

			if (item.second > index) {

				item.second--;

			}

		}

	}

	unsigned int IApplication::GetModuleLevel(IApplicationModule* module) {

		unsigned int level = 1;

		for (auto item : module->GetDependenciesMap()) {

			unsigned int dependencyLevel = GetModuleLevel(name2ModuleMap[item.first]);

			if (level < dependencyLevel + 1) {

				level = dependencyLevel + 1;

			}

		}

		return level;
	}

	void	IApplication::SortModuleVector() {

		/* Setup Name To Module Level Map */
		std::unordered_map<String, unsigned int> name2ModuleLevelMap;

		for (auto item : name2ModuleMap) {

			name2ModuleLevelMap[item.second->GetName()] = GetModuleLevel(item.second);

		}



		/* Sort */
		std::vector<IApplicationModule*> moduleVector(name2ModuleMap.size());

		{

			unsigned int i = 0;

			for (auto item : name2ModuleMap) {

				moduleVector[i] = item.second;

				++i;

			}

		}

		for (unsigned int i = 0; i < moduleVector.size(); ++i) {

			for (unsigned int j = 0; j < i; ++j) {

				if (
					name2ModuleLevelMap[moduleVector[i]->GetName()] < name2ModuleLevelMap[moduleVector[j]->GetName()]
				) {

					IApplicationModule* mw = moduleVector[i];
					moduleVector[i] = moduleVector[j];
					moduleVector[j] = mw;

				}

			}

		}

		sortedModuleVector = moduleVector;

	}

	void	IApplication::Start() {

		for (unsigned int i = 0; i < componentVector.size(); ++i) {

			componentVector[i]->Start();

		}

	}

	void	IApplication::PreUpdate() {

		for (unsigned int i = 0; i < componentVector.size(); ++i) {

			componentVector[i]->PreUpdate();

		}

	}

	void	IApplication::Update() {

		for (unsigned int i = 0; i < componentVector.size(); ++i) {

			componentVector[i]->Update();

		}

	}

	void	IApplication::LateUpdate() {

		for (unsigned int i = 0; i < componentVector.size(); ++i) {

			componentVector[i]->LateUpdate();

		}

	}

	void	IApplication::PreRender() {

		for (unsigned int i = 0; i < componentVector.size(); ++i) {

			componentVector[i]->PreRender();

		}

	}

	void	IApplication::Render() {

		for (unsigned int i = 0; i < componentVector.size(); ++i) {

			componentVector[i]->Render();

		}

	}

	void	IApplication::LateRender() {

		for (unsigned int i = 0; i < componentVector.size(); ++i) {

			componentVector[i]->LateRender();

		}

	}

	void IApplication::AddModule(IApplicationModule* module) {

		name2ModuleMap[module->GetName()] = module;

		module->application = this;

	}

	void IApplication::RemoveModule(IApplicationModule* module) {

		name2ModuleMap.erase(module->GetName());

		module->application = 0;

	}
	
}