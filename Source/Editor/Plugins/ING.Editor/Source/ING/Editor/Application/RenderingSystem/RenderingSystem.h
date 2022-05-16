#pragma once

/**
 *	Include Editor Entry Point
 */
#include <ING\Editor\EntryPoint\EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include ApplicationComponentOverride
 */
#include <ING/Application/Component/Override/Override.h>



/**
 *	Include ING::ApplicationRenderingSystem
 */
#include <ING/Application/RenderingSystem/RenderingSystem.h>



namespace ING {

	class IApplication;

	class IApplicationComponent;

	namespace Rendering {

		class IPipeline;

	}



	namespace Editor {

		class PLUGIN_API(ING_EDITOR) ApplicationRenderingSystem : 
			public ApplicationComponentOverride<ING::ApplicationRenderingSystem>
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ApplicationRenderingSystem	(IApplicationComponent* component);
			~ApplicationRenderingSystem	();



			/**
			 *	Init, Release Methods
			 */
		public:
			virtual bool Init() override;
			virtual void Release() override;



			/**
			 *	Methods
			 */
		public:
			virtual void	Start			() override;

			virtual void	PreUpdate		() override;
			virtual void	Update			() override;
			virtual void	LateUpdate		() override;

			virtual void	PreRender		() override;
			virtual void	Render			() override;
			virtual void	LateRender		() override;

		};

	}

}