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
 *	Include Unordered Map
 */
#include <unordered_map>



namespace ING {

	namespace Utils {

		struct VirtualStructProperty {

			size_t		size;

			std::string name;

		};



		class ING_API VirtualStruct {

			/**
			 *	Constructors And Destructor
			 */
		public:
			VirtualStruct	();
			~VirtualStruct	();



			/**
			 *	Properties
			 */		
		private:
			std::unordered_map<std::string, VirtualStructProperty>	name2propertyMap;

		public:
			std::unordered_map<std::string, VirtualStructProperty>&	GetName2propertyMap	() { return name2propertyMap; }
			


			/**
			 *	Methods
			 */
		public:
			template<typename T>
			void	AddProperty		(const std::string& name) {

				VirtualStructProperty prop;

				prop.name = name;

				prop.size = sizeof(T);

				name2propertyMap[name] = prop;

			}

			void	RemoveProperty	(const std::string& name) {

				name2propertyMap.erase(name);

			}

			void	CopyFrom	(const VirtualStruct& srcStruct);
			void	CopyTo		(VirtualStruct& destStruct) const;

			void	Clear		();



			/**
			 *	Operators
			 */
		public:
			void operator +=	(const VirtualStruct& b);

		};

	}

}