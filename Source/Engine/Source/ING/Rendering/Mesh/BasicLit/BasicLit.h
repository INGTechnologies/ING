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
 *	Include Mesh
 */
#include <ING/Rendering/Mesh/Mesh.h>



/**
 *	Include Math
 */
#include <ING/Math/Math.h>



/**
 *	Include AMath
 */
#include <ING/AMath/AMath.h>



namespace ING {

	class Camera;



	namespace Rendering {

		class IRenderer;

		class IDevice;

		class IDeviceContext;

		class IPass;

		class IBuffer;



		struct BasicLitVertex {

			Math::Vector3 localPos;
			Math::Vector3 localormal;
			Math::Vector3 localTangent;
			Math::Vector2 texcoord;

		};



		class ING_API BasicLitMesh : public IMesh
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			BasicLitMesh();
			~BasicLitMesh();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			IBuffer*					vBuffer;
			IBuffer*					iBuffer;

		public:
			std::vector<BasicLitVertex>	vertices;
			std::vector<size_t>			indices;

			IBuffer*					GetVBuffer	() { return vBuffer; }
			IBuffer*					GetIBuffer	() { return iBuffer; }

		};

	}

}