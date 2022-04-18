
/**
 *	Include Header
 */
#include "Component.h"



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



namespace ING {

	namespace Scripting {

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			IAssemblyComponent::IAssemblyComponent(Assembly* assembly, const std::string& name) :
				assembly(assembly),

				name(name)
			{



			}

			IAssemblyComponent::~IAssemblyComponent()
			{



			}



			/**
			 *	Release Method
			 */
			void IAssemblyComponent::Release() {

				delete this;

			}



			/**
			 *	Methods
			 */
			void IAssemblyComponent::OnOpen() {



			}

			void IAssemblyComponent::OnClose() {



			}


		}

	}

}