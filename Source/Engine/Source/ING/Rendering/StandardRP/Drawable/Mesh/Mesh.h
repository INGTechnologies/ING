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

		class BasicLitMesh;

		class IMesh;



		namespace StandardRP {

			class ING_API MeshDrawable : public IDrawable
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				MeshDrawable();
				~MeshDrawable();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release();



				/**
				 *	Properties
				 */
			public:
				BasicLitMesh* mesh;



				/**
				 *	Methods
				 */
			public:
				virtual void Draw() override;

			};

		}

	}

}