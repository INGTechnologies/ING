#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	class ING_API Coder {

		/**
		 *	Constructors And Destructor
		 */
	public:
		Coder();
		~Coder();



		/**
		 *	Release Method
		 */
	public:
		virtual void Release();



		/**
		 *	Encode, Decode, Check Methods
		 */
	public:
		virtual std::wstring	Encode	(std::wstring content, std::wstring key);

		virtual std::wstring	Decode	(std::wstring content, std::wstring key);

		virtual bool			Check	(std::wstring content, std::wstring key);

	};


}