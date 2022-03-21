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
 *	Include Rendering Material Manager
 */
#include <ING/Rendering/Material/Manager/Manager.h>



namespace ING {

	namespace Rendering {

		class IDrawableCategory;

		class IDrawble;

		class IShader;

		class IDeviceContext;

		class IDevice;



		class ING_API IMaterial
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IMaterial		(const std::string& name, IShader* shader);
			~IMaterial		();



			/**
			 *	Release Methods
			 */
		public:
			virtual void	Release();


			/**
			 *	Properties
			 */
		private:
			std::string		name;

			IShader*		shader;

		public:
			std::string		GetName			() { return name; }

			IShader*		GetShader		() { return shader; }

			void			SetShader		(IShader* shader) { this->shader = shader; }



			/**
			 *	Methods
			 */
		public:
			virtual void Apply(const std::string& passName);

		};

	}

}