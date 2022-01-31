#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	namespace Rendering {

		/**
		 *	Declare Classes
		 */
		class Device;

		class Convertor;



		/**
		 *	API Class
		 */
		class ING_API API :
			public Singleton<API>,
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			API();
			~API();



			/**
			 *	Init, Release Methods
			 */
		public:
			virtual bool Init();
			virtual bool Release();



			/**
			 *	Main Device
			 */
		private:
			Device* device;

		public:
			Device* GetDevice() {

				return device;

			}



			/**
			 *	Convertor
			 */
		private:
			Convertor* convertor;

		public:
			Convertor* GetConvertor() {

				return convertor;

			}

		};

	}

}