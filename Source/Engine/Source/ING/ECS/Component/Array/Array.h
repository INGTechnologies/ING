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
 *	Include ECS Component
 */
#include <ING/ECS/Component/Component.h>



/**
 *	Include Unordered Map
 */
#include <unordered_map>



namespace ING {

	namespace ECS {

		class Entity;



		class IComponentArray {

			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() {

				delete this;

			}

		};



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

				//AllocateData();

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

			IdGenerator		idGenerator;

		public:
			unsigned int	GetStride		() { return stride; }

			unsigned int	GetCount		() { return count; }

			unsigned int	GetSize			() { return size; }

			void*			GetPData		() { return pData; }

			unsigned int	GetSizeInByte	() { return sizeInByte; }

			std::unordered_map <ComponentId, unsigned int>& GetId2IndexMap() { return id2IndexMap; }

			std::unordered_map <unsigned int, ComponentId>& GetIndex2IdMap() { return index2IdMap; }



			/**
			 *	Methods
			 */
		public:
			void			AllocateData() {

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

			void			Add		(T& component) {

				ComponentId id = idGenerator.GenUInt32();

				unsigned int index = count;

				id2IndexMap[id] = index;
				index2IdMap[index] = id;

				++count;

				if (count > size || count == 1) {

					AllocateData();

				}

				pData[index] = component;

			}

			void			Erase	(ComponentId id) {

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

			void			Clear	() {

				id2IndexMap.clear();
				index2IdMap.clear();

				idGenerator.ClearIds();

				if (pData != nullptr) {

					free(pData);

				}

			}

		};

	}

}