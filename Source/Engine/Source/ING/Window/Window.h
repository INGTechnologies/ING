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
	private:
		Window();

	public:
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
		bool		isMain;
		HWND		handle;
		WindowDesc	desc;

		ui16		classId;

		Screen*		screen;

	public:
		bool		IsMain		() { return isMain; }

		HWND		GetHandle	() { return handle; }

		WindowDesc	GetDesc		() { return desc; }

		Screen*		GetScreen	() { return screen; }



		/**
		 *	Methods
		 */
	public:
		void			Show();

		void			Hide();


		/* Title */
		void			SetTitle(std::wstring title);

		void			SetTitle(const wchar_t* title) {

			SetTitle(WString(title));

		}

		std::wstring	GetTitle();

	};

}