
/**
 *	Include Header
 */
#include "Creator.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Node
 */
#include <ING/UI/Node/Node.h>



/**
 *	Include Style
 */
#include <ING/UI/Style/Style.h>



namespace ING {

	namespace Editor {

		namespace UI {

			/**
			 *	Constructors And Destructor
			 */
			ITabCreator::ITabCreator(const String& name) :
				name(name)
			{



			}

			ITabCreator::~ITabCreator()
			{



			}



			/**
			 *	Release Method
			 */
			void ITabCreator::Release() {


				delete this;
			}



			/**
			 *	Methods
			 */
			C_Tab* ITabCreator::Create(const String& tabName) {


				return 0;
			}

		}

	}

}