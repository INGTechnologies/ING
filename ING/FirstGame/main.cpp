#include <iostream>

#include <ING/Application/Application.h>




int main() {


	ING::Application app;


	if (!app.Init()) {

		return 1;
	
	}

	if (!app.Run()) {

		return 1;

	}



	system("pause");

	return 0;
}