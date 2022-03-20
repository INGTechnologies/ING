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



		/**
		 *	longerface Class
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
				filledCount = 0;
				pData		= nullptr;

			}

			~SmartArray() {

				Clear();

			}



			/**
			 *	Properties
			 */
		private:
			T*										pData;
			size_t									filledCount;
			size_t									count;

			std::vector < std::unordered_map<size_t, size_t>* >	id2IndexMapVector;
			std::vector < std::unordered_map<size_t, size_t>* >	index2IdMapVector;

		public:
			T*										GetPData		() { return pData; }

			size_t									GetCount		() { return count; }

			size_t									GetFilledCount	() { return filledCount; }

			std::vector < std::unordered_map<size_t, size_t>* > & GetId2IndexMapVector	() { return id2IndexMapVector; }
			std::vector < std::unordered_map<size_t, size_t>* > & GetIndex2IdMapVector	() { return index2IdMapVector; }



			/**
			 *	Methods
			 */
		private:
			void Allocate(size_t newFilledCount);

		public:
			size_t Id2Index(size_t id);
			size_t Index2Id(size_t index);

		public:
			void Clear();
			void Add(const T& data, size_t id);
			void Erase(size_t id);
			T&	 Get(size_t id);
			T*	 GetDataPtr(size_t id);

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
		size_t SmartArray<T>::Id2Index(size_t id) {

			for (std::unordered_map<size_t, size_t>*& id2IndexMap : id2IndexMapVector) {

				if (id2IndexMap->find(id) != id2IndexMap->end()) {

					return (*id2IndexMap)[id];

				}

			}

			return 0;

		}

		template<typename T>
		size_t SmartArray<T>::Index2Id(size_t index) {

			for (std::unordered_map<size_t, size_t>*& index2IdMap : index2IdMapVector) {

				if (index2IdMap->find(index) != index2IdMap->end()) {

					return (*index2IdMap)[index];

				}

			}

			return 0;

		}

		template<typename T>
		void SmartArray<T>::Allocate(size_t newFilledCount) {

			size_t newCount = newFilledCount * 2;

			if (newCount != 0) {

				size_t sizeInByte = newCount * sizeof(T);

				size_t oldSizeInByte = count * sizeof(T);

				T* newPData = (T*)malloc(sizeInByte);

				if (pData != nullptr) {

					memcpy(newPData, pData, ([](size_t sizeInByte, size_t oldSizeInByte)->size_t {

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
		void SmartArray<T>::Clear() {

			if (pData != nullptr) {

				free(pData);

				pData = nullptr;

			}

			count = 0;

			filledCount = 0;

			for (std::unordered_map<size_t, size_t>*& id2IndexMap : id2IndexMapVector) {

				id2IndexMap->clear();

				delete id2IndexMap;

			}

			id2IndexMapVector.clear();

			for (std::unordered_map<size_t, size_t>*& index2IdMap : index2IdMapVector) {

				index2IdMap->clear();

				delete index2IdMap;

			}

			index2IdMapVector.clear();
			
		}

		template<typename T>
		void SmartArray<T>::Add(const T& data, size_t id) {

			if (filledCount + 1 > count) {

				Allocate(filledCount + 1);

			}
			else {

				++filledCount;

			}

			size_t index = filledCount - 1;

			pData[index] = data;

			bool isThereAnyId2IndexMapNotFull = false;

			for (std::unordered_map<size_t, size_t>*& id2IndexMap : id2IndexMapVector) {

				if (id2IndexMap->size() < id2IndexMap->max_size()) {

					(*id2IndexMap)[id] = index;

					isThereAnyId2IndexMapNotFull = true;

					break;

				}

			}

			if (!isThereAnyId2IndexMapNotFull) {

				id2IndexMapVector.push_back(new std::unordered_map<size_t, size_t>());

				(*(id2IndexMapVector[id2IndexMapVector.size() - 1]))[id] = index;

			}



			bool isThereAnyIndex2IdMapNotFull = false;

			for (std::unordered_map<size_t, size_t>*& index2IdMap : index2IdMapVector) {

				if (index2IdMap->size() < index2IdMap->max_size()) {

					(*index2IdMap)[index] = id;

					isThereAnyIndex2IdMapNotFull = true;

					break;

				}

			}

			if (!isThereAnyIndex2IdMapNotFull) {

				index2IdMapVector.push_back(new std::unordered_map<size_t, size_t>());

				(*(index2IdMapVector[index2IdMapVector.size() - 1]))[index] = id;

			}

		}

		template<typename T>
		void SmartArray<T>::Erase(size_t id) {

			size_t index = Id2Index(id);

			if (filledCount > 1) {

				if (filledCount - 1 != index) {

					size_t lastComponentId = Index2Id(filledCount - 1);

					pData[index] = pData[filledCount - 1];

					//index2IdMap[index] = lastComponentId;

					for (std::unordered_map<size_t, size_t>*& index2IdMap : index2IdMapVector) {

						if (index2IdMap->find(index) != index2IdMap->end()) {

							(*index2IdMap)[index] = lastComponentId;

							break;

						}

					}

					for (std::unordered_map<size_t, size_t>*& id2IndexMap : id2IndexMapVector) {

						if (id2IndexMap->find(lastComponentId) != id2IndexMap->end()) {

							(*id2IndexMap)[lastComponentId] = index;

							break;

						}

					}

					for (std::unordered_map<size_t, size_t>*& index2IdMap : index2IdMapVector) {

						if (index2IdMap->find(filledCount - 1) != index2IdMap->end()) {

							index2IdMap->erase(filledCount - 1);

							break;

						}

					}

					for (std::unordered_map<size_t, size_t>*& id2IndexMap : id2IndexMapVector) {

						if (id2IndexMap->find(id) != id2IndexMap->end()) {

							id2IndexMap->erase(id);

							break;

						}

					}

					//id2IndexMap[lastComponentId] = index;

					//index2IdMap.erase(filledCount - 1);

					//id2IndexMap.erase(id);

				}
				else {

					for (std::unordered_map<size_t, size_t>*& index2IdMap : index2IdMapVector) {

						if (index2IdMap->find(index) != index2IdMap->end()) {

							index2IdMap->erase(index);

							break;

						}

					}

					for (std::unordered_map<size_t, size_t>*& id2IndexMap : id2IndexMapVector) {

						if (id2IndexMap->find(id) != id2IndexMap->end()) {

							id2IndexMap->erase(id);

							break;

						}

					}

					//index2IdMap.erase(index);

					//id2IndexMap.erase(id);

				}

				--filledCount;

				if (filledCount <= count / 4) {

					Allocate(filledCount);

				}

			}
			else {

				Clear();

			}



			unsigned int index2IdMapVectorSize = index2IdMapVector.size();
			for (unsigned int i = 0; i < index2IdMapVectorSize;) {

				std::unordered_map<size_t, size_t>*& index2IdMap = index2IdMapVector[i];

				if (index2IdMap->size() == 0) {

					index2IdMapVector.erase(index2IdMapVector.begin() + i);

				}
				else {

					++i;

				}

			}



			unsigned int id2IndexMapVectorSize = id2IndexMapVector.size();
			for (unsigned int i = 0; i < id2IndexMapVectorSize;) {

				std::unordered_map<size_t, size_t>*& id2IndexMap = id2IndexMapVector[i];

				if (id2IndexMap->size() == 0) {

					id2IndexMapVector.erase(id2IndexMapVector.begin() + i);

				}
				else {

					++i;

				}

			}

		}

		template<typename T>
		T& SmartArray<T>::Get(size_t id) {

			return pData[Id2Index(id)];

		}

		template<typename T>
		T* SmartArray<T>::GetDataPtr(size_t id) {

			return pData + Id2Index(id);

		}

	}

}