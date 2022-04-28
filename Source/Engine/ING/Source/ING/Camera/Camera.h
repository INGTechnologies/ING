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

		class ICameraData;

	}

	struct TransformS;
	struct TransformM;

	class Screen;



	enum CameraTargetMode {

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

		Rendering::ICameraData*	renderingData;

		Rendering::IPipeline*	renderingPipeline;

		CameraTargetMode		targetMode;

	public:
		List<Camera*>::Node*	GetNode				()							{ return node; }

		List<Camera*>::Node*	GetNodeInScreenCameraList()						{ return nodeInScreenCameraList; }

		CameraId				GetId				()							{ return id; }

		bool					IsActive			()							{ return isActive; }

		void					SetActive			(bool isActive)				{ this->isActive = isActive; }

		const RMatrix4x4&		GetViewMatrix		()							{ return viewMatrix; }
		const RMatrix4x4&		GetProjectionMatrix ()							{ return projectionMatrix; }

		const TransformM&		GetTransformM		()							{ return transformM; }

		void					SetTransformM		(const ING::TransformM& newTransformM)		{ this->transformM = newTransformM; }

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

		Rendering::ICameraData*	GetRenderingData	()							{ return renderingData; }
		void					SetRenderingData	(Rendering::ICameraData* renderingData)		{ this->renderingData = renderingData; }

		Rendering::IPipeline*	GetRenderingPipeline()							{ return renderingPipeline; }
		void					SetRenderingPipeline(Rendering::IPipeline* renderingPipeline) { this->renderingPipeline = renderingPipeline; }

		CameraTargetMode		GetTargetMode		()							{ return targetMode; }
		void					SetTargetMode		(CameraTargetMode mode);

		unsigned int			GetClientWidth		();
		unsigned int			GetClientHeight		();



		/**
		 *	Methods
		 */
	public:
		void Update();

	};

}