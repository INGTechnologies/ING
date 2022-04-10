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

	class Window;

	class Camera;



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
		bool							isMain;

		ScreenDesc						desc;

		Rendering::ISwapChain*			swapChain;

		Window*							window;

		List<Camera*>					cameraList;

	public:
		bool							IsMain				() { return isMain; }

		ScreenDesc						GetDesc				() { return desc; }

		Rendering::ISwapChain*			GetSwapChain		() { return swapChain; }

		Window*							GetWindow			() { return window; }

		float							GetAspectRatio		();

		float							GetClientHeight		();
		float							GetClientWidth		();



		/**
		 *	Methods
		 */
	public:
		List<Camera*>::Node*			AddCamera			(Camera* camera);
		void							RemoveCamera		(Camera* camera);

	};

}