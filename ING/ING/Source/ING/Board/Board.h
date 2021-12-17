#pragma once

#include <map>
#include <string>

#include "../Singleton/Singleton.h"

#include "Square/Square.h"

template<class T>
class Board: public Singleton<T>
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
	 *	Events
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
	void AddSquare(T* square) 
	{

		if (squareMap.find(typeid(T).name()) == squareMap.end()) 
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

