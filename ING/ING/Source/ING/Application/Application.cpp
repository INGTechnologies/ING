#include "Application.h"

#include "../Thread/Manager/Manager.h"



namespace ING {


	Application::Application() {

		/*
		 *	Add Squares
		 */
		AddSquare(new Thread::Manager());


	}

	Application::~Application() {



	}


	bool Application::Init() {


		Board<Application>::Init();

		return true;
	}


	bool Application::Run() {


		Board<Application>::Run();

		return true;
	}


	bool Application::Release() {


		Board<Application>::Release();

		return true;
	}


}
