#pragma once

#include <ING/EntryPoint/EntryPoint.h>




namespace ING {

	namespace Utils {

		template<class T>
		class ING_API Singleton {

			/*
			 *	Constructors And Destructor
			 */
		public:
			Singleton() {

			}



			/*
			 *	Instance
			 */
		private:
			static T* mInstance;

		public:
			static T* GetInstance() { return mInstance; }

		};

		template<class T>
		T* Singleton<T>::mInstance = nullptr;

		#define IMPLEMENT_SINGLETON(T) T* TInstance = new T();

	}

}