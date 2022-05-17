
/**
 *	Include Header
 */
#include "Component.h"



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
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Application Component Override
 */
#include <ING/Application/Component/Override/Override.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	IApplicationComponent::IApplicationComponent(IApplication* application, const String& name) :
		name(name),
		application(application)
	{



	}

	IApplicationComponent::~IApplicationComponent()
	{



	}



	/**
	 *	Init, Release Methods
	 */
	bool IApplicationComponent::Init()
	{

		for (auto item : overrideVector) {

			if(!item->Init()) return false;

		}

		return true;

	}
	void IApplicationComponent::Release()
	{

		if (application != 0) {

			application->RemoveComponent(this);

		}

		for (unsigned int i = 0; i < overrideVector.size(); ++i) {

			overrideVector[i]->Release();

		}

		overrideVector.clear();

		delete this;
	}



	/**
	 *	Methods
	 */
	void	IApplicationComponent::AddOverride(IApplicationComponentOverride* override) {

		name2OverrideIndex[override->GetName()] = overrideVector.size();

		overrideVector.resize(overrideVector.size() + 1);

		overrideVector[overrideVector.size() - 1] = override;

	}

	void	IApplicationComponent::RemoveOverride(IApplicationComponentOverride* override) {

		unsigned int index = name2OverrideIndex[override->GetName()];

		overrideVector.erase(overrideVector.begin() + index);

		name2OverrideIndex.erase(override->GetName());

		for (auto& item : name2OverrideIndex) {

			if (item.second > index) {

				item.second--;

			}

		}

	}

	void	IApplicationComponent::Start() {

		for (auto item : overrideVector) {

			item->Start();

		}

	}

	void	IApplicationComponent::PreUpdate() {

		for (auto item : overrideVector) {

			item->PreUpdate();

		}

	}

	void	IApplicationComponent::Update() {

		for (auto item : overrideVector) {

			item->Update();

		}

	}

	void	IApplicationComponent::LateUpdate() {

		for (auto item : overrideVector) {

			item->LateUpdate();

		}

	}

	void	IApplicationComponent::PreRender() {

		for (auto item : overrideVector) {

			item->PreRender();

		}

	}

	void	IApplicationComponent::Render() {

		for (auto item : overrideVector) {

			item->Render();

		}

	}

	void	IApplicationComponent::LateRender() {

		for (auto item : overrideVector) {

			item->LateRender();

		}

	}
	
}