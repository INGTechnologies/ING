#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	namespace Scripting {

		class ING_API Manager :
			public Singleton<Manager>,
			public Square
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Manager();
			~Manager();



			/**
			 *	Init, Run, Release Methods
			 */
		public:
			virtual bool Init();
			virtual bool Run();
			virtual bool Release();

		};

	}

}