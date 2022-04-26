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

	namespace Rendering {

		class Renderer;

		class IRenderer;

		class IPipeline;

		class IDevice;



		class ING_API System :
			public Singleton<System>,
			public Square
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			System();
			~System();



			/**
			 *	Init, Run, Release Methods
			 */
		public:
			virtual bool Init()		override;
			virtual bool Run()		override;
			virtual bool Release()	override;



			/**
			 *	Properties
			 */
		private:
			IPipeline*	defaultPipeline;

			IPipeline*	pipeline;

			IPipeline*	targetPipeline;

			bool		isRendering;

			IDevice*	defaultDevice;

			IDevice*	device;

			IDevice*	targetDevice;

		public:
			IPipeline*	GetDefaultPipeline	() { return defaultPipeline; }

			IPipeline*	GetPipeline			() { return pipeline; }

			IPipeline*	GetTargetPipeline	() { return targetPipeline; }

			void		SetPipeline			(IPipeline* pipeline);

			bool		IsRendering			() { return isRendering; }

			IDevice*	GetDefaultDevice	() { return defaultDevice; }

			IDevice*	GetDevice			() { return device; }

			IDevice*	GetTargetDevice		() { return targetDevice; }

			void		SetDevice			(IDevice* device);



			/**
			 *	Methods
			 */
		public:
			void		PreUpdate();
			void		FrameUpdate();

		};

	}

}



/**
 *	Define Macros
 */
#define RENDERING_ASSERTION(A)  {\
\
	A;\
	if (!Rendering::System::GetInstance()->IsRendering()){\
	\
		return false;\
	\
	}\
\
}