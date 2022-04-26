
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
	std::wstring	Coder::Encode(const std::wstring& content, const std::wstring& key) {

		std::wstring result = content;



		return result;

	}

	std::wstring	Coder::Decode(const std::wstring& content, const std::wstring& key) {

		std::wstring result = content;



		return result;

	}

	bool			Coder::Check(const std::wstring& content, const std::wstring& key) {

		bool result = false;



		return result;

	}

}