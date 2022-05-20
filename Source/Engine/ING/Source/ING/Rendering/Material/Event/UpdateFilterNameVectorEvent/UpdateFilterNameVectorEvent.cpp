
/**
 *	Include Header
 */
#include "UpdateFilterNameVectorEvent.h"



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		MaterialUpdateFilterNameVectorEvent::MaterialUpdateFilterNameVectorEvent(IMaterial* material) :
			IMaterialEvent(material)
		{



		}

		MaterialUpdateFilterNameVectorEvent::~MaterialUpdateFilterNameVectorEvent() {



		}



		/**
		 *	Name
		 */
		String MaterialUpdateFilterNameVectorEvent::GetName() { return "UPDATE_FILTER_NAME_VECTOR"; };

	}

}