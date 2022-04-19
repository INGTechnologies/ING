
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



/**
 *	Include CSharp Assembly Component
 */
#include <ING/Scripting/CSharp/Assembly/Component/Component.h>



/**
 *	Include CSharp Assembly Component Creator
 */
#include <ING/Scripting/CSharp/Assembly/Component/Creator/Creator.h>



/**
 *	Include CSharp Language
 */
#include <ING/Scripting/CSharp/Language/Language.h>



namespace ING {

	namespace Scripting {

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			Assembly::Assembly(Context* context, const std::string& name, const std::vector<std::string>& componentNameVector) :
				context(context),

				monoAssembly(0),
				monoImage(0),

				name(name),

				isOpening(false)
			{

				componentVector.resize(componentNameVector.size());

				for (unsigned int i = 0; i < componentNameVector.size(); ++i) {

					IAssemblyComponentCreator* componentCreator = ((Language*)context->GetLanguage())->GetAssemblyComponentCreator(componentNameVector[i]);

					if (componentCreator == 0) {

						Debug::Error(String('"') + componentNameVector[i] + String('"') + String(" Assembly Component Creator Not Found"));

						componentVector.resize(i);

						break;

					}

					componentVector[i] = componentCreator->Create(this);

					componentName2ComponentIndexMap[componentVector[i]->GetName()] = i;

				}

			}

			Assembly::~Assembly()
			{



			}



			/**
			 *	Release Method
			 */
			void Assembly::Release() {

				if (isOpening) {

					OnClose();

				}

				for (auto item : componentVector) {

					item->Release();

				}

				componentVector.clear();

				componentName2ComponentIndexMap.clear();

				delete this;

			}



			/**
			 *	Methods
			 */
			void Assembly::OnOpen() {

				isOpening = true;

				for (auto item : componentVector) {

					item->OnOpen();

				}

			}

			void Assembly::OnClose() {

				for (auto item : componentVector) {

					item->OnClose();

				}

				isOpening = false;

			}

		}

	}

}