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
		virtual WString	Encode	(const WString& content, const WString& key);

		virtual WString	Decode	(const WString& content, const WString& key);

		virtual bool			Check	(const WString& content, const WString& key);

	};


}