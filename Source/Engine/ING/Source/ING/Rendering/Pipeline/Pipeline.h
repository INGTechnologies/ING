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
 *	Include Mutex
 */
#include <mutex>



namespace ING {

	class Camera;



	namespace Rendering {

		class IRenderer;

		class IDevice;

		class IDeviceContext;

		class IPass;



		class ING_API IPipeline
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IPipeline	(String name);
			~IPipeline	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		protected:
			String		name;

			IRenderer*	defaultRenderer;

			IRenderer*	renderer;

			IRenderer*	targetRenderer;

			bool		isRendering;

			std::unordered_map<String, unsigned int> name2PassIndex;

			std::vector<IPass*> passVector;

		public:
			String		GetName				() { return name; }

			IRenderer*	GetDefaultRenderer	() { return defaultRenderer; }

			IRenderer*	GetRenderer			() { return renderer; }

			IRenderer*	GetTargetRenderer	() { return targetRenderer; }

			void		SetRenderer			(IRenderer* renderer);

			bool		IsRendering			() { return isRendering; }

			unsigned int GetPassIndex		(const String& name) { return name2PassIndex[name]; }

			IPass*		GetPass				(const String& name) { return passVector[GetPassIndex(name)]; }

			IPass*		GetPass				(unsigned int index) { return passVector[index]; }



			/**
			 *	Methods
			 */
		public:
			void		 AddPass			(IPass* pass);
			void		 RemovePass			(IPass* pass);

			virtual void SetupCamera		(IDeviceContext* context, Camera* camera);
			virtual void ClearCameraData	(Camera* camera);

			virtual bool Render				(IDeviceContext* context);

			void		 BeginRender		(IDeviceContext* context);
			void		 EndRender			(IDeviceContext* context);

		};

	}

}