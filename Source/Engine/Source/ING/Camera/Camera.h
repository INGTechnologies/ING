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



/**
 *	Include Camera Id
 */
#include <ING/Camera/Id.h>



/**
 *	Include Transform
 */
#include <ING/Transform/Transform.h>



namespace ING {

	namespace Rendering {

		class Scene;

		class IPipeline;

	}

	struct TransformS;
	struct TransformM;

	class Screen;



	enum CAMERA_TARGET_MODE {

		CAMERA_TARGET_SCREEN,
		CAMERA_TARGET_TEXTURE

	};



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

		List<Camera*>::Node*	nodeInScreenCameraList;

		CameraId				id;

		bool					isActive;

		RMatrix4x4				viewMatrix;
		RMatrix4x4				projectionMatrix;

		TransformM				transformM;

		float					fov;

		float					nearPlane;
		float					farPlane;

		Screen*					screen;
		unsigned int			oldScreenWidth;
		unsigned int			oldScreenHeight;

		Rendering::Scene*		renderingScene;

		void*					renderingData;

		Rendering::IPipeline*	renderingPipeline;

		CAMERA_TARGET_MODE		targetMode;

	public:
		List<Camera*>::Node*	GetNode				()							{ return node; }

		List<Camera*>::Node*	GetNodeInScreenCameraList()						{ return nodeInScreenCameraList; }

		CameraId				GetId				()							{ return id; }

		bool					IsActive			()							{ return isActive; }

		void					SetActive			(bool isActive)				{ this->isActive = isActive; }

		const RMatrix4x4&		GetViewMatrix		()							{ return viewMatrix; }
		const RMatrix4x4&		GetProjectionMatrix ()							{ return projectionMatrix; }

		const TransformM&		SetTransform		()							{ return transformM; }

		void					SetTransform		(TransformM transformM)		{ this->transformM = transformM; }

		float					GetFOV				()							{ return fov; }
		void					SetFOV				(float fov)					{ this->fov = fov;				Update(); }

		float					GetNearPlane		()							{ return nearPlane; }
		void					SetNearPlane		(float nearPlane)			{ this->nearPlane = nearPlane;	Update(); }
		float					GetFarPlane			()							{ return farPlane; }
		void					SetFarPlane			(float farPlane)			{ this->farPlane = farPlane;	Update(); }

		Screen*					GetScreen			()							{ return screen; }
		void					SetScreen			(Screen* screen);

		Rendering::Scene*		GetRenderingScene	()							{ return renderingScene; }
		void					SetRenderingScene	(Rendering::Scene* renderingScene)	{ this->renderingScene = renderingScene;}

		void*					GetRenderingData	()							{ return renderingData; }
		void					SetRenderingData	(void* renderingData)		{ this->renderingData = renderingData; }

		Rendering::IPipeline*	GetRenderingPipeline()							{ return renderingPipeline; }
		void					SetRenderingPipeline(Rendering::IPipeline* renderingPipeline) { this->renderingPipeline = renderingPipeline; }

		CAMERA_TARGET_MODE		GetTargetMode		()							{ return targetMode; }
		void					SetTargetMode		(CAMERA_TARGET_MODE mode);

		unsigned int			GetClientWidth		();
		unsigned int			GetClientHeight		();



		/**
		 *	Methods
		 */
	public:
		void Update();

	};

}