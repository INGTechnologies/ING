#pragma once


#include <ING/Utils/Utils.h>

using namespace ING::Utils;



#include <ING/Utils/Singleton/Singleton.h>
#include <ING/Utils/Board/Square/Square.h>
#include <ING/Utils/IdGenerator/IdGenerator.h>

#include "../Thread.h"



#include <mutex>
#include <map>


namespace ING {


	class Thread::Manager :
		public Singleton<Manager>,
		public Square
	{

		/*
		 *	Constructors And Destructor
		 */
	public:
		Manager();
		~Manager();



		/*
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;

	};


}