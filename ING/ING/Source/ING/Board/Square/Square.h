#pragma once

#include "../../Singleton/Singleton.h"



class Square {

	/*
	 *	Constructors And Destructor
	 */
public:
	Square() {

	}

	~Square() {

	}



	/*
	 *	Events 
	 */
public:
	virtual bool Init() {

		return true;
	}

	virtual bool Run() {

		return true;
	}

	virtual bool Release() {

		return true;
	}


};

