#pragma once


#include "../Singleton/Singleton.h"

#include "../Window/Window.h"

#include "../Board/Board.h"

namespace ING {

	class Application: public Board<Application> {

		/*
		 *	Constructors And Destructor
		 */
	public:
		Application();
		~Application();



		/*
		 *	Events
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;

	};

}