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



namespace ING {

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

	};

}