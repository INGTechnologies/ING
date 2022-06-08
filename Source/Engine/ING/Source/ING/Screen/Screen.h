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

		class ISwapChain;

	}

	class IWindow;

	class C_Camera;



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
		Screen(IWindow* window);
		Screen(IWindow* window, ScreenDesc desc);
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
		bool							isMain;

		ScreenDesc						desc;

		Rendering::ISwapChain*			swapChain;

		IWindow*						window;

		List<C_Camera*>					cameraList;

	public:
		bool							IsMain				() { return isMain; }

		ScreenDesc						GetDesc				() { return desc; }

		Rendering::ISwapChain*			GetSwapChain		() { return swapChain; }

		IWindow*						GetWindow			() { return window; }

		float							GetAspectRatio		();

		float							GetClientHeight		();
		float							GetClientWidth		();



		/**
		 *	Methods
		 */
	public:
		List<C_Camera*>::Node*			AddCamera			(C_Camera* camera);
		void							RemoveCamera		(C_Camera* camera);

	};

}