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

	namespace Rendering {

		class Renderer;

		class IRenderer;

		class IPipeline;

		class IDevice;



		class ING_API System : public IApplicationComponent
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			System(IApplication* application);
			~System();



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
			IPipeline*	defaultPipeline;

			IPipeline*	pipeline;

			IPipeline*	targetPipeline;

			IDevice*	defaultDevice;

			IDevice*	device;

			IDevice*	targetDevice;

		public:
			IPipeline*	GetDefaultPipeline	() { return defaultPipeline; }

			IPipeline*	GetPipeline			() { return pipeline; }

			IPipeline*	GetTargetPipeline	() { return targetPipeline; }

			void		SetPipeline			(IPipeline* pipeline);

			IDevice*	GetDefaultDevice	() { return defaultDevice; }

			IDevice*	GetDevice			() { return device; }

			IDevice*	GetTargetDevice		() { return targetDevice; }

			void		SetDevice			(IDevice* device);



			/**
			 *	Methods
			 */
		public:
			virtual void	Start() override;

			virtual void	PreUpdate() override;
			virtual void	Update() override;
			virtual void	LateUpdate() override;

			virtual void	PreRender() override;
			virtual void	Render() override;
			virtual void	LateRender() override;

		};

	}

}