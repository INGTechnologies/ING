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
 *	Include Mutex, Map, UnorderedMap
 */
#include <mutex>
#include <map>
#include <unordered_map>



namespace ING {

	class Thread;

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



		/**
		 *	Thread Management
		 */
	private:
		std::unordered_map<unsigned int, Thread*>			threadMap;
		std::unordered_map<std::thread::id, unsigned int>	threadIdMap;
		IdGenerator											threadIdGenerator;
		std::mutex											mutex;

	public:
		void	RegisterThread(Thread* thread);
		void	UnregisterThread(Thread* thread);
		Thread* ThisThread();

	};


}