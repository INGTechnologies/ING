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



/**
 *	Include Drawable
 */
#include <ING/Rendering/Drawable/Drawable.h>



namespace ING {

	class Camera;



	namespace Rendering {

		class IRenderer;

		class IDevice;

		class IDeviceContext;

		class IPass;



		namespace StandardRP {

			class ING_API UIDrawable : public IDrawable
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				UIDrawable();
				~UIDrawable();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release();



				/**
				 *	Methods
				 */
			public:
				virtual void Draw() override;

			};

		}

	}

}