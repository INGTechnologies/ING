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
			T*												pData;
			unsigned long									filledCount;
			unsigned long									count;

			std::vector < std::unordered_map<unsigned long, unsigned long>* >	id2IndexMapVector;
			std::vector < std::unordered_map<unsigned long, unsigned long>* >	index2IdMapVector;

		public:
			T*												GetPData		() { return pData; }

			unsigned long									GetCount		() { return count; }

			unsigned long									GetFilledCount	() { return filledCount; }

			std::vector < std::unordered_map<unsigned long, unsigned long>* > & GetId2IndexMapVector	() { return id2IndexMapVector; }
			std::vector < std::unordered_map<unsigned long, unsigned long>* > & GetIndex2IdMapVector	() { return index2IdMapVector; }



			/**
			 *	Methods
			 */
		private:
			void Allocate(unsigned long newFilledCount);

		public:
			unsigned long Id2Index(unsigned long id);
			unsigned long Index2Id(unsigned long index);

		public:
			void Clear();
			void Add(T& data, unsigned long id);
			void Erase(unsigned long id);
			T&	 Get(unsigned long id);
			T*	 GetDataPtr(unsigned long id);

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
		unsigned long SmartArray<T>::Id2Index(unsigned long id) {

			for (std::unordered_map<unsigned long, unsigned long>*& id2IndexMap : id2IndexMapVector) {

				if (id2IndexMap->find(id) != id2IndexMap->end()) {

					return (*id2IndexMap)[id];

				}

			}

			return 0;

		}

		template<typename T>
		unsigned long SmartArray<T>::Index2Id(unsigned long index) {

			for (std::unordered_map<unsigned long, unsigned long>*& index2IdMap : index2IdMapVector) {

				if (index2IdMap->find(index) != index2IdMap->end()) {

					return (*index2IdMap)[index];

				}

			}

			return 0;

		}

		template<typename T>
		void SmartArray<T>::Allocate(unsigned long newFilledCount) {

			unsigned long newCount = newFilledCount * 2;

			if (newCount != 0) {

				unsigned long sizeInByte = newCount * sizeof(T);

				unsigned long oldSizeInByte = count * sizeof(T);

				T* newPData = (T*)malloc(sizeInByte);

				if (pData != nullptr) {

					memcpy(newPData, pData, ([](unsigned long sizeInByte, unsigned long oldSizeInByte)->unsigned long {

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

			for (std::unordered_map<unsigned long, unsigned long>*& id2IndexMap : id2IndexMapVector) {

				id2IndexMap->clear();

				delete id2IndexMap;

			}

			for (std::unordered_map<unsigned long, unsigned long>*& index2IdMap : index2IdMapVector) {

				index2IdMap->clear();

				delete index2IdMap;

			}
			
		}

		template<typename T>
		void SmartArray<T>::Add(T& data, unsigned long id) {

			if (filledCount + 1 > count) {

				Allocate(filledCount + 1);

			}
			else {

				++filledCount;

			}

			unsigned long index = filledCount - 1;

			pData[index] = data;

			bool isThereAnyId2IndexMapNotFull = false;

			for (std::unordered_map<unsigned long, unsigned long>*& id2IndexMap : id2IndexMapVector) {

				if (id2IndexMap->size() < id2IndexMap->max_size()) {

					(*id2IndexMap)[id] = index;

					isThereAnyId2IndexMapNotFull = true;

					break;

				}

			}

			if (!isThereAnyId2IndexMapNotFull) {

				id2IndexMapVector.push_back(new std::unordered_map<unsigned long, unsigned long>());

				(*(id2IndexMapVector[id2IndexMapVector.size() - 1]))[id] = index;

			}



			bool isThereAnyIndex2IdMapNotFull = false;

			for (std::unordered_map<unsigned long, unsigned long>*& index2IdMap : index2IdMapVector) {

				if (index2IdMap->size() < index2IdMap->max_size()) {

					(*index2IdMap)[index] = id;

					isThereAnyIndex2IdMapNotFull = true;

					break;

				}

			}

			if (!isThereAnyIndex2IdMapNotFull) {

				index2IdMapVector.push_back(new std::unordered_map<unsigned long, unsigned long>());

				(*(index2IdMapVector[index2IdMapVector.size() - 1]))[index] = id;

			}

		}

		template<typename T>
		void SmartArray<T>::Erase(unsigned long id) {

			unsigned long index = Id2Index(id);

			if (filledCount > 1) {

				if (filledCount - 1 != index) {

					unsigned long lastComponentId = Index2Id(filledCount - 1);

					pData[index] = pData[filledCount - 1];

					//index2IdMap[index] = lastComponentId;

					for (std::unordered_map<unsigned long, unsigned long>*& index2IdMap : index2IdMapVector) {

						if (index2IdMap->find(index) != index2IdMap->end()) {

							(*index2IdMap)[index] = lastComponentId;

							break;

						}

					}

					for (std::unordered_map<unsigned long, unsigned long>*& id2IndexMap : id2IndexMapVector) {

						if (id2IndexMap->find(lastComponentId) != id2IndexMap->end()) {

							(*id2IndexMap)[lastComponentId] = index;

							break;

						}

					}

					for (std::unordered_map<unsigned long, unsigned long>*& index2IdMap : index2IdMapVector) {

						if (index2IdMap->find(filledCount - 1) != index2IdMap->end()) {

							index2IdMap->erase(filledCount - 1);

							break;

						}

					}

					for (std::unordered_map<unsigned long, unsigned long>*& id2IndexMap : id2IndexMapVector) {

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

					for (std::unordered_map<unsigned long, unsigned long>*& index2IdMap : index2IdMapVector) {

						if (index2IdMap->find(index) != index2IdMap->end()) {

							index2IdMap->erase(index);

							break;

						}

					}

					for (std::unordered_map<unsigned long, unsigned long>*& id2IndexMap : id2IndexMapVector) {

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
			for (unsigned int i = 0; i < index2IdMapVectorSize; ++i) {

				std::unordered_map<unsigned long, unsigned long>*& index2IdMap = index2IdMapVector[i];

				if (index2IdMap->size() == 0) {

					index2IdMapVector.erase(index2IdMapVector.begin() + i);

				}

			}



			unsigned int id2IndexMapVectorSize = id2IndexMapVector.size();
			for (unsigned int i = 0; i < id2IndexMapVectorSize; ++i) {

				std::unordered_map<unsigned long, unsigned long>*& id2IndexMap = id2IndexMapVector[i];

				if (id2IndexMap->size() == 0) {

					id2IndexMapVector.erase(id2IndexMapVector.begin() + i);

				}

			}

		}

		template<typename T>
		T& SmartArray<T>::Get(unsigned long id) {

			return pData[Id2Index(id)];

		}

		template<typename T>
		T* SmartArray<T>::GetDataPtr(unsigned long id) {

			return pData + Id2Index(id);

		}

	}

}