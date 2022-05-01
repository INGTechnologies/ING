
/**
 *	Include Header
 */
#include "UISystem.h"



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include UI Node
 */
#include <ING/UI/Node/Node.h>



/**
 *	Include UI Element
 */
#include <ING/UI/Element/Element.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationUISystem::ApplicationUISystem(IApplication* application) :
		IApplicationComponent(application, "UISystem"),

		rootElement(0)
	{



	}

	ApplicationUISystem::~ApplicationUISystem() {



	}



	/**
	 *	Init, Release Methods
	 */
	bool ApplicationUISystem::Init() {

		rootElement = new UI::Element();

		return IApplicationComponent::Init();
	}

	void ApplicationUISystem::Release() {

		if (rootElement != 0) {

			rootElement->Release();

		}

		IApplicationComponent::Release();

	}



	/**
	 *	Properties
	 */
	void	ApplicationUISystem::ChangeRootElement(UI::Element* rootElement) {

		if (this->rootElement != 0) {

			this->rootElement->Release();

		}

		this->rootElement = rootElement;

	}



	/**
	 *	Methods
	 */
	void	ApplicationUISystem::Start() {

		IApplicationComponent::Start();

	}

	void	ApplicationUISystem::PreUpdate() {

		IApplicationComponent::PreUpdate();

	}

	void	ApplicationUISystem::Update() {

		IApplicationComponent::Update();

	}

	void	ApplicationUISystem::LateUpdate() {

		IApplicationComponent::LateUpdate();

	}

	void	ApplicationUISystem::PreRender() {

		IApplicationComponent::PreRender();

	}

	void	ApplicationUISystem::Render() {

		IApplicationComponent::Render();

	}

	void	ApplicationUISystem::LateRender() {

		IApplicationComponent::LateRender();

	}

}
