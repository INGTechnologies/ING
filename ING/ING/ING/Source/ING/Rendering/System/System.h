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

		class ING_API System :
			public Singleton<System>,
			public Square
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			System();
			~System();



			/**
			 *	Init, Run, Release Methods
			 */
		public:
			virtual bool Init()		override;
			virtual bool Run()		override;
			virtual bool Release()	override;

		};

	}

}