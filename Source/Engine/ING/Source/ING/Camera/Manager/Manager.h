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

	class C_Camera;



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
		List<C_Camera*>			cameraList;

	public:
		List<C_Camera*>&		GetCameraList () { return cameraList; }



		/**
		 *	Method
		 */
	public:
		List<C_Camera*>::Node*	AddCamera		(C_Camera* camera);

		void					RemoveCamera	(List<C_Camera*>::Node* node);

		void					FrameUpdate		();

	};


}