#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Singleton
 */
#include <ING/Utils/Singleton/Singleton.h>



/**
 *	Include Square
 */
#include "Square/Square.h"



/**
 *	Include Map And String
 */
#include <map>

#include <string>



/**
 *	Include Vector
 */
#include <vector>



namespace ING {

	namespace Utils {

		template<class T>
		class Board : public Singleton<T>
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Board() {

			}
			~Board() {

			}



			/**
			 *	Init, Run, Release Methods
			 */
		public:
			virtual bool Init()
			{

				for (auto& item : squareVector) {

					if (!(item->Init()))
					{
						return false;
					}

				}

				return true;
			}

			virtual bool Run() {

				for (auto& item : squareVector) {

					if (!(item->Run()))
					{
						return false;
					}

				}

				return true;
			}

			virtual bool Release()
			{

				int squareCount = squareVector.size();

				for (int i = squareCount - 1; i >= 0; --i) {

					Square* square = squareVector[i];

					if (!(square->Release()))
					{
						return false;
					}

					int a = 5;
				}



				squareMap.clear();

				squareVector.clear();



				delete this;

				return true;
			}



			/**
			 *	Squares
			 */
		private:
			std::map<std::string, Square*>	squareMap;
			std::vector<Square*>			squareVector;

		public:
			template<class T>
			void AddSquare()
			{

				T* square = new T();

				if (squareMap.find(typeid(T).name()) != squareMap.end())
				{
					return;
				}

				squareVector.push_back(square);

				squareMap[typeid(T).name()] = square;

			}

			template<class T>
			T* GetSquare()
			{
				if (squareMap.find(typeid(T).name()) == squareMap.end())
				{
					return nullptr;
				}

				return squareMap[typeid(T).name()];
			}


		};


	}

}