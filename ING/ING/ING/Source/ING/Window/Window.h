#pragma once

/*
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/*
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	class ING_API Window
	{

		/*
		 *	Constructors And Destructor
		 */
	public:
		Window();
		~Window();



		/*
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init();
		virtual bool Run();
		virtual bool Release();

	};


}