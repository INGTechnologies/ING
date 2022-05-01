#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include ApplicationComponent
 */
#include <ING/Application/Component/Component.h>



namespace ING {

	class IApplication;

	namespace UI {

		class Node;

		class IElement;

	}

	class ING_API ApplicationUISystem : public IApplicationComponent
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ApplicationUISystem		(IApplication* application);
		~ApplicationUISystem	();



		/**
		 *	Init, Release Methods
		 */
	public:
		virtual bool Init();
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		UI::IElement*	rootElement;

	public:

		UI::IElement*	GetRootElement		() { return rootElement; }

		void			ChangeRootElement	(UI::IElement* rootElement);



		/**
		 *	Methods
		 */
	public:
		virtual void	Start		() override;

		virtual void	PreUpdate	() override;
		virtual void	Update		() override;
		virtual void	LateUpdate	() override;

		virtual void	PreRender	() override;
		virtual void	Render		() override;
		virtual void	LateRender	() override;

	};

}