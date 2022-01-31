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

	class ApplicationThread;



	class ING_API ApplicationThreadManager :
		public Singleton<ApplicationThreadManager>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ApplicationThreadManager();
		~ApplicationThreadManager();



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
		ApplicationThread* renderingThread;
		ApplicationThread* physicsThread;

		List<ApplicationThread*> applicationThreadList;

	public:
		ApplicationThread*					GetRenderingThread () { return renderingThread; }
		ApplicationThread*					GetPhysicsThread () { return physicsThread; }

		List<ApplicationThread*>::Node*		AddThread(ApplicationThread* thread);
		void								RemoveThread(List<ApplicationThread*>::Node* node);



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