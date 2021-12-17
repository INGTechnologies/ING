#pragma once

#include "../../Singleton/Singleton.h"
#include "../../Board/Square/Square.h"

#include "../Thread.h"


#include <mutex>


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
		 *	Events
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;



		/*
		 *	 
		 */
	private:
		std::mutex mutex;
		
		Thread* mainThread;

	public:
		Thread* GetMainThread() {
			return mainThread;
		}
		Thread* GetCurrentThread();

	};


}