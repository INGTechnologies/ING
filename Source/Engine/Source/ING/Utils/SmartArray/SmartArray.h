#pragma once

/**
 *	Include Unordered Map
 */
#include <unordered_map>



/**
 *	Include Vector
 */
#include <vector>



/**
 *	Define And Declares Classes, Structs,... 
 */
namespace ING {

	namespace Utils {

		struct Entity;


		const unsigned int SMART_ARRAY_MAX_SIZE_IN_BYTE_PER_BLOCK = std::numeric_limits<std::vector<int>::size_type>::max();



		template<typename T>
		class SmartArrayBlock {

		public:
			SmartArrayBlock() {

				filledCount = 0;
				count = 0;
				pData = 0;

			}



			/**
			 *	Properties
			 */
		public:
			T* pData;
			unsigned int filledCount;
			unsigned int count;

			std::unordered_map<unsigned int, unsigned int>	id2IndexMap;
			std::unordered_map<unsigned int, unsigned int>	index2IdMap;



			/**
			 *	Methods
			 */
		public:
			void Allocate(unsigned int newFilledCount);
			void Add(T& data, unsigned int id);
			void Erase(unsigned int id);
			void Clear();
			T& Get(unsigned int id);
			T* GetDataPtr(unsigned int id);
			bool IsFull() { return (count == filledCount && (count + 1) * sizeof(T) > SMART_ARRAY_MAX_SIZE_IN_BYTE_PER_BLOCK); }

		};



		/**
		 *	Interface Class
		 */
		class ISmartArray {

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
		class SmartArray : public ISmartArray
		{
			/**
			 *	Constructors And Destructor
			 */
		public:
			SmartArray() {

				count		= 0;

			}

			~SmartArray() {

				Clear();

			}



			/**
			 *	Properties
			 */
		private:
			unsigned int		count;

			std::vector<SmartArrayBlock<T>*>	blockVector;

			std::unordered_map<unsigned int, unsigned int>	id2BlockIndexMap;

		public:
			unsigned int		GetCount() { return count; }

			std::vector<SmartArrayBlock<T>*>& GetBlockVector() { return blockVector; }

			std::unordered_map<unsigned int, unsigned int>	GetId2BlockIndexMap	() {return id2BlockIndexMap;}



			/**
			 *	Methods
			 */
		public:
			void Clear();
			void Add(T& data, unsigned int id);
			void Erase(unsigned int id);
			T&	 Get(unsigned int id);
			T*	 GetDataPtr(unsigned int id);

		};

	}

}



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace Utils {

		/**
		 *	Methods
		 */
		template<typename T>
		void SmartArrayBlock<T>::Allocate(unsigned int newFilledCount) {

			unsigned int newCount = newFilledCount * 2;

			while (newCount * sizeof(T) > SMART_ARRAY_MAX_SIZE_IN_BYTE_PER_BLOCK) {

				if (((int)newCount) - 1 >= 0) {

					--newCount;

				}
				else {

					newCount = 0;

				}

			}

			if (newCount != 0) {

				unsigned int sizeInByte = newCount * sizeof(T);

				unsigned int oldSizeInByte = count * sizeof(T);

				T* newPData = (T*)malloc(sizeInByte);

				if (pData != nullptr) {

					memcpy(newPData, pData, ([](unsigned int sizeInByte, unsigned int oldSizeInByte)->unsigned int {

						if (sizeInByte > oldSizeInByte) {

							return oldSizeInByte;

						}

						return sizeInByte;

					})(sizeInByte, oldSizeInByte));

					free(pData);

					pData = nullptr;

				}

				pData = newPData;

			}
			else {

				if (pData != nullptr) {

					free(pData);

					pData = nullptr;

				}

			}

			count = newCount;
			filledCount = newFilledCount;

		}

		template<typename T>
		void SmartArrayBlock<T>::Clear() {

			if (pData != nullptr) {

				free(pData);

				pData = nullptr;

			}

			count = 0;

			filledCount = 0;

			id2IndexMap.clear();
			index2IdMap.clear();
			
		}

		template<typename T>
		void SmartArrayBlock<T>::Add(T& data, unsigned int id) {

			if (filledCount + 1 > count) {

				Allocate(filledCount + 1);

			}
			else {

				++filledCount;

			}

			unsigned int index = filledCount - 1;

			pData[index] = data;

			id2IndexMap[id] = index;

			index2IdMap[index] = id;

		}

		template<typename T>
		void SmartArrayBlock<T>::Erase(unsigned int id) {

			unsigned int index = id2IndexMap[id];

			if (filledCount > 1) {

				if (filledCount - 1 != index) {

					unsigned int lastComponentId = index2IdMap[filledCount - 1];

					pData[index] = pData[filledCount - 1];

					index2IdMap[index] = lastComponentId;

					id2IndexMap[lastComponentId] = index;

					index2IdMap.erase(filledCount - 1);

					id2IndexMap.erase(id);

				}
				else {

					index2IdMap.erase(index);

					id2IndexMap.erase(id);

				}

				--filledCount;

				if (filledCount <= count / 4) {

					Allocate(filledCount);

				}

			}
			else {

				filledCount = 0;

				count = 0;

				index2IdMap.clear();

				id2IndexMap.clear();

				if (pData != nullptr) {

					free(pData);

					pData = nullptr;

				}

			}

		}

		template<typename T>
		T& SmartArrayBlock<T>::Get(unsigned int id) {

			return pData[id2IndexMap[id]];

		}

		template<typename T>
		T* SmartArrayBlock<T>::GetDataPtr(unsigned int id) {

			return pData + id2IndexMap[id];

		}

		template<typename T>
		void SmartArray<T>::Clear() {

			id2BlockIndexMap.clear();

			for (SmartArrayBlock<T>* block : blockVector) {

				block->Clear();

			}

			blockVector.clear();

		}

		template<typename T>
		void SmartArray<T>::Add(T& data, unsigned int id) {

			if (blockVector.size() == 0) {

				blockVector.push_back(new SmartArrayBlock<T>());

			}
			else {

				if (blockVector[blockVector.size() - 1]->IsFull()) {

					blockVector.push_back(new SmartArrayBlock<T>());

				}

			}

			unsigned int blockIndex = blockVector.size() - 1;

			SmartArrayBlock<T>* block = blockVector[blockIndex];

			block->Add(data, id);

			id2BlockIndexMap[id] = blockIndex;

		}

		template<typename T>
		void SmartArray<T>::Erase(unsigned int id) {

			unsigned int blockIndex = id2BlockIndexMap[id];

			SmartArrayBlock<T>* block = blockVector[blockIndex];

			block->Erase(id);

			if (block->count == 0) {

				block->Clear();

				blockVector.resize(blockVector.size() - 1);

			}

			id2BlockIndexMap.erase(id);

		}

		template<typename T>
		T&	SmartArray<T>::Get(unsigned int id) {

			unsigned int blockIndex = id2BlockIndexMap[id];

			return blockVector[blockIndex]->Get(id);

		}

		template<typename T>
		T*	SmartArray<T>::GetDataPtr(unsigned int id) {

			unsigned int blockIndex = id2BlockIndexMap[id];

			return blockVector[blockIndex]->GetDataPtr(id);

		}

	}

}