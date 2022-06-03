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



		/**
		 *	Interface Class
		 */
		class IFMap {

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
		template<typename TId, typename T>
		class FMap : public IFMap
		{

			/**
			 *	Iterator
			 */
		public:
			struct Iterator {

				/**
				 *	Constructors And Destructor
				 */
			public:
				Iterator(size_t index, T* firstElementPData) {

					this->index = index;
					this->firstElementPData = firstElementPData;

				}

				~Iterator() {



				}



				/**
				 *	Properties
				 */
			public:
				size_t index;
				T* firstElementPData;



				/**
				 *	Operaters
				 */
			public:
				T&		operator *  () {

					return firstElementPData[index];

				}

				void	operator ++ () {

					++index;

				}

				bool	operator != (const Iterator& a) {

					return a.index != index || a.firstElementPData != firstElementPData;

				}

			};



			/**
			 *	Constructors And Destructor
			 */
		public:
			FMap() {

				count		= 0;
				filledCount = 0;
				pData		= nullptr;

			}

			~FMap() {

				Clear();

			}



			/**
			 *	Properties
			 */
		private:
			T*										pData;
			size_t									filledCount;
			size_t									count;

			std::unordered_map<TId, size_t>			id2IndexMap;
			std::unordered_map<size_t, TId>			index2IdMap;

		public:
			T*										GetPData		() { return pData; }

			size_t									GetCount		() { return count; }

			size_t									GetFilledCount	() { return filledCount; }

			std::unordered_map<TId, size_t>&		GetId2IndexMap	() { return id2IndexMap; }
			std::unordered_map<size_t, TId>&		GetIndex2IdMap	() { return index2IdMap; }



			/**
			 *	Methods
			 */
		private:
			void		Allocate	(size_t newFilledCount);

		public:
			size_t		Id2Index	(TId id) { return id2IndexMap[id]; }
			size_t		Index2Id	(size_t index) { return index2IdMap[index]; }

			Iterator	begin		() const { return Iterator(0, pData); }
			Iterator	end			() const { return Iterator(filledCount, pData); }

			void		Clear		();
			void		Add			(const T& data, TId id);
			void		Erase		(TId id);
			T&			Get			(TId id);
			T&			GetByIndex	(size_t index);
			T*			GetDataPtr	(TId id);

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
		template<typename TId, typename T>
		void FMap<TId, T>::Allocate(size_t newFilledCount) {

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

		template<typename TId, typename T>
		void FMap<TId, T>::Clear() {

			if (pData != nullptr) {

				free(pData);

				pData = nullptr;

			}

			count = 0;

			filledCount = 0;

			id2IndexMap.clear();

			index2IdMap.clear();
			
		}

		template<typename TId, typename T>
		void FMap<TId, T>::Add(const T& data, TId id) {

			if (filledCount + 1 > count) {

				Allocate(filledCount + 1);

			}
			else {

				++filledCount;

			}

			size_t index = filledCount - 1;

			memcpy(pData + index, &data, sizeof(T));

			index2IdMap[index] = id;
			id2IndexMap[id] = index;

		}

		template<typename TId, typename T>
		void FMap<TId, T>::Erase(TId id) {

			size_t index = Id2Index(id);

			if (filledCount > 1) {

				if (filledCount - 1 != index) {

					size_t lastComponentId = Index2Id(filledCount - 1);

					memcpy(pData + index, pData + filledCount - 1, sizeof(T));

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

				Clear();

			}

		}

		template<typename TId, typename T>
		T& FMap<TId, T>::Get(TId id) {

			return pData[Id2Index(id)];

		}

		template<typename TId, typename T>
		T& FMap<TId, T>::GetByIndex(size_t index) {

			return pData[index];

		}

		template<typename TId, typename T>
		T* FMap<TId, T>::GetDataPtr(TId id) {

			return pData + Id2Index(id);

		}

	}

}