#pragma once

/*
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/*
 *	Include Singleton
 */
#include <ING/Utils/Singleton/Singleton.h>



/*
 *	Include Square
 */
#include "Square/Square.h"



/*
 *	Include Map And String
 */
#include <map>

#include <string>



namespace ING {

	namespace Utils {

		template<class T>
		class ING_API Board : public Singleton<T>
		{

			/*
			 *	Constructors And Destructor
			 */
		public:
			Board() {

			}
			~Board() {

			}



			/*
			 *	Init, Run, Release Methods
			 */
		public:
			virtual bool Init()
			{

				for (std::map<std::string, void*>::iterator square = squareMap.begin(); square != squareMap.end(); ++square)
				{

					if (!((Square*)(square->second))->Init())
					{
						return false;
					}

				}

				return true;
			}

			virtual bool Run() {

				for (std::map<std::string, void*>::iterator square = squareMap.begin(); square != squareMap.end(); ++square)
				{

					if (!((Square*)(square->second))->Run())
					{
						return false;
					}

				}

				return true;
			}

			virtual bool Release()
			{

				for (std::map<std::string, void*>::iterator square = squareMap.begin(); square != squareMap.end(); ++square)
				{

					if (!((Square*)(square->second))->Release())
					{
						return false;
					}

				}

				squareMap.clear();

				return true;
			}



			/*
			 *	Squares
			 */
		private:
			std::map<std::string, void*> squareMap;

		public:
			template<class T>
			void AddSquare()
			{

				T* square = new T();

				if (squareMap.find(typeid(T).name()) != squareMap.end())
				{
					return;
				}

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