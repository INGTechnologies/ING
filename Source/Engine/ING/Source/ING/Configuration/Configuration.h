#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include String, Map
 */
#include <string>
#include <map>



namespace ING {

	class ING_API Configuration
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		Configuration();
		~Configuration();



		/**
		 *	ptr map
		 */
	private:
		std::map<String, void*> ptrMap;



		/**
		 *	Methods
		 */
	public:
		bool Exist(const String& name) {

			return (ptrMap.find(name) != ptrMap.end());

		}

		void Add(const String& name, unsigned int size) {

			if (ptrMap.find(name) != ptrMap.end()) return;

			void* pData = malloc(size);

			ptrMap[name] = pData;

		}

		template<typename T>
		void Add(const String& name) {

			if (ptrMap.find(name) != ptrMap.end()) return;

			void* pData = new T();

			ptrMap[name] = pData;

		}

		template<typename T>
		T Get(const String& name) {

			if (ptrMap.find(name) == ptrMap.end()) return T();

			if (ptrMap.find(name) == ptrMap.end()) {

				return T();

			}

			T data = *((T*)(ptrMap[name]));

			return data;

		}

		template<typename T>
		void Set(const String& name, T data) {

			if (ptrMap.find(name) == ptrMap.end()) return;

			*((T*)(ptrMap[name])) = data;

		}

		bool LoadFromFile(const String& filePath);

	};

}