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



		class ING_API Engine :
			public Board<Engine>,
			public Square
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Engine();
			~Engine();



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
			Renderer*	defaultRenderer;

			Renderer*	renderer;

			Renderer*	targetRenderer;

		public:
			Renderer*	GetDefaultRenderer	() { return defaultRenderer; }

			Renderer*	GetRenderer			() { return renderer; }

			Renderer*	GetTargetRenderer   () { return targetRenderer; }

			void		SetRenderer			(Renderer* renderer);



			/**
			 *	Methods
			 */
		public:
			void		FrameUpdate();

		};

	}

}