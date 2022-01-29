#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include ScreenDesc
 */
#include <ING/Screen/Desc/Desc.h>



/**
 *	Include ScreenManager
 */
#include <ING/Screen/Manager/Manager.h>



namespace ING {

	namespace Rendering {

		class SwapChain;

	}

	class Window;



	class ING_API Screen
	{

		/**
		 *	Friend Classes
		 */
	public:
		friend class ScreenManager;



		/**
		 *	Constructors And Destructor
		 */
	public:
		Screen(Window* window);
		Screen(Window* window, ScreenDesc desc);
		~Screen();



		/**
		 *	InitWithDesc, Release Methods
		 */
	private:
		virtual void InitWithDesc(ScreenDesc desc);

	public:
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		bool					isMain;

		ScreenDesc				desc;

		Rendering::SwapChain*	swapChain;

		Window*					window;

	public:
		bool							IsMain				() { return isMain; }

		ScreenDesc						GetDesc				() { return desc; }

		Rendering::SwapChain*			GetSwapChain		() { return swapChain; }

		Window*							GetWindow			() { return window; }

	};

}