#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



namespace ING {

	namespace Utils {

		template<typename T>
		class NoDestructor {

		public:
			NoDestructor() {

				pData = nullptr;

				pData = new T();

			}
			template<typename TNext>
			NoDestructor(TNext next) :
				NoDestructor()
			{

				DeleteData();

				pData = new T();

				*pData = next;

			}
			~NoDestructor() {

				free(pData);

			}

		private:
			T* pData;

		public:
			T*	GetPData()	{ return pData; }
			T&	GetData()	{ return *pData; }

		public:
			template<typename TNext>
			void operator = (TNext next) {

				DeleteData();

				pData = new T();

				*pData = next;

			}

			void DeleteData() {

				if (pData != nullptr) {

					delete pData;

					pData = nullptr;

				}

			}

		};

	}

}