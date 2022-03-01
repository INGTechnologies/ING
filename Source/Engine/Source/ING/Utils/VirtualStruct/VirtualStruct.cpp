
/**
 *	Include Header
 */
#include "VirtualStruct.h"



namespace ING {

	namespace Utils {

		/**
		 *	Constructors And Destructor
		 */
		VirtualStruct::VirtualStruct() {



		}

		VirtualStruct::~VirtualStruct() {

			Clear();

		}



		/**
		 *	Methods
		 */
		void	VirtualStruct::CopyFrom	(VirtualStruct& srcStruct) {

			Clear();

			for (auto& item : srcStruct.name2propertyMap) {

				name2propertyMap[item.first] = item.second;

			}

		}

		void	VirtualStruct::CopyTo	(VirtualStruct& destStruct) {

			destStruct.CopyFrom(*this);

		}

		void	VirtualStruct::Clear	() {

			name2propertyMap.clear();

		}

	}

}