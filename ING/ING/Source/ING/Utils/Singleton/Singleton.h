#pragma once

#include <ING\EntryPoint\EntryPoint.h>




namespace ING {

	namespace Utils {

		template<class T>
		class ING_API Singleton {

			/*
			 *	Constructors And Destructor
			 */
		public:
			Singleton() {

				mInstance = (T*)this;

			}



			/*
			 *	Instance
			 */
		private:
			static T* mInstance;

		public:
			static T* GetInstance();

		};

#ifdef ING_EXPORTS

		template<class T>
		T* Singleton<T>::mInstance = nullptr;

		template<class T>
		T* Singleton<T>::GetInstance() { return mInstance; }

#endif

		#define IMPLEMENT_SINGLETON(T) T* TInstance = new T();

	}

}

