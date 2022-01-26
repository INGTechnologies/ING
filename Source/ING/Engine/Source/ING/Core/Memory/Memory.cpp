
/**
 *	Include Header
 */
#include "Memory.h"



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Memory::Memory() {



	}

	Memory::~Memory() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool Memory::Init() {



		return Square::Init();
	}

	bool Memory::Run() {



		return Square::Run();
	}

	bool Memory::Release() {



		return Square::Release();
	}



	/**
	 *	Allocate, Deallocate Methods
	 */
	void* Memory::Allocate(ui64 size) {

#ifdef _DEBUG

		/*  */

#endif

		return malloc(size);
	}

	void Memory::Deallocate(void* ptr) {

#ifdef _DEBUG

		/*  */

#endif

		free(ptr);
	}
}
