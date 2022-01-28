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
 *	Include Window Manager
 */
#include <ING/Window/Manager/Manager.h>



/**
 *	Include Windows
 */
#include <Windows.h>



/**
 *	Include WindowDesc
 */
#include <ING/Window/Desc/Desc.h>



namespace ING {

	class Screen;



	class ING_API Window
	{

		/**
		 *	Friend Classes
		 */
	public:
		friend class WindowManager;



		/**
		 *	Constructors And Destructor
		 */
	public:
		Window();
		Window(WindowDesc desc);
		~Window();



		/**
		 *	InitWithDesc, Release Methods
		 */
	private:
		virtual void InitWithDesc(WindowDesc desc);
		
	public:
		virtual void Release();

				void Shutdown();



		/**
		 *	Properties
		 */
	private:
		bool	isMain;
		HWND	handle;
		WindowDesc desc;

		std::wstring classId;

		Screen* screen;

	public:
		bool		IsMain		() { return isMain; }

		HWND		GetHandle	() { return handle; }

		WindowDesc	GetDesc		() { return desc; }

		Screen*		GetScreen	() { return screen; }



		/**
		 *	Events
		 */

	};

}