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



namespace ING {

	class IApplication;

	namespace Rendering {

		class Renderer;

		class IRenderer;

		class IPipeline;

		class IDevice;



		class ING_API System
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			System(IApplication* application);
			~System();



			/**
			 *	Init, Run, Release Methods
			 */
		public:
			virtual bool Init();
			virtual void Start();
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			IApplication* application;

			IPipeline*	defaultPipeline;

			IPipeline*	pipeline;

			IPipeline*	targetPipeline;

			IDevice*	defaultDevice;

			IDevice*	device;

			IDevice*	targetDevice;

		public:
			IApplication* GetApplication	() { return application; }

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
			void		PreRender();
			void		Render();
			void		LateRender();

		};

	}

}