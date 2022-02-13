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

				lastFilledComponentIndex = 0;

				size		= 1;

				AllocateData();

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

			unsigned int	lastFilledComponentIndex;

			unsigned int	size;

			T*				pData;

			unsigned int	sizeInByte;

		public:
			unsigned int	GetStride		() { return stride; }

			unsigned int	GetCount		() { return count; }

			unsigned int	GetLastFilledComponentIndex() { return lastFilledComponentIndex; }

			unsigned int	GetSize			() { return size; }

			void*			GetPData		() { return pData; }

			unsigned int	GetSizeInByte	() { return sizeInByte; }



			/**
			 *	Methods
			 */
		public:
			void			AllocateData() {

				size = ((lastFilledComponentIndex + 1) * 2);

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

				if(count != 0)
					++lastFilledComponentIndex;

				++count;

				if (lastFilledComponentIndex >= size) {

					AllocateData();

				}

				pData[lastFilledComponentIndex] = component;

			}

			void			Erase	(ComponentId id) {

				--count;

				if (count < 0) count = 0;

				if (lastFilledComponentIndex == id) {

					--lastFilledComponentIndex;

				}

				if (lastFilledComponentIndex + 1 <= (size / 4)) {

					AllocateData();

				}

			}

			void			Clear	() {

				if (pData != nullptr) {

					free(pData);

				}

			}

		};

	}

}