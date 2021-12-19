#pragma once

#include <ING\EntryPoint\EntryPoint.h>



#include <ING\Utils/Utils.h>

using namespace ING::Utils;



#include <ING/Utils/Singleton/Singleton.h>
#include <ING/Utils/Board/Square/Square.h>
#include <ING/Utils/IdGenerator/IdGenerator.h>



namespace ING {

	class ING_API ApplicationEventManager :
		public Singleton<ApplicationEventManager>,
		public Square
	{

		/*
		 *	Constructors And Destructor
		 */
	public:
		ApplicationEventManager();
		~ApplicationEventManager();



		/*
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;

	};

}