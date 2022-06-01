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



/**
 *	Include BindFlag
 */
#include <ING/Rendering/API/BindFlag/BindFlag.h>



namespace ING {

	class Camera;



	namespace Rendering {

		class C_Renderer;

		class IDevice;

		class IDeviceContext;

		class C_Pass;

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

			VertexBufferDesc vertexBufferDesc;
			IndexBufferDesc indexBufferDesc;

			unsigned int vertexStride;

			IDevice* device;

		public:
			IBuffer* GetVertexBuffer() { return vertexBuffer; }
			IBuffer* GetIndexBuffer	() { return indexBuffer; }

			const VertexBufferDesc& GetVertexBufferDesc () { return vertexBufferDesc; }
			const IndexBufferDesc& GetIndexBufferDesc() { return indexBufferDesc; }

			unsigned int GetVertexStride	() { return vertexStride; }

			IDevice* GetDevice		() { return device; }

			virtual unsigned int GetVertexCount () { return 0; }
			virtual unsigned int GetIndexCount  () { return 0; }



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
			Mesh(
				const std::vector<T>& vertexVector,
				const std::vector<unsigned int>& indexVector,
				Format indexFormat
			);
			Mesh(
				const std::vector<T>& vertexVector,
				const std::vector<unsigned int>& indexVector,
				const VertexBufferDesc& vertexBufferDesc,
				const IndexBufferDesc& indexBufferDesc
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

			virtual unsigned int		GetVertexCount() override;
			virtual unsigned int		GetIndexCount() override;



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

			vertexStride = sizeof(T);

		}

		template<typename T>
		Mesh<T>::Mesh(
			const std::vector<T>& vertexVector,
			const std::vector<unsigned int>& indexVector
		) :
			Mesh(vertexVector, indexVector, FORMAT_R32_UINT)
		{ }

		template<typename T>
		Mesh<T>::Mesh(
			const std::vector<T>&vertexVector,
			const std::vector<unsigned int>&indexVector,
			Format indexFormat
		) : 
			Mesh(vertexVector, indexVector, 
				{

					vertexVector.size(),
					sizeof(T),
					USAGE_DEFAULT,
					BIND_VERTEX_BUFFER,
					(CPUAccessFlag)0

				},
				{

					indexVector.size(),
					indexFormat,
					USAGE_DEFAULT,
					BIND_INDEX_BUFFER,
					(CPUAccessFlag)0

				}
			)
		{}

		template<typename T>
		Mesh<T>::Mesh(
			const std::vector<T>& vertexVector,
			const std::vector<unsigned int>& indexVector,
			const VertexBufferDesc& vertexBufferDesc,
			const IndexBufferDesc& indexBufferDesc
		) {

			this->vertexVector = vertexVector;
			this->indexVector = indexVector;

			this->vertexBufferDesc = vertexBufferDesc;
			this->indexBufferDesc = indexBufferDesc;

			vertexStride = sizeof(T);

		}

		template<typename T>
		Mesh<T>::~Mesh() {



		}



		/**
		 *	Properties
		 */
		template<typename T>
		unsigned int Mesh<T>::GetVertexCount() {

			return vertexVector.size();

		}

		template<typename T>
		unsigned int Mesh<T>::GetIndexCount() {

			return indexVector.size();

		}



		/**
		 *	Methods
		 */
		template<typename T>
		void Mesh<T>::BuildBuffers() {

			vertexBufferDesc.stride = vertexStride;
			vertexBufferDesc.count = vertexVector.size();
			indexBufferDesc.count = indexVector.size();

			vertexBuffer	= IVertexBuffer::Create	(device, vertexBufferDesc, &vertexVector[0]);
			indexBuffer		= IIndexBuffer::Create	(device, indexBufferDesc, &indexVector[0]);

		}

	}

}