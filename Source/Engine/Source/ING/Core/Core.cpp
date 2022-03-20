
/**
 *	Include Header
 */
#include "Core.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Memory
 */
#include <ING/Core/Memory/Memory.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Core::Core() {

		Debug::Log("Start Creating Core");

		/**
		 *	Add Squares
		 */
		/* Memory */
		AddSquare<Memory>();

		Debug::Log("Core Created");

	}

	Core::~Core() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool Core::Init() {

		Debug::Log("Start Initializing Core");

		bool result = Board<Core>::Init();
	
		if (result)
			Debug::Log("Core Initialized");
		else {

			Debug::Log("Cant Init Core");

		}

		return result;
	}

	bool Core::Run() {

		Debug::Log("Start Running Core");

		return Board<Core>::Run();
	}

	bool Core::Release() {

		Debug::Log("Start Releasing Core");

		bool result = Board<Core>::Release();

		if (result)
			Debug::Log("Finished Releasing Core");
		else {

			Debug::Log("Cant Release Core");

		}

		return result;
	
	}


}
