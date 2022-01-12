#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Singleton
 */
#include <ING/Utils/Singleton/Singleton.h>



namespace ING {

	namespace Utils {

		class ING_API Square {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Square() {

			}

			~Square() {

			}



			/**
			 *	Init, Run, Release Methods
			 */
		public:
			virtual bool Init() {

				return true;
			}

			virtual bool Run() {

				return true;
			}

			virtual bool Release() {

				delete this;

				return true;
			}

		};



	}

}

