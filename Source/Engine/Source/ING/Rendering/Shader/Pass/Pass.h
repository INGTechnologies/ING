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

		class IShader;

		class IInputLayout;



		class ING_API IShaderPass {

			/**
			 *	Constructors And Destructor
			 */
		public:
			IShaderPass		(const std::string& name);
			~IShaderPass	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();


			/**
			 *	Properties
			 */
		private:
			std::string		name;

			std::unordered_map<std::string, IShader*> childShaderNameToChildShader;

			IInputLayout*	inputLayout;

		public:
			std::string		GetName	() const { return name; }

			IShader*		GetChild(const std::string& name) { return childShaderNameToChildShader[name]; }

			void			SetInputLayout(IInputLayout* inputLayout) { this->inputLayout = inputLayout; }

			IInputLayout*	GetInputLayout() { return inputLayout; }



			/**
			 *	Methods
			 */
		public:
			void AddChild	(const std::string& tag, IShader* shader);
			void RemoveChild(const std::string& tag, IShader* shader);

			void Apply();

		};

	}

}