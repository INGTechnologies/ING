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

			Format   indexFormat;

			IDevice* device;

		public:
			IBuffer* GetVertexBuffer() { return vertexBuffer; }
			IBuffer* GetIndexBuffer	() { return indexBuffer; }

			unsigned int GetStride	() { return stride; }

			IDevice* GetDevice		() { return device; }

			virtual unsigned int GetVertexCount () { return 0; }
			virtual unsigned int GetIndexCount  () { return 0; }

			Format   GetIndexFormat () { return indexFormat; }



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

			virtual unsigned int GetVertexCount() override;
			virtual unsigned int GetIndexCount() override;



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
		) :
			Mesh(vertexVector, indexVector, FORMAT_R32_UINT)
		{ }

		template<typename T>
		Mesh<T>::Mesh(
			const std::vector<T>& vertexVector,
			const std::vector<unsigned int>& indexVector,
			Format indexFormat
		) {

			this->vertexVector = vertexVector;
			this->indexVector = indexVector;

			this->indexFormat = indexFormat;

			stride = sizeof(T);

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

			vertexBuffer	= IVertexBuffer::Create	(device, vertexVector.size(), stride, &vertexVector[0]);
			indexBuffer		= IIndexBuffer::Create	(device, indexVector.size(), indexFormat, &indexVector[0]);

		}

	}

}