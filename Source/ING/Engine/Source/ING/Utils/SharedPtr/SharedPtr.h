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
 *	Include UniquePtr
 */
#include <ING\Utils\UniquePtr\UniquePtr.h>



 /**
  *	Include NoDuplicatesList
  */
#include <ING\Utils\NoDuplicatesList\NoDuplicatesList.h>



namespace ING {

	namespace Utils {

		template<typename T>
		class SharedPtr {

			/**
			 *	Constructors And Destructor
			 */
		public:
			struct Manager {

				T* ptr;

				bool autoRelease = true;

				unsigned int ptrCount = 0;

			};



			/**
			 *	Constructors And Destructor
			 */
		public:
			SharedPtr()
			{

				CreateDefaultManager();

				manager->autoRelease = false;

			}

			SharedPtr(T data) {

				CreateDefaultManager();

				(manager->ptr) = new T();

				*(manager->ptr) = data;

			}

			SharedPtr(T* pData) {

				CreateDefaultManager();

				manager->ptr = new T();

				manager->ptr = pData;

			}

			SharedPtr(UniquePtr<T>& next) {

				CreateDefaultManager();

				if (next.GetPtr() != nullptr) {

					manager->autoRelease = true;

					manager->ptr = next.GetPtr();

				}
				else {

					manager->autoRelease = false;

					manager->ptr = nullptr;

				}

			}
			
			SharedPtr(SharedPtr<T>& next) {

				this->manager = next.GetManager();

				this->manager->ptrCount++;
			}

			~SharedPtr() {

				if (manager != nullptr) {

					manager->ptrCount--;

					if (manager->ptrCount == 0) {

						if (manager->autoRelease) {

							delete manager->ptr;

						}

						delete manager;

					}

				}

			}



			/**
			 *	Manager
			 */
		protected:
			Manager* manager;

			void CreateDefaultManager() {

				manager = new Manager();

				manager->ptrCount++;

				manager->autoRelease = true;

			}

		public:
			T* GetPtr() {
				return GetManager()->ptr;
			}

			Manager* GetManager() {
				return manager;
			}

			void RemoveManager() {

				delete manager;

			}



			/**
			 *	Operators
			 */
		public:
			T& operator*() {
				return *GetPtr();
			}

		};

	}

}