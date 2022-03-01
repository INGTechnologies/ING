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

		public:
			IPipeline*	GetDefaultPipeline	() { return defaultPipeline; }

			IPipeline*	GetPipeline			() { return pipeline; }

			IPipeline*	GetTargetPipeline	() { return targetPipeline; }

			void		SetPipeline	(IPipeline* pipeline);



			/**
			 *	Methods
			 */
		public:
			void		FrameUpdate();

		};

	}

}