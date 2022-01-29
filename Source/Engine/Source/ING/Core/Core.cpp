
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



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Core::Core() {

		/**
		 *	Add Squares
		 */
		/* Memory */
		AddSquare<Memory>();

	}

	Core::~Core() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool Core::Init() {



		return Board<Core>::Init();
	}

	bool Core::Run() {



		return Board<Core>::Run();
	}

	bool Core::Release() {



		return Board<Core>::Release();
	
	}


}
