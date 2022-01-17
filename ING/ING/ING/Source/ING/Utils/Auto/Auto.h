#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Vector
 */
#include <vector>



/**
 *	Include String
 */
#include <string>



namespace ING {

	namespace Utils {

		struct Auto {

		public:
			Auto() {

				pData = nullptr;

			}
			template<typename T>
			Auto(T next):
				Auto()
			{

				DeleteData();

				pData = malloc(sizeof(T));

				memcpy(pData, &next, sizeof(T));

			}
			~Auto() {

				DeleteData();

			}

		private:
			void* pData;

		public:
			void* GetPData() { return pData; }

		public:
			template<typename T>
			void operator = (T next) {

				DeleteData();

				pData = malloc(sizeof(T));

				memcpy(pData, &next, sizeof(T));

			}

			template<typename T>
			T& As() {

				return *((T*)pData);
			}

			void DeleteData() {

				if (pData != nullptr) {

					free(pData);

					pData = nullptr;

				}

			}

		};

	}

}