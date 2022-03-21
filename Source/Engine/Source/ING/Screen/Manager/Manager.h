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
		 *	Properties
		 */
	private:
		Screen*			mainScreen;

		List<Screen*>	screenList;

	public:
		Screen*			GetMainScreen() { return mainScreen; }



		/**
		 *	Methods
		 */
	public:
		void			InitScreen(Screen* screen);

	};

}