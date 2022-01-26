
/**
 *	Include IOStream
 */
#include <iostream>



/**
 *	Include Application
 */
#include <ING\Application\Application.h>



int main() {



	ING::Application::CreateInstance();
	
	ING::Application::GetInstance()->Init();

	ING::Application::GetInstance()->Run();



	system("pause");
	return 0;
}