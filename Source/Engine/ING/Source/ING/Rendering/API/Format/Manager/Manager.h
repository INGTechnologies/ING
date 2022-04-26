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
 *	Include Format
 */
#include <ING\Rendering/API/Format/Format.h>



namespace ING {

	namespace Rendering {

		class IAPI;

		class ING_API FormatManager :
			public Singleton<FormatManager>,
			public Square
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			FormatManager();
			~FormatManager();



			/**
			 *	Init, Run, Release Methods
			 */
		public:
			virtual bool	Init()		override;
			virtual bool	Run()		override;
			virtual bool	Release()	override;



			/**
			 *	Properties
			 */
		private:
			std::unordered_map<Format, unsigned int> format2StrideMap;

		public:
			unsigned int GetStride(Format);

		};

	}

}