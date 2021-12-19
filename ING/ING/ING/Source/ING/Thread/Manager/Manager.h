#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Mutex, Map
 */
#include <mutex>
#include <map>



namespace ING {


	class ING_API ThreadManager :
		public Singleton<ThreadManager>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ThreadManager();
		~ThreadManager();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;

	};


}