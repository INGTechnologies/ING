
/**
 *	Include Header
 */
#include "Convertor.h"



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			Convertor::Convertor() {



			}

			Convertor::~Convertor() {



			}



			/**
			 *	Release Methods
			 */
			void Convertor::Release() {


				/* Clear Maps */
				clearFlagMap.clear();

				cullModeMap.clear();
				
				fillModeMap.clear();
				
				formatMap.clear();
				
				primitiveTopologyMap.clear();



				Rendering::Convertor::Release();

			}

		}

	}

}