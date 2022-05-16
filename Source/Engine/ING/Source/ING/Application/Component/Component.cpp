
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

			application->componentVector[application->GetComponentIndex(name)] = 0;
			application->name2ComponentIndexMap.erase(name);

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
	void	IApplicationComponent::AddOverride(IApplicationComponentOverride* component) {

		AddOverride(component, overrideVector.size());

	}

	void	IApplicationComponent::AddOverride(IApplicationComponentOverride* component, unsigned int index) {

		if (overrideVector.size() == index) {

			overrideVector.push_back(component);

		}
		else {

			overrideVector.insert(overrideVector.begin() + index, component);

			unsigned int passCount = overrideVector.size();

			for (unsigned int i = index + 1; i < passCount; ++i) {

				name2OverrideIndex[overrideVector[i]->GetName()]++;

			}

		}

		name2OverrideIndex[component->GetName()] = index;

		component->SetComponent(this);

	}

	void	IApplicationComponent::RemoveOverride(unsigned int index) {

		String passName = GetOverride(index)->GetName();

		GetOverride(index)->SetComponent(0);

		overrideVector.erase(overrideVector.begin() + index);

		unsigned int passCount = overrideVector.size();

		for (unsigned int i = index + 1; i < passCount; ++i) {

			name2OverrideIndex[overrideVector[i]->GetName()]--;

		}

		name2OverrideIndex.erase(passName);

	}

	void	IApplicationComponent::RemoveOverride(const String& name) {

		RemoveOverride(name2OverrideIndex[name]);

	}

	void	IApplicationComponent::RemoveOverride(IApplicationComponentOverride* component) {

		RemoveOverride(component->GetName());

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