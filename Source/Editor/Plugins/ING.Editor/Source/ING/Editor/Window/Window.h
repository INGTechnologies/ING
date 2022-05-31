#pragma once

/**
 *	Include Editor Entry Point
 */
#include <ING/Editor/EntryPoint/EntryPoint.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include IOStream
 */
#include <iostream>



/**
 *	Include Window Desc
 */
#include <ING/Editor/Window/Desc/Desc.h>



namespace ING {

	class IWindow;

	namespace UI {

		class C_Canvas;

	}



	namespace Editor {

		class Layout;



		class PLUGIN_API(ING_EDITOR) Window
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Window	(const WindowDesc & desc);
			~Window	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			IWindow*		ingWindow;

			String			name;

			UI::C_Canvas*	canvas;

			Layout*			layout;

		public:
			IWindow*		GetINGWindow()	{ return ingWindow; }

			const String&	GetName		()	{ return name; }

			UI::C_Canvas*	GetCanvas	()	{ return canvas; }

			Layout*			GetLayout	()  { return layout; }
			void			SetLayout	(Layout* layout);
			void			SetLayout	(const String& layoutName);

		};

	}

}