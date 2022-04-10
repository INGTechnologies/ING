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



/**
 *	Include APIFlag
 */
#include <ING\Rendering/API/APIFlag.h>



namespace ING {

	namespace Rendering {

		class IAPI;

		class ING_API APIManager :
			public Board<APIManager>,
			public Square
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			APIManager();
			~APIManager();



			/**
			 *	Init, Init API, Run, Release Methods
			 */
		public:
			virtual bool	Init()		override;
					bool	InitAPI();
			virtual bool	Run()		override;
			virtual bool	Release()	override;



			/**
			 *	API Management Methods, Properties
			 */
		protected:
			APIFlag apiFlag;

			IAPI* api;

		public:
			APIFlag GetAPIFlag() {

				return apiFlag;

			}

			IAPI* GetAPI() {

				return api;

			}

		};

	}

}