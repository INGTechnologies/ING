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

			std::unordered_map<String, unsigned int> name2ChildIndex;

			std::vector<IPass*> childVector;

		public:
			String			GetName() { return name; }

			unsigned int	GetChildIndex(const String& name) { return name2ChildIndex[name]; }

			IPass*			GetChild(const String& name) { return childVector[GetChildIndex(name)]; }

			IPass*			GetChild(unsigned int index) { return childVector[index]; }



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