
/**
 *	Include Header
 */
#include "Coder.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Coder::Coder() {



	}

	Coder::~Coder() {



	}



	/**
	 *	Release Method
	 */
	void Coder::Release() {

		delete this;

	}



	/**
	 *	Encode, Decode, Check Methods
	 */
	WString	Coder::Encode(const WString& content, const WString& key) {

		WString result = content;



		return result;

	}

	WString	Coder::Decode(const WString& content, const WString& key) {

		WString result = content;



		return result;

	}

	bool			Coder::Check(const WString& content, const WString& key) {

		bool result = false;



		return result;

	}

}