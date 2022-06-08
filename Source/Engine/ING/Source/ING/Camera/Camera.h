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



/**
 *	Include Reflection
 */
#include <ING/Reflection/Reflection.h>

using namespace ING::Reflection;



namespace ING {

	namespace Rendering {

		class Scene;

		class C_Pipeline;

		class C_CameraData;

	}

	struct S_TransformS;
	struct S_TransformM;

	class Screen;



	enum CameraTargetMode {

		CAMERA_TARGET_SCREEN,
		CAMERA_TARGET_TEXTURE

	};



	class ING_API C_Camera : public C_Object
	{

		ING_REFLECT_CLASS(C_Camera, C_Object)



		/**
		 *	Friend Classes
		 */
	public:
		friend class CameraManager;



		/**
		 *	Constructor
		 */
	protected:
		void Constructor();



		/**
		 *	Release Methods
		 */
	public:
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		List<C_Camera*>::Node*	node;

		List<C_Camera*>::Node*	nodeInScreenCameraList;

		CameraId				id;

		bool					isActive;

		RMatrix4x4				viewMatrix;
		RMatrix4x4				projectionMatrix;

		S_TransformM			transformM;

		float					fov;

		float					nearPlane;
		float					farPlane;

		Screen*					screen;
		unsigned int			oldScreenWidth;
		unsigned int			oldScreenHeight;

		Rendering::Scene*		renderingScene;

		Rendering::C_CameraData*	renderingData;

		Rendering::C_Pipeline*	renderingPipeline;

		CameraTargetMode		targetMode;

	public:
		List<C_Camera*>::Node*	GetNode				()							{ return node; }

		List<C_Camera*>::Node*	GetNodeInScreenCameraList()						{ return nodeInScreenCameraList; }

		CameraId				GetId				()							{ return id; }

		bool					IsActive			()							{ return isActive; }

		void					SetActive			(bool isActive)				{ this->isActive = isActive; }

		const RMatrix4x4&		GetViewMatrix		()							{ return viewMatrix; }
		const RMatrix4x4&		GetProjectionMatrix ()							{ return projectionMatrix; }

		const S_TransformM&		GetS_TransformM		()							{ return transformM; }

		void					SetS_TransformM		(const ING::S_TransformM& newS_TransformM)		{ this->transformM = newS_TransformM; }

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

		Rendering::C_CameraData*	GetRenderingData	()							{ return renderingData; }
		void					SetRenderingData	(Rendering::C_CameraData* renderingData)		{ this->renderingData = renderingData; }

		Rendering::C_Pipeline*	GetRenderingPipeline()							{ return renderingPipeline; }
		void					SetRenderingPipeline(Rendering::C_Pipeline* renderingPipeline);

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