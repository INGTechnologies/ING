#include <iostream>


#include <ING/Application/Application.h>


#include <ING/Thread/Thread.h>

#include <ING/Thread/Manager/Manager.h>


#include <ING/Event/Manager/Manager.h>



#include <ING/Rendering/Rendering.h>

using namespace ING::Rendering;



#include <ING/Utils/Utils.h>

using namespace ING::Utils;



using namespace ING;



int main() {

	
	ING_CREATE_APPLICATION

	ING_INIT_APPLICATION

	ING_RUN_APPLICATION
	


	system("pause");
	return 0;
}