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

		class Layer;



		class ING_API LayerManager :
			public Singleton<LayerManager>,
			public Square
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			LayerManager();
			~LayerManager();



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