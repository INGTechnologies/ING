
/**
 *	Include Header
 */
#include "Assembly.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include CSharp Context
 */
#include <ING/Scripting/CSharp/Context/Context.h>



namespace ING {

	namespace Scripting {

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			Assembly::Assembly(Context* context) :
				context(context),

				monoAssembly(0),
				monoImage(0)
			{

				

			}

			Assembly::~Assembly()
			{



			}



			/**
			 *	Release Method
			 */
			void Assembly::Release() {

				if (monoImage != 0) {

					mono_image_close(monoImage);

				}

				if (monoAssembly != 0) {

					mono_assembly_close(monoAssembly);

				}

				delete this;

			}


		}

	}

}