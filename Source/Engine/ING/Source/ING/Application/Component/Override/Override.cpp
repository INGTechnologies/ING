
/**
 *	Include Header
 */
#include "Override.h"



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
 *	Include Application Component
 */
#include <ING/Application/Component/Component.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	IApplicationComponentOverride::IApplicationComponentOverride(IApplicationComponent* component, const String& name) :
		name(name),
		component(component)
	{



	}

	IApplicationComponentOverride::~IApplicationComponentOverride()
	{



	}



	/**
	 *	Init, Release Methods
	 */
	bool IApplicationComponentOverride::Init()
	{



		return true;

	}
	void IApplicationComponentOverride::Release()
	{

		if (component != 0) {

			component->overrideVector[component->GetOverrideIndex(name)] = 0;
			component->name2OverrideIndex.erase(name);

		}

		delete this;
	}



	/**
	 *	Properties
	 */
	IApplication* IApplicationComponentOverride::GetApplication() { 
		
		return GetComponent()->GetApplication(); 
	}



	/**
	 *	Methods
	 */
	void	IApplicationComponentOverride::Start() {



	}

	void	IApplicationComponentOverride::PreUpdate() {



	}

	void	IApplicationComponentOverride::Update() {



	}

	void	IApplicationComponentOverride::LateUpdate() {



	}

	void	IApplicationComponentOverride::PreRender() {



	}

	void	IApplicationComponentOverride::Render() {



	}

	void	IApplicationComponentOverride::LateRender() {



	}
	
}