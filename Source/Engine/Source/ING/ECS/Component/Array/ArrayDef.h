#pragma once

#include "Array.h"



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {

		template<typename T>
		void			ComponentArray<T>::AllocateData() {

			size = (count * 2);

			unsigned int sizeInByte = size * stride;

			unsigned int oldSizeInByte = this->sizeInByte;

			T* newPData = (T*)malloc(sizeInByte);



			if (pData != nullptr) {

				memcpy(newPData, pData, ([](unsigned int sizeInByte, unsigned int oldSizeInByte)->unsigned int {

					if (sizeInByte > oldSizeInByte) {

						return oldSizeInByte;

					}

					return sizeInByte;

					})(sizeInByte, oldSizeInByte));

				free(pData);

			}



			this->sizeInByte = sizeInByte;



			pData = newPData;

		}

		template<typename T>
		void			ComponentArray<T>::Add(T& component, ComponentId id) {

			unsigned int index = count;

			id2IndexMap[id] = index;
			index2IdMap[index] = id;

			++count;

			if (count > size || count == 1) {

				AllocateData();

			}

			pData[index] = component;

		}

		template<typename T>
		T&				ComponentArray<T>::Get(ComponentId id) {

			return pData[id2IndexMap[id]];

		}

		template<typename T>
		T*				ComponentArray<T>::GetDataPtr(ComponentId id) {

			return pData + id2IndexMap[id];

		}

		template<typename T>
		void			ComponentArray<T>::Erase(ComponentId id) {

			unsigned int index = id2IndexMap[id];

			if (count > 1) {

				ComponentId lastComponentId = index2IdMap[count - 1];

				pData[index] = pData[count - 1];

				index2IdMap[index] = lastComponentId;

				id2IndexMap[lastComponentId] = index;

				index2IdMap.erase(count - 1);

				id2IndexMap.erase(id);

			}

			--count;

			if (count < size / 4 || count == 0) {

				AllocateData();

			}

		}

		template<typename T>
		void			ComponentArray<T>::Clear() {

			id2IndexMap.clear();
			index2IdMap.clear();

			if (pData != nullptr) {

				free(pData);

			}

		}

	}

}