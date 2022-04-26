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


	class ING_API EventManager :
		public Singleton<EventManager>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		EventManager();
		~EventManager();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;

	};


}