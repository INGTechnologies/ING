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

		template<typename T>
		class View
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			View() {



			}

			~View() {



			}



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() {

				delete this;

			}

		};

	}

}