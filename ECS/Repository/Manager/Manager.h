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

		class ING_API RepositoryManager :
			public Singleton<RepositoryManager>,
			public Square
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			RepositoryManager();
			~RepositoryManager();



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