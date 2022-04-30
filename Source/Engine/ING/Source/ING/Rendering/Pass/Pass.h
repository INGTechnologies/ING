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

		class IPipeline;



		/**
		 *	Interface Class
		 */
		class ING_API IPass
		{

			/**
			 *	Friend Class
			 */
		public:
			friend class IPipeline;



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

			std::unordered_map<String, unsigned int> name2ChildIndex;

			std::vector<IPass*> childVector;

			IPass*			parent;

			IPipeline*		pipeline;

		public:
			String			GetName		() { return name; }

			unsigned int	GetChildIndex(const String& name) { return name2ChildIndex[name]; }

			IPass*			GetChild	(const String& name) { return childVector[GetChildIndex(name)]; }

			IPass*			GetChild	(unsigned int index) { return childVector[index]; }

			IPass*			GetParent	() { return parent; }

			IPipeline*		GetPipeline	() { return pipeline; }

		private:
			void			SetParent	(IPass* newParent);

			void			SetPipeline	(IPipeline* pipeline);



			/**
			 *	Methods
			 */
		public:
			void			AddChild	(IPass* child);
			void			AddChild	(IPass* child, unsigned int index);
			void			RemoveChild	(unsigned int index);
			void			RemoveChild	(const String& name);
			void			RemoveChild	(IPass* child);

			virtual bool	Render		(IDeviceContext* context, Camera* camera);

		};

	}

}