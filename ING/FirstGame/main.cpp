#include <iostream>


#include <ING/Application/Application.h>

/*
#include <ING/Threading/Thread.h>
#include <ING/Threading/Manager/Manager.h>



#include <ING/Rendering/Rendering.h>

using namespace ING::Rendering;



#include <ING/Utils/Utils.h>

using namespace ING::Utils;



using namespace ING;
*/


int main() {

	IMPLEMENT_SINGLETON(ING::Application);

	/*

	ING::Application* app = ING::Application::GetInstance();

	if (!app->Init()) {

		return 1;
	
	}

	if (!app->Run()) {

		return 1;

	}
	*/


	system("pause");

	return 0;
}