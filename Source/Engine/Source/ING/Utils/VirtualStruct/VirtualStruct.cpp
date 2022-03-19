
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
		void	VirtualStruct::CopyFrom	(const VirtualStruct& srcStruct) {

			Clear();

			for (auto& item : srcStruct.name2propertyMap) {

				name2propertyMap[item.first] = item.second;

			}

		}

		void	VirtualStruct::CopyTo	(VirtualStruct& destStruct) const {

			destStruct.CopyFrom(*this);

		}

		void	VirtualStruct::Clear	() {

			name2propertyMap.clear();

		}



		/**
		 *	Operators
		 */
		void VirtualStruct::operator +=	(const VirtualStruct& b) {

			for (auto& item : b.name2propertyMap) {

				name2propertyMap[item.first] = item.second;

			}
		}

	}

}