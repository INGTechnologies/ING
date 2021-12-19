#pragma once

#include <ING/EntryPoint/EntryPoint.h>



#include <ING/Utils/Utils.h>

using namespace ING::Utils;



#include <ING/Utils/Singleton/Singleton.h>
#include <ING/Utils/Board/Square/Square.h>
#include <ING/Utils/IdGenerator/IdGenerator.h>



#include <mutex>
#include <map>



namespace ING {


	class ING_API EventManager :
		public Singleton<EventManager>,
		public Square
	{

		/*
		 *	Constructors And Destructor
		 */
	public:
		EventManager();
		~EventManager();



		/*
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;

	};


}