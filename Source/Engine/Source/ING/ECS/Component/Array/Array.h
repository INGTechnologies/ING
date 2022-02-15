#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include ECS Component Id
 */
#include <ING/ECS/Component/Id/Id.h>



/**
 *	Include Unordered Map
 */
#include <unordered_map>



/**
 *	Define And Declares Classes, Structs,... 
 */
namespace ING {

	namespace ECS {

		class Entity;



		/**
		 *	Interface Class
		 */
		class IComponentArray {

			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() {

				delete this;

			}

		};



		/**
		 *	Main Class
		 */
		template<typename T>
		class ComponentArray : public IComponentArray
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ComponentArray() {

				sizeInByte	= 0;

				stride		= sizeof(T);

				pData		= nullptr;

				count		= 0;

				size		= 1;

			}

			~ComponentArray() {

				Clear();

			}



			/**
			 *	Properties
			 */
		private:
			unsigned int	stride;

			unsigned int	count;

			unsigned int	size;

			T*				pData;

			unsigned int	sizeInByte;

			std::unordered_map <ComponentId  , unsigned int> id2IndexMap;

			std::unordered_map <unsigned int , ComponentId>	 index2IdMap;

		public:
			unsigned int	GetStride		() { return stride; }

			unsigned int	GetCount		() { return count; }

			unsigned int	GetSize			() { return size; }

			T*				GetPData		() { return pData; }

			unsigned int	GetSizeInByte	() { return sizeInByte; }

			std::unordered_map <ComponentId, unsigned int>& GetId2IndexMap() { return id2IndexMap; }

			std::unordered_map <unsigned int, ComponentId>& GetIndex2IdMap() { return index2IdMap; }



			/**
			 *	Methods
			 */
		public:
			void			AllocateData	();

			void			Add				(T& component, ComponentId id);

			T&				Get				(ComponentId id);

			void			Erase			(ComponentId id);

			void			Clear			();

		};

	}

}



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