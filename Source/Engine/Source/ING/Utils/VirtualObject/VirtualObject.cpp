
/**
 *	Include Header
 */
#include "VirtualObject.h"



namespace ING {

	namespace Utils {

		/**
		 *	Constructors And Destructor
		 */
		VirtualObject::VirtualObject	() {



		}

		VirtualObject::VirtualObject	(VirtualStruct& vstruct) : VirtualObject() {

			this->vstruct.CopyFrom(vstruct);

			Recreate();

		}

		VirtualObject::VirtualObject	(VirtualObject* srcObj) : VirtualObject(srcObj->vstruct) {

			for (auto& item : name2propertyMap) {

				memcpy(item.second.pData, srcObj->name2propertyMap[item.first].pData, item.second.size);

			}

		}

		VirtualObject::~VirtualObject	() {

			Clear();

		}



		/**
		 *	Methods
		 */
		void	VirtualObject::Recreate() {

			Clear();

			std::unordered_map<std::string, VirtualStructProperty>	vstructName2propertyMap = vstruct.GetName2propertyMap();

			for (auto& item : vstructName2propertyMap) {

				name2propertyMap[item.first].pData = malloc(item.second.size);
				name2propertyMap[item.first].name  = item.second.name;

			}

		}

		void	VirtualObject::Clear() {

			for (auto& item : name2propertyMap) {

				if (item.second.pData != nullptr) {

					free(item.second.pData);

					item.second.pData = nullptr;

				}

			}

		}

	}

}