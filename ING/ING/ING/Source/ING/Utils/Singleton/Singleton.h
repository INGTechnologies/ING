#pragma once

/*
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



namespace ING {

	namespace Utils {

		template<class T>
		class Singleton {

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



		/*
		 *	Define Members
		 */
		template<class T>
		T* Singleton<T>::mInstance;

		template<class T>
		T* Singleton<T>::GetInstance() {
			return mInstance;
		}



		/*
		 *	Include Macros
		 */
		#define IMPLEMENT_SINGLETON(T) T* TInstance = new T();

	}

}

