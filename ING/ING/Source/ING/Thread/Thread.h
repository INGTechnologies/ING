#pragma once


#include <thread>
#include <mutex>


namespace ING {


	class Thread
	{

		/*
		 *	Child Classes
		 */
	public:
		class Manager;
		friend class Manager;
	


		/*
		 *	Constructors And Destructor
		 */
	public:
		Thread();
		~Thread();


	private:
		std::mutex mutex;
		std::thread llthread;
		uint32_t id;

	public:
		void Start();
		void Join();
		void Release();


	};

}