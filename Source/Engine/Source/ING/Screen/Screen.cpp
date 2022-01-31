
/**
 *	Include Header
 */
#include "Screen.h"



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include SwapChain
 */
#include <ING/Rendering/API/SwapChain/SwapChain.h>



/**
 *	Include Rendering API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>





namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Screen::Screen(Window* window) :
		isMain(false)
	{

		this->window = window;

		ScreenDesc desc;

		InitWithDesc(desc);

	}

	Screen::Screen(Window* window, ScreenDesc desc) :
		isMain(false)
	{

		this->window = window;

		InitWithDesc(desc);

	}

	Screen::~Screen()
	{



	}



	/**
	 *	InitWithDesc, Release Methods
	 */
	void Screen::InitWithDesc(ScreenDesc desc) {

		this->desc = desc;

		if (desc.initSwapChain) {

			/* Create SwapChain */
			Rendering::Device* device = Rendering::APIManager::GetInstance()->GetAPI()->GetDevice();

			swapChain = Rendering::SwapChain::Create(device, window);

			ScreenManager::GetInstance()->InitScreen(this);

		}

	}

	void Screen::Release()
	{

		if(swapChain != nullptr)
			swapChain->Release();

		delete this;

	}

}