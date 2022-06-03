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
 *	Include Reflection
 */
#include <ING/Reflection/Reflection.h>

using namespace ING::Reflection;



namespace ING {

	class Camera;



	namespace Rendering {

		class IDeviceContext;

		class C_Pipeline;



		/**
		 *	Interface Class
		 */
		class ING_API C_Pass : public Reflection::C_Object
		{

			/**
			 *	Friend Class
			 */
		public:
			friend class C_Pipeline;



			ING_REFLECT_CLASS(C_Pass, Reflection::C_Object)



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
		private:
			String			name;

			std::unordered_map<String, unsigned int> name2ChildIndex;

			std::vector<C_Pass*> childVector;

			C_Pass*			parent;

			C_Pipeline*		pipeline;

		public:
			String			GetName		() { return name; }

			unsigned int	GetChildIndex(const String& name) { return name2ChildIndex[name]; }

			C_Pass*			GetChild	(const String& name) { return childVector[GetChildIndex(name)]; }

			C_Pass*			GetChild	(unsigned int index) { return childVector[index]; }

			C_Pass*			GetParent	() { return parent; }

			C_Pipeline*		GetPipeline	() { return pipeline; }

		private:
			void			SetParent	(C_Pass* newParent);

			void			SetPipeline	(C_Pipeline* pipeline);



			/**
			 *	Methods
			 */
		public:
			void			AddChild	(C_Pass* child);
			void			AddChild	(C_Pass* child, unsigned int index);
			void			RemoveChild	(unsigned int index);
			void			RemoveChild	(const String& name);
			void			RemoveChild	(C_Pass* child);

			virtual bool	Render		(IDeviceContext* context, Camera* camera);

		};

	}

}