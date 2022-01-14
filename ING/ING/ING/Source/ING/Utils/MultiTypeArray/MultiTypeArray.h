#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Vector
 */
#include <vector>



namespace ING {

	namespace Utils {

		class MultiTypeArray {

			/**
			 *	 Nested Classes, Structs
			 */
		public:
			/**
			 *	 Element Struct
			 */
			struct Element {

			public:
				Element() {

					typeName = "null";

					pData = nullptr;

				}
				~Element() {



				}

			private:
				void* pData;

			public:
				void* GetPData() { return pData; }

			public:
				template<typename T>
				void operator = (T next) {

					DeleteData();



					typeName = typeid(T).name();



					pData = malloc(sizeof(T));

					memcpy(pData, &next, sizeof(T));

				}

				template<typename T>
				T& As() {

					return *((T*)pData);
				}

				void DeleteData() {

					if (pData != nullptr) {

						free(pData);

					}

				}

			private:
				std::string typeName;

			public:
				std::string& GetTypeName() {
					return typeName;
				}

			};



			/**
			 *	Constructors And Destructor
			 */
		public:
			MultiTypeArray(ui64 size) {
				mSize = 0;
				Resize(size);

			}
			MultiTypeArray(int size) {
				mSize = 0;
				Resize(size);

			}
			MultiTypeArray() :
				MultiTypeArray(0)
			{

			}
			~MultiTypeArray() {

				Clear();

			}



			/**
			 *	Size
			 */
		private:
			ui64 mSize;

		public:
			ui64 GetSize() { return mSize; }

			void Resize(ui64 size) {

				if (size == mSize) return;

				if (size != 0) {

					if (size < mSize) {

						for (ui64 i = size; i < mSize; ++i) {

							if (vector[i].GetPData() != nullptr)
								vector[i].DeleteData();

						}

						vector.resize(size);



						mSize = size;
						return;

					}
					else if (size > mSize) {

						vector.resize(size);

						for (ui64 i = mSize; i < size; ++i) {

							vector[i] = Element();

						}



						mSize = size;
						return;

					}

				}
				else {
					Clear();



					mSize = size;
					return;
				}

			}



			/**
			 *	vector
			 */
		private:
			std::vector<Element> vector;



			/**
			 *	Clear Method
			 */
		public:
			void Clear() {

				if (GetSize() != 0) {

					for (ui64 i = 0; i < mSize; ++i) {

						if (vector[i].GetPData() != nullptr)
							free(vector[i].GetPData());

					}

					vector.clear();

					mSize = 0;

				}

			}



			/**
			 *	Operators
			 */
		public:
			Element& operator[](ui64 index) {

				return vector[index];

			}



		public:
			/**
			 *	Ref Class
			 */
			class Ref {

				/**
				 *	Constructors And Destructor
				 */
			public:
				Ref(MultiTypeArray* arrayPtr) {
					this->arrayPtr = arrayPtr;
				}
				~Ref() {

					this->arrayPtr->Clear();

				}



				/**
				 *	Array Pointer
				 */
			private:
				MultiTypeArray* arrayPtr;

			public:
				MultiTypeArray* GetArrayPtr() {
					return arrayPtr;
				}



				/**
				 *	Basic Methods
				 */
			public:
				ui64 GetSize() { return arrayPtr->GetSize(); }

				void Resize(ui64 size) {
				
					arrayPtr->Resize(size);
				
				};

				void Clear() {

					arrayPtr->Clear();

				}



				/**
				 *	Operators
				 */
			public:
				Element& operator[](ui64 index) {

					return (*arrayPtr)[index];

				}

			};

		};

	}

}