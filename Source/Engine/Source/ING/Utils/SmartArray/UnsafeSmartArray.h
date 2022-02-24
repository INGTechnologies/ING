#pragma once

/**
 *	Include Unordered Map
 */
#include <unordered_map>



/**
 *	Define And Declares Classes, Structs,... 
 */
namespace ING {

	namespace Utils {

		struct Entity;


		const unsigned int MAX_UNSAFE_SMART_ARRAY_SIZE_IN_BYTE = 1000 * 4 * 7;



		/**
		 *	Interface Class
		 */
		class IUnsafeSmartArray {

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
		class UnsafeSmartArray : public IUnsafeSmartArray
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			UnsafeSmartArray() {

				sizeInByte	= 0;

				stride		= sizeof(T);

				pData		= nullptr;

				count		= 0;

				size		= 1;

			}

			~UnsafeSmartArray() {

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

			std::unordered_map <unsigned int  , unsigned int>	id2IndexMap;

			std::unordered_map <unsigned int , unsigned int>	index2IdMap;

		public:
			unsigned int	GetStride		() { return stride; }

			unsigned int	GetCount		() { return count; }

			unsigned int	GetSize			() { return size; }

			T*				GetPData		() { return pData; }

			unsigned int	GetSizeInByte	() { return sizeInByte; }

			std::unordered_map <unsigned int, unsigned int>& GetId2IndexMap() { return id2IndexMap; }

			std::unordered_map <unsigned int, unsigned int>& GetIndex2IdMap() { return index2IdMap; }

			bool			IsFull() { return ((count + 1) * 2 * stride > MAX_UNSAFE_SMART_ARRAY_SIZE_IN_BYTE); }



			/**
			 *	Methods
			 */
		public:
			void			AllocateData	();

			void			Add		(T& component, unsigned int id);

			T&				Get		(unsigned int id);

			T*				GetDataPtr		(unsigned int id);

			void			Erase			(unsigned int id);

			void			Clear			();

		};

	}

}



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace Utils {

		template<typename T>
		void			UnsafeSmartArray<T>::AllocateData() {

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
		void			UnsafeSmartArray<T>::Add(T& component, unsigned int id) {

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
		T& UnsafeSmartArray<T>::Get(unsigned int id) {

			return pData[id2IndexMap[id]];

		}

		template<typename T>
		T* UnsafeSmartArray<T>::GetDataPtr(unsigned int id) {

			return pData + id2IndexMap[id];

		}

		template<typename T>
		void			UnsafeSmartArray<T>::Erase(unsigned int id) {

			unsigned int index = id2IndexMap[id];

			if (count > 1) {

				unsigned int lastComponentId = index2IdMap[count - 1];

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
		void			UnsafeSmartArray<T>::Clear() {

			id2IndexMap.clear();
			index2IdMap.clear();

			if (pData != nullptr) {

				free(pData);

			}

		}

	}

}