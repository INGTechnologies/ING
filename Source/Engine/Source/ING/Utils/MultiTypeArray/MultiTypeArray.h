#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Vector
 */
#include <vector>



 /**
  *	Include String
  */
#include <string>



/**
 *	Include Auto
 */
#include <ING/Utils/Auto/Auto.h>



/**
 *	Include Auto
 */
#include <ING/Utils/Types.h>



namespace ING {

	namespace Utils {

		class MultiTypeArray {

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

							vector[i].~Auto();

						}

						vector.resize(size);



						mSize = size;
						return;

					}
					else if (size > mSize) {

						vector.resize(size);

						for (ui64 i = mSize; i < size; ++i) {

							vector[i] = Auto();

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
			std::vector<Auto> vector;



			/**
			 *	Clear Method
			 */
		public:
			void Clear() {

				if (GetSize() != 0) {

					for (ui64 i = 0; i < mSize; ++i) {

						vector[i].~Auto();

					}

					vector.clear();

					mSize = 0;

				}

			}



			/**
			 *	Operators
			 */
		public:
			Auto& operator[](ui64 index) {

				return vector[index];

			}



			/**
			 *	Ref Class
			 */
		public:
			class Ref {

				/**
				 *	Constructors And Destructor
				 */
			public:
				Ref() {

					arrayPtr = nullptr;

				}

				Ref(MultiTypeArray* arrayPtr) {

					this->arrayPtr = arrayPtr;

				}

				~Ref() {

					if (this->arrayPtr != nullptr) {

						this->arrayPtr->Clear();

					}

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
				Auto& operator[](ui64 index) {

					return (*arrayPtr)[index];

				}

				Ref& operator=(MultiTypeArray* arrayPtr) {

					this->arrayPtr = arrayPtr;

					return *this;

				}

			};

		};

	}

}