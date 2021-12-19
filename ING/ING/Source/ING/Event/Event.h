#pragma once

#include <ING\EntryPoint\EntryPoint.h>



#include <ING/Utils/Utils.h>

using namespace ING::Utils;





namespace ING {

	class ING_API Event {

		/*
		 *	Constructors And Destructor
		 */
	public:
		class Manager;
		friend class Manager;



		/*
		 *	Constructors And Destructor
		 */
	public:
		Event();
		~Event();

	};


}