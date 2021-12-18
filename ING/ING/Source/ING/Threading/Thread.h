#pragma once

#include <ING/EntryPoint/EntryPoint.h>

#include <ING/Utils/Utils.h>

using namespace ING::Utils;


#include <thread>
#include <mutex>


namespace ING {


	class ING_API Thread
	{

		/*
		 *	Classes And Types
		 */
	public:
		class Manager;
		friend class Manager;

		typedef void (*FunctionPointer)(Thread*);
	


		/*
		 *	Constructors And Destructor
		 */
	public:
		Thread();
		Thread(FunctionPointer functionPtr);

		~Thread();



		/*
		 *	Properties
		 */
	private:
		std::mutex mutex;
		std::thread llthread;
		uint32_t id;
		FunctionPointer functionPtr;

	public:
		uint32_t& GetId() { return id; }
		FunctionPointer GetFunctionPtr() { return functionPtr; }
		std::thread& GetLLThread() { return llthread; }



		/*
		 *	Init, Run, Release Methods
		 */
	public:
		void Start();
		void Join();
		void Terminate();
		void Release();


	};

}