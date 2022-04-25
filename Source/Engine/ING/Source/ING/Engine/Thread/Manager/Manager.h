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



/**
 *	Include Mutex
 */
#include <mutex>



namespace ING {

	class Thread;

	class EngineThread;



	class ING_API EngineThreadManager :
		public Singleton<EngineThreadManager>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		EngineThreadManager();
		~EngineThreadManager();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;



		/**
		 *	Thread Management
		 */
	private:
		EngineThread* renderingThread;
		EngineThread* physicsThread;

		List<EngineThread*> applicationThreadList;

	public:
		EngineThread*					GetRenderingThread	() { return renderingThread; }
		EngineThread*					GetPhysicsThread	() { return physicsThread; }

		List<EngineThread*>&			GetThreadList		() { return applicationThreadList; }



		/**
		 *	StartFrame, EndFrame Method
		 */
	public:
		void StartFrame();
		void EndFrame();



		/**
		 *	Mutex
		 */
	private:
		std::mutex mutex;

	};

}