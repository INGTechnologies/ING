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
 *	Include ApplicationComponent
 */
#include <ING/Application/Component/Component.h>



namespace ING {

	class IApplication;

	namespace Rendering {

		class IPipeline;

	}



	namespace Editor {

		class PLUGIN_API(ING_EDITOR) ApplicationRenderingSystem : public IApplicationComponent
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ApplicationRenderingSystem	(IApplication* application);
			~ApplicationRenderingSystem	();



			/**
			 *	Init, Release Methods
			 */
		public:
			virtual bool Init() override;
			virtual void Release() override;



			/**
			 *	Properties
			 */
		private:
			Rendering::IPipeline*	mainPipeline;

		public:
			Rendering::IPipeline*	GetMainPipeline() { return mainPipeline; }

			void					SetMainPipeline(Rendering::IPipeline*) { this->mainPipeline = mainPipeline; }



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