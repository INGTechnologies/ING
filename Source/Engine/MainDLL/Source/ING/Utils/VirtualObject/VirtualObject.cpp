
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

		VirtualObject::VirtualObject	(const VirtualStruct& vstruct) : VirtualObject() {

			this->vstruct.CopyFrom(vstruct);

			Recreate();

		}

		VirtualObject::VirtualObject	(const VirtualObject& srcObj) : VirtualObject(srcObj.vstruct) {

			for (auto& item : name2propertyMap) {

				memcpy(item.second.pData, srcObj.name2propertyMap.find(item.first)->second.pData, item.second.size);

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

			name2propertyMap.clear();

		}



		/**
		 *	Operators
		 */
		VirtualObject&	VirtualObject::operator =	(const VirtualObject& b) {

			vstruct.CopyFrom(b.vstruct);

			Recreate();

			for (auto& item : name2propertyMap) {

				memcpy(item.second.pData, b.name2propertyMap.find(item.first)->second.pData, item.second.size);

			}

			return *this;
		}

		VirtualObject& VirtualObject::operator +=	(const VirtualObject& b) {

			vstruct += b.vstruct;

			for (auto& item : name2propertyMap) {

				if(b.name2propertyMap.find(item.first) != b.name2propertyMap.end())
					(item.second.pData, b.name2propertyMap.find(item.first)->second.pData, item.second.size);

			}

			return *this;
		}

		bool			VirtualObject::operator ==	(const VirtualObject& b) const {

			for (auto& item : name2propertyMap) {

				if (memcmp(item.second.pData, b.name2propertyMap.find(item.first)->second.pData, item.second.size) != 0) return 0;

			}

			return true;
		}

		bool			VirtualObject::operator !=	(const VirtualObject& b) const {

			return !(*this == b);
		}

	}

}