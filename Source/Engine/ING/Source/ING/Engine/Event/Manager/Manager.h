#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	class ING_API EngineEventManager :
		public Singleton<EngineEventManager>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		EngineEventManager();
		~EngineEventManager();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;

	};

}