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
 *	Include Camera Manager
 */
#include <ING/Camera/Manager/Manager.h>



/**
 *	Include Math
 */
#include <ING/Math/Math.h>

using namespace ING::Math;



namespace ING {

	namespace Rendering {

		class Scene;

	}

	struct TransformS;
	struct TransformM;

	class Screen;



	class ING_API Camera
	{

		/**
		 *	Friend Classes
		 */
	public:
		friend class CameraManager;



		/**
		 *	Constructors And Destructor
		 */
	public:
		Camera();
		~Camera();



		/**
		 *	Release Methods
		 */
	public:
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		List<Camera*>::Node*	node;

		bool					isActive;

		Matrix4x4				viewMatrix;
		Matrix4x4				projectionMatrix;

		TransformM*				transformM;

		float					fov;

		float					nearPlane;
		float					farPlane;

		Screen*					screen;

		Rendering::Scene*		renderingScene;

		void*					renderingData;

	public:
		List<Camera*>::Node*	GetNode				()							{ return node; }

		bool					IsActive			()							{ return isActive; }

		void					SetActive			(bool isActive)				{ this->isActive = isActive; }

		Matrix4x4				GetViewMatrix		()							{ return viewMatrix; }
		Matrix4x4				GetProjectionMatrix ()							{ return projectionMatrix; }

		TransformM*				GetTransformM		()							{ return transformM; }

		void					SetTransformM		(TransformM* transformM)	{ this->transformM = transformM; }

		float					GetFOV				()							{ return fov; }
		void					SetFOV				(float fov)					{ this->fov = fov;				Update(); }

		float					GetNearPlane		()							{ return nearPlane; }
		void					SetNearPlane		(float nearPlane)			{ this->nearPlane = nearPlane;	Update(); }
		float					GetFarPlane			()							{ return farPlane; }
		void					SetFarPlane			(float farPlane)			{ this->farPlane = farPlane;	Update(); }

		Screen*					GetScreen			()							{ return screen; }
		void					SetScreen			(Screen* screen)			{ this->screen = screen;		Update(); }

		Rendering::Scene*		GetRenderingScene	()							{ return renderingScene; }
		void					SetRenderingScene	(Rendering::Scene* renderingScene)	{ this->renderingScene = renderingScene;}

		void*					GetRenderingData	()							{ return renderingData; }
		void					SetRenderingData	(void* renderingData)		{ this->renderingData = renderingData; }



		/**
		 *	Methods
		 */
	public:
		void Update();

	};

}