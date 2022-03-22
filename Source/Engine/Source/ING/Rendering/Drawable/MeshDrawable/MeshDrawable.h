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



/**
 *	Include Transform
 */
#include <ING/Transform/Transform.h>



namespace ING {

	class Camera;



	namespace Rendering {

		class IRenderer;

		class IDevice;

		class IDeviceContext;

		class IPass;

		class IMesh;

		class IMaterial;



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
		private:
			IMesh*		mesh;
			IMaterial*	material;
			TransformM	transformMatrices;

		public:
			IMesh*		GetMesh		()						{ return mesh; }
			IMaterial*	GetMaterial	()						{ return material; }

			void		SetMesh		(IMesh* mesh)			{ this->mesh = mesh; }
			void		SetMaterial	(IMaterial* material)	{ this->material = material; }

			void		SetTransform(const TransformM& transformMatrices)	{ this->transformMatrices = transformMatrices; }



			/**
			 *	Methods
			 */
		public:
			virtual void Draw(Camera* camera, const std::string& passName) override;

		};

	}

}