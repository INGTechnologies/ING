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
 *	Include Vertex Buffer
 */
#include <ING/Rendering/API/Resource/VertexBuffer/VertexBuffer.h>



/**
 *	Include Index Buffer
 */
#include <ING/Rendering/API/Resource/IndexBuffer/IndexBuffer.h>



/**
 *	Include Format
 */
#include <ING/Rendering/API/Format/Format.h>



namespace ING {

	class Camera;



	namespace Rendering {

		class IRenderer;

		class IDevice;

		class IDeviceContext;

		class IPass;

		class IBuffer;



		class ING_API IMesh : public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IMesh();
			IMesh(IDevice* device);
			~IMesh();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		protected:
			IBuffer* vertexBuffer;
			IBuffer* indexBuffer;

			unsigned int stride;

			IDevice* device;

		public:
			IBuffer* GetVertexBuffer() { return vertexBuffer; }
			IBuffer* GetIndexBuffer	() { return vertexBuffer; }

			unsigned int GetStride	() { return stride; }

			IDevice* GetDevice		() { return device; }



			/**
			 *	Methods
			 */
		public:
			virtual void BuildBuffers();

		};



		template<typename T>
		class Mesh : public IMesh {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Mesh();
			Mesh(
				const std::vector<T>&		vertexVector,
				const std::vector<unsigned int>&	indexVector
			);
			~Mesh();



			/**
			 *	Properties
			 */
		protected:
			std::vector<T>				vertexVector;
			std::vector<unsigned int>	indexVector;

		public:
			std::vector<T>&				GetVertexVector () { return vertexVector; }
			std::vector<unsigned int>&	GetIndexVector  () { return indexVector; }



			/**
			 *	Methods
			 */
		public:
			virtual void BuildBuffers() override;

		};

	}

}



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		template<typename T>
		Mesh<T>::Mesh() {

			stride = sizeof(T);

		}

		template<typename T>
		Mesh<T>::Mesh(
			const std::vector<T>& vertexVector,
			const std::vector<unsigned int>& indexVector
		) {

			this->vertexVector = vertexVector;
			this->indexVector = indexVector;

			stride = sizeof(T);

		}

		template<typename T>
		Mesh<T>::~Mesh() {



		}



		/**
		 *	Methods
		 */
		template<typename T>
		void Mesh<T>::BuildBuffers() {

			vertexBuffer	= IVertexBuffer::Create	(device, vertexVector.size(), stride, &vertexVector[0]);
			indexBuffer		= IIndexBuffer::Create	(device, indexVector.size(), FORMAT_R32_UINT, &indexVector[0]);

		}

	}

}