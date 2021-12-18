#pragma once

#include <ING/EntryPoint/EntryPoint.h>




#include <ING/Utils/Utils.h>

using namespace ING::Utils;



#include <ING/Utils/Singleton/Singleton.h>
#include <ING/Utils/Board/Square/Square.h>
#include <ING/Utils/IdGenerator/IdGenerator.h>

#include <ING/Threading/Thread.h>



#include <mutex>
#include <map>


namespace ING {


	class ING_API Thread::Manager :
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



		/*
		 *	 Properties
		 */
	private:
		std::mutex mutex;

		std::map<uint32_t, Thread*> threadMap;

	public:
		Thread* GetMainThread() {
			return threadMap[0];
		}
		Thread* GetCurrentThread();



		/*
		 *	Id Generator	
		 */
	private:
		IdGenerator idGenerator;





	};


}