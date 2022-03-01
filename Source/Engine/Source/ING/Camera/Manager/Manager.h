#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	class Camera;



	class ING_API CameraManager :
		public Singleton<CameraManager>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		CameraManager();
		~CameraManager();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;



		/**
		 *	Properties
		 */
	private:
		List<Camera*>  cameraList;
		std::unordered_map< Camera*>  cameraList;

	public:
		List<Camera*>& GetCameraList () { return cameraList; }



		/**
		 *	Method
		 */
	public:
		List<Camera*>::Node*	AddCamera		(Camera* camera);

		void					RemoveCamera	(List<Camera*>::Node* node);

	};


}