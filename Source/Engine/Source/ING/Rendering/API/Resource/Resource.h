#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	namespace Rendering {

		class Device;



		class ING_API Resource :
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Resource(Rendering::Device* device);
			~Resource();



			/**
			 *	Create, Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			Rendering::Device*	device;

		public:
			Rendering::Device*	GetDevice	() { return device; }

			void				SetDevice	(Rendering::Device* device) { this->device = device; }

		};

	}

}