#pragma once

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


		#define IMPLEMENT_SINGLETON(T) T* TInstance = new T();

	}

}

#include "Singleton.tpp"
