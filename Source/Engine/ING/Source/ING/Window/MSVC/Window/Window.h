#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>

#ifdef USE_MSVC


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
 *	Include Map
 */
#include <map>



/**
 *	Include WindowDesc
 */
#include <ING/Window/Desc/Desc.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>




/**
 *	Include EventStorage
 */
#include <ING/Event/Storage/Storage.h>



namespace ING {

	class Screen;

	class Event;

	class WindowEvent;



	namespace MSVC {

		class ING_API Window :
			public IWindow
		{

			/**
			 *	Friend Class
			 */
		public:
			friend class IWindow;



			/**
			 *	WndProc
			 */
		public:
			static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);



			/**
			 *	Constructors And Destructor
			 */
		protected:
			Window();
			Window(const WindowDesc& desc);
			~Window();



			/**
			 *	InitWithDesc, InitEvents, Release Methods
			 */
		protected:
			virtual void	InitWithDesc(const WindowDesc& desc) override;

		public:
			virtual void	Release() override;



			/**
			 *	Properties
			 */
		private:
			bool isHandleDestroyed;



			/**
			 *	Methods
			 */
		public:
			virtual void	Show() override;

			virtual void	Hide() override;

			virtual void	Focus() override;


			/* Title */
			virtual void	SetTitle(const WString& title) override;


			/* Icon */
			virtual void	SetIconFromFile(const WString& path) override;


			/* Style */
			virtual unsigned int GetStyle() override;
			virtual void	SetStyle(unsigned int styleFlag) override;

		};

	}

}

#endif