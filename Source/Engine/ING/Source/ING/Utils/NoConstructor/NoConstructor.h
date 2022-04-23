#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



namespace ING {

	namespace Utils {

		template<typename T>
		class NoConstructor {

		public:
			NoConstructor() {

				pData = nullptr;

				pData = (T*)malloc(sizeof(T));

			}
			template<typename TNext>
			NoConstructor(TNext next) :
				NoConstructor()
			{

				DeleteData();

				pData = (T*)malloc(sizeof(T));

				*pData = next;

			}
			~NoConstructor() {

				delete pData;

			}

		private:
			T* pData;

		public:
			T* GetPData() { return pData; }
			T& GetData() { return *pData; }

		public:
			template<typename TNext>
			void operator = (TNext next) {

				DeleteData();

				pData = (T*)malloc(sizeof(T));

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