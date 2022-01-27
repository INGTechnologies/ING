
/**
 *	Include Header
 */
#include "Screen.h"



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;





namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Screen::Screen() :
		isMain(false)
	{

		ScreenDesc desc;

		InitWithDesc(desc);

	}

	Screen::Screen(ScreenDesc desc) :
		isMain(false)
	{

		InitWithDesc(desc);

	}

	Screen::~Screen()
	{



	}



	/**
	 *	InitWithDesc, Release Methods
	 */
	void Screen::InitWithDesc(ScreenDesc desc) {

		ScreenManager::GetInstance()->InitScreen(this);

	}

	void Screen::Release()
	{

		delete this;

	}

}