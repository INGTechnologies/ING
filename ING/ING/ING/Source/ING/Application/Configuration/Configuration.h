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

	class ING_API ApplicationConfiguration
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ApplicationConfiguration();
		~ApplicationConfiguration();



		/**
		 *	ptr map
		 */
	private:
		std::map<std::string, void*> ptrMap;



		/**
		 *	Add, Set, Get Methods
		 */
	public:
		template<typename T>
		void Add(std::string name) {

			void* pData = new T();

			ptrMap[name] = pData;

		}

		template<typename T>
		T Get(std::string name) {

			if (ptrMap.find(name) == ptrMap.end()) {

				return T();

			}

			T data = *((T*)(ptrMap[name]));

			return data;

		}

		template<typename T>
		void Set(std::string name, T data) {

			*((T*)(ptrMap[name])) = data;

		}

	};

}