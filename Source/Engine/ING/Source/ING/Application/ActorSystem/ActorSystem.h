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

	class ING_API ApplicationActorSystem : public IApplicationComponent
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ApplicationActorSystem	(IApplication* application);
		~ApplicationActorSystem	();



		/**
		 *	Init, Release Methods
		 */
	public:
		virtual bool Init();
		virtual void Release();



		/**
		 *	Methods
		 */
	public:
		virtual void Start		() override;

		virtual void PreUpdate	() override;
		virtual void Update		() override;
		virtual void LateUpdate	() override;

		virtual void PreRender	() override;
		virtual void Render		() override;
		virtual void LateRender	() override;

	};

}