
/**
 * Include Header
 */
#include "MeshDrawable.h"



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include Renderer
 */
#include <ING/Rendering/Renderer/Renderer.h>



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Rendering Buffer
 */
#include <ING/Rendering/API/Resource/Buffer/Buffer.h>



/**
 *	Include Rendering Primitive Topology
 */
#include <ING/Rendering/API/PrimitiveTopology/PrimitiveTopology.h>



/**
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>



/**
 *	Include Rendering Drawable
 */
#include <ING/Rendering/Drawable/Category/Category.h>



/**
 *	Include Rendering Layer
 */
#include <ING/Rendering/Layer/Layer.h>



/**
 *	Include Rendering Layer Manager
 */
#include <ING/Rendering/Layer/Manager/Manager.h>



/**
 *	Include Rendering Mesh
 */
#include <ING/Rendering/Mesh/Mesh.h>



/**
 *	Include Rendering Material
 */
#include <ING/Rendering/Material/Material.h>



/**
 *	Include Rendering Drawable Material
 */
#include <ING/Rendering/Material/DrawableMaterial/DrawableMaterial.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>




namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		MeshDrawable::MeshDrawable() :
			mesh(0),
			material(0)
		{



		}

		MeshDrawable::~MeshDrawable() {

				

		}



		/**
		 *	Release Methods
		 */
		void MeshDrawable::Release() {

			delete this;

		}



		/**
		 *	Methods
		 */
		void MeshDrawable::Draw(Camera* camera, const std::string& passName) {

			material->Apply(passName);

			material->As<DrawableMaterial>()->ApplyTransform(transformMatrices,false);
			material->As<DrawableMaterial>()->ApplyCamera(camera,false);

			material->UpdatePropertyBuffer();


			/* Bind Buffers */
			IBuffer* vertexBuffer = mesh->GetVertexBuffer();
			IBuffer* indexBuffer  = mesh->GetIndexBuffer();

			IDeviceContext* context = vertexBuffer->GetDevice()->GetContext();

			context->IASetPrimitiveTopology(TRIANGLE_LIST);

			context->IASetVertexBuffer(vertexBuffer, mesh->GetVertexBufferDesc().stride, 0);
			context->IASetIndexBuffer(indexBuffer, mesh->GetIndexBufferDesc().format, 0);


			context->DrawIndexed(mesh->GetIndexCount(),0,0);

		}

	}

}