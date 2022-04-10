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
 *	Include Vector
 */
#include <vector>



namespace ING {

	namespace Rendering {

		class IShaderPass;

		class IMaterial;

		class IDevice;



		class ING_API IState : public AsMethod {

			/**
			 *	Constructors And Destructor
			 */
		public:
			IState		(IDevice* device, const std::string& name);
			IState		(const std::string& name);
			~IState();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		public:
			std::string	name;
			IDevice* device;

		public:
			const std::string& GetName		() { return name; }
			IDevice*		   GetDevice	() { return device; }

			

			/**
			 *	Methods
			 */
		public:
			virtual void Apply();

		};

	}

}