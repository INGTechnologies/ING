#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include IOStream
 */
#include <iostream>



/**
 *	Include Virtual Struct
 */
#include <ING/Utils/VirtualStruct/VirtualStruct.h>



namespace ING {

	namespace Utils {

		struct VirtualObjectProperty : public VirtualStructProperty {

			void* pData = nullptr;

		};



		class ING_API VirtualObject {

			/**
			 *	Constructors And Destructor
			 */
		public:
			VirtualObject	();
			VirtualObject	(VirtualStruct& vstruct);
			VirtualObject	(VirtualObject* srcObj);
			~VirtualObject	();



			/**
			 *	Properties
			 */
		private:
			VirtualStruct											vstruct;

			std::unordered_map<std::string, VirtualObjectProperty>	name2propertyMap;

		public:
			const VirtualStruct&									GetVStruct			() { return vstruct; }

			std::unordered_map<std::string, VirtualObjectProperty>& GetName2propertyMap	() { return name2propertyMap; }



			/**
			 *	Methods
			 */
		public:
			template<typename T>
			void	AddProperty		(std::string name) {

				VirtualObjectProperty prop;

				prop.name	= name;

				prop.size	= sizeof(T);

				prop.pData	= malloc(sizeof(T));

				name2propertyMap[name] = prop;



				VirtualStructProperty vStructProp;

				vStructProp.name = name;

				vStructProp.size = sizeof(T);

				vstruct.GetName2propertyMap()[name] = vStructProp;

			}

			template<typename T>
			void	SetProperty		(std::string name, T& data) {

				*((T*)(name2propertyMap[name].pData)) = data;

			}

			template<typename T>
			T&		GetProperty		(std::string name) {

				return *((T*)(name2propertyMap[name].pData));

			}

			void	RemoveProperty	(std::string name) {

				if (name2propertyMap[name].pData != nullptr) {

					free(name2propertyMap[name].pData);

				}

				name2propertyMap.erase(name);



				vstruct.GetName2propertyMap().erase(name);

			}

			void	Recreate		();

			void	Clear			();



			/**
			 *	Operators
			 */

		};

	}

}