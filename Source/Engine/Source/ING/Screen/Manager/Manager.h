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



namespace ING {

	class Screen;

	class ING_API ScreenManager :
		public Singleton<ScreenManager>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ScreenManager();
		~ScreenManager();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init();
		virtual bool Run();
		virtual bool Release();



		/**
		 *	Window Management
		 */
	private:
		Screen* mainScreen;

	public:
		Screen* GetMainScreen() { return mainScreen; }

		void InitScreen(Screen* screen);

	};

}