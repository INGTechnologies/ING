
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
				name2propertyMap[item.first].size  = item.second.size;

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



		/**
		 *	Operators
		 */
		VirtualObject&	VirtualObject::operator =	(VirtualObject& b) {

			Clear();

			vstruct.CopyFrom(b.vstruct);

			Recreate();

			for (auto& item : name2propertyMap) {

				memcpy(item.second.pData, b.name2propertyMap[item.first].pData, item.second.size);

			}

			return *this;
		}

		bool			VirtualObject::operator ==	(VirtualObject& b) {

			for (auto& item : name2propertyMap) {

				if (memcmp(item.second.pData, b.name2propertyMap[item.first].pData, item.second.size) != 0) return 0;

			}

			return true;
		}

		bool			VirtualObject::operator !=	(VirtualObject& b) {

			return !(*this == b);
		}

	}

}