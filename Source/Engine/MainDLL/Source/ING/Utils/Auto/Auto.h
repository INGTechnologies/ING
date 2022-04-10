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

		class Auto {

		public:
			Auto() : pData(0) {



			}
			template<typename T>
			Auto(T next):
				Auto()
			{

				DeleteData();

				pData = malloc(sizeof(T));

				size = sizeof(T);

				memcpy(pData, &next, sizeof(T));

			}
			~Auto() {

				DeleteData();

			}

		private:
			void* pData;
			unsigned int size;

		public:
			void*			GetPData() { return pData; }
			unsigned int	GetSize() { return size; }

		public:
			template<typename T>
			void operator = (const T& next) {

				DeleteData();

				pData = malloc(sizeof(T));

				size = sizeof(T);

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

			void CopyFrom(Auto& src) {

				DeleteData();

				pData = malloc(src.size);

				size = src.size;

				memcpy(pData, src.pData, size);

			}

			void CopyTo(Auto& target) {

				target.DeleteData();

				target.pData = malloc(size);

				target.size = size;

				memcpy(target.pData, pData, size);

			}

			Auto Clone() {

				Auto result;

				CopyTo(result);

				return result;

			}

		};

	}

}