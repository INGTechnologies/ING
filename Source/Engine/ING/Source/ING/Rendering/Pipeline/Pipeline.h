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



/**
 *	Include Reflection
 */
#include <ING/Reflection/Reflection.h>

using namespace ING::Reflection;



namespace ING {

	class C_Camera;

	class ApplicationRenderingSystem;



	namespace Rendering {

		class C_Renderer;

		class IDevice;

		class IDeviceContext;

		class C_Pass;



		class ING_API C_Pipeline : public Reflection::C_Object
		{

			/**
			 *	Friend Class
			 */
		public:
			friend class C_Pass;



			ING_REFLECT_CLASS(C_Pipeline, Reflection::C_Object)



			/**
			 *	Constructor
			 */
		protected:
			void Constructor(const String& name);



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() override;



			/**
			 *	Properties
			 */
		protected:
			String		name;

			C_Renderer*	renderer;

			bool		isRendering;

			std::unordered_map<String, unsigned int> name2PassIndex;

			std::vector<C_Pass*> passVector;

			IClass*		cameraDataClass;

		public:
			const String& GetName			() { return name; }

			C_Renderer*	GetRenderer			() { return renderer; }

			void		SetRenderer			(C_Renderer* renderer) { this->renderer = renderer; }

			bool		IsRendering			() { return isRendering; }

			unsigned int GetPassIndex		(const String& name) { return name2PassIndex[name]; }

			C_Pass*		GetPass				(const String& name) { return passVector[GetPassIndex(name)]; }

			C_Pass*		GetPass				(unsigned int index) { return passVector[index]; }

			IClass*		GetCameraDataClass	() { return cameraDataClass; }
			void		SetCameraDataClass	(IClass* _class) { this->cameraDataClass = _class; }



			/**
			 *	Methods
			 */
		public:
			void		 AddPass			(C_Pass* pass);
			void		 AddPass			(C_Pass* pass, unsigned int index);
			void		 RemovePass			(unsigned int index);
			void		 RemovePass			(const String& name);
			void		 RemovePass			(C_Pass* pass);

			virtual void SetupCamera		(IDeviceContext* context, C_Camera* camera);
			virtual void ClearCameraData	(C_Camera* camera);

			virtual bool Render				(IDeviceContext* context);

			void		 BeginRender		(IDeviceContext* context);
			void		 EndRender			(IDeviceContext* context);

		};

	}

}