
/**
 *	Include Header
 */
#include "Creator.h"



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



/**
 *	Include CSharp Assembly
 */
#include <ING/Scripting/CSharp/Assembly/Assembly.h>



/**
 *	Include CSharp Assembly Component
 */
#include <ING/Scripting/CSharp/Assembly/Component/Component.h>



namespace ING {

	namespace Scripting {

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			IAssemblyComponentCreator::IAssemblyComponentCreator(const std::string& name) :
				name(name)
			{



			}

			IAssemblyComponentCreator::~IAssemblyComponentCreator()
			{



			}



			/**
			 *	Release Method
			 */
			void IAssemblyComponentCreator::Release() {

				delete this;

			}



			/**
			 *	Methods
			 */
			IAssemblyComponent* IAssemblyComponentCreator::Create(Assembly* assembly) {

				return 0;
			}

		}

	}

}