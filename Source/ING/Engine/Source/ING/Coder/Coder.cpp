
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
	std::wstring	Coder::Encode(std::wstring content, std::wstring key) {

		std::wstring result = content;



		return result;

	}

	std::wstring	Coder::Decode(std::wstring content, std::wstring key) {

		std::wstring result = content;



		return result;

	}

	bool			Coder::Check(std::wstring content, std::wstring key) {

		bool result = false;



		return result;

	}

}