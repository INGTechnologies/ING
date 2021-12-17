#pragma once


#include "../Singleton/Singleton.h"




namespace ING {

	class Application: public Singleton<Application> {
	public:
		Application();
		~Application();

	};

}