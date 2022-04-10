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
		class IDevice;

		class IConvertor;



		/**
		 *	API Class
		 */
		class ING_API IAPI :
			public Singleton<IAPI>,
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IAPI();
			~IAPI();



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
			IDevice* device;

		public:
			IDevice* GetDevice() {

				return device;

			}



			/**
			 *	Convertor
			 */
		private:
			IConvertor* convertor;

		public:
			IConvertor* GetConvertor() {

				return convertor;

			}

		};

	}

}