
/**
 *	Include Header
 */
#include "EngineComponent.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



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



namespace ING {

	namespace Scripting {

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			EngineAssemblyComponent::EngineAssemblyComponent(Assembly* assembly, const String& name) :
				IAssemblyComponent(assembly, name)
			{



			}

			EngineAssemblyComponent::~EngineAssemblyComponent()
			{



			}



			/**
			 *	Release Method
			 */
			void EngineAssemblyComponent::Release() {

				IAssemblyComponent::Release();

			}



			/**
			 *	Methods
			 */
			void EngineAssemblyComponent::OnOpen() {



			}

			void EngineAssemblyComponent::OnClose() {



			}


		}

	}

}