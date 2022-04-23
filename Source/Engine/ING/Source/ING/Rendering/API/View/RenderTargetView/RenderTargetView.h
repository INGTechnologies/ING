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
 *	Include View
 */
#include <ING/Rendering/API/View/View.h>



namespace ING {

	namespace Rendering {

		class ING_API IRenderTargetView: public IView
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IRenderTargetView(IDevice* device);
			~IRenderTargetView();



			/**
			 *	Create, Release Methods
			 */
		public:
			static IRenderTargetView*	Create(IDevice* device);

			virtual void				Release() override;

		};

	}

}