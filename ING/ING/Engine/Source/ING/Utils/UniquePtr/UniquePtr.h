#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



 /**
  *	Include IOStream
  */
#include <iostream>



namespace ING {

	namespace Utils {

		template<typename T>
		class UniquePtr {
		
			/**
			 *	Constructors And Destructor
			 */
		public:
			UniquePtr():
				ptr(nullptr)
			{



			}

			UniquePtr(T data) {

				ptr = new T();

				*ptr = data;

			}

			UniquePtr(T* pData) {

				ptr = new T();

				ptr = pData;

			}

			UniquePtr(UniquePtr<T>& next) {

				this->ptr = next.GetPtr();

				next.ptr = nullptr;

			}

			~UniquePtr() {

				if (ptr != NULL && ptr != 0 && ptr != nullptr) {
					delete ptr;
				}

			}




			/**
			 *	Ptr 
			 */
		protected:
			T* ptr;

		public:
			T* GetPtr() {
				return ptr;
			}



			/**
			 *	Operators
			 */
		public:
			T& operator*() {
				return *ptr;
			}

		};

	}

}