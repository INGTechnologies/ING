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

		class ING_API RenderTargetView: public View
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			RenderTargetView();
			~RenderTargetView();



			/**
			 *	Create, Release Methods
			 */
		public:
			static RenderTargetView* Create();

			virtual void Release() override;

		};

	}

}