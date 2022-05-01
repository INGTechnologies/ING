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



/**
 *	Include String
 */
#include <ING/Utils/String/String.h>



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
			VirtualObject	(const VirtualStruct& vstruct);
			VirtualObject	(const VirtualObject& srcObj);
			~VirtualObject	();



			/**
			 *	Properties
			 */
		private:
			VirtualStruct											vstruct;

			std::unordered_map<String, VirtualObjectProperty>	name2propertyMap;

		public:
			const VirtualStruct&									GetVStruct			() { return vstruct; }

			std::unordered_map<String, VirtualObjectProperty>& GetName2propertyMap	() { return name2propertyMap; }



			/**
			 *	Methods
			 */
		public:
			template<typename T>
			void	AddProperty		(const String& name) {

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
			void	SetProperty		(const String& name, const T& data) {

				*((T*)(name2propertyMap[name].pData)) = data;

			}

			template<typename T>
			void	TrySetProperty(const String& name, const T& data) {

				if (name2propertyMap.find(name) == name2propertyMap.end()) return;

				*((T*)(name2propertyMap[name].pData)) = data;

			}

			template<typename T>
			T		GetProperty		(const String& name) const {

				return *((T*)(name2propertyMap.find(name)->second.pData));

			}

			void	RemoveProperty	(const String& name) {

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
		public:
			VirtualObject& operator =	(const VirtualObject& b);
			VirtualObject& operator +=	(const VirtualObject& b);

			bool		   operator ==	(const VirtualObject& b) const;
			bool		   operator !=	(const VirtualObject& b) const;

		};

	}

}