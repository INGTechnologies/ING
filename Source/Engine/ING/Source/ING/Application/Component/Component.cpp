
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



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	IApplicationComponent::IApplicationComponent(IApplication* application, const std::string& name) :
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



		return true;

	}
	void IApplicationComponent::Release()
	{

		application->RemoveComponent(this);

		delete this;
	}



	/**
	 *	Methods
	 */
	void	IApplicationComponent::Start() {



	}

	void	IApplicationComponent::PreUpdate() {



	}

	void	IApplicationComponent::Update() {



	}

	void	IApplicationComponent::LateUpdate() {



	}

	void	IApplicationComponent::PreRender() {



	}

	void	IApplicationComponent::Render() {



	}

	void	IApplicationComponent::LateRender() {



	}
	
}