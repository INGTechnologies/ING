#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	namespace ECS {

		class ING_API SystemManager :
			public Singleton<SystemManager>,
			public Square
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			SystemManager();
			~SystemManager();



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