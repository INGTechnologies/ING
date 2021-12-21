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

		class ING_API Engine :
			public Singleton<Engine>,
			public Square,
			public Board<Engine>
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

		};

	}

}