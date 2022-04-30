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



namespace ING {

	class Camera;



	namespace Rendering {

		class IDeviceContext;

		enum PassAddOption {

			PASS_ADD_BEFORE,
			PASS_ADD_AFTER,
			PASS_ADD_TAIL,
			PASS_ADD_HEAD

		};



		/**
		 *	Interface Class
		 */
		class ING_API IPass
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IPass	(const String& name);
			~IPass	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void	Release();



			/**
			 *	Properties
			 */
		private:
			String			name;

		public:
			String			GetName() { return name; }



			/**
			 *	Methods
			 */
		public:
			virtual bool	Render(IDeviceContext* context, Camera* camera);

		};

	}

}