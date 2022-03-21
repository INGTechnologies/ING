
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
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>




namespace ING {

	namespace Rendering {

		namespace StandardRP {

			/**
			 *	Constructors And Destructor
			 */
			MeshDrawable::MeshDrawable() {



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
			void MeshDrawable::Draw(const std::string& passName) {

				material->Apply(passName);


				/* Bind Buffers */
				IBuffer* vertexBuffer = mesh->GetVertexBuffer();
				IBuffer* indexBuffer  = mesh->GetIndexBuffer();

				IDeviceContext* context = vertexBuffer->GetDevice()->GetContext();

				context->IASetPrimitiveTopology(TRIANGLE_LIST);

				context->IASetVertexBuffer(vertexBuffer, mesh->GetStride(), 0 );
				context->IASetIndexBuffer(indexBuffer, FORMAT_R32_UINT, 0);


				context->DrawIndexed(mesh->GetIndexCount(),0,0);

			}

		}

	}

}