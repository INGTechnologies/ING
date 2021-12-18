#pragma once

#include <ING/EntryPoint/EntryPoint.h>

#include <ING\Utils/Utils.h>

using namespace ING::Utils;




#include <ING/Utils/Singleton/Singleton.h>
#include <ING/Utils/Board/Board.h>



namespace ING {

	class ING_API Application: public Board<Application> {	

		/*
		 *	Constructors And Destructor
		 */
	public:
		Application();
		~Application();



		/*
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;

	};

}