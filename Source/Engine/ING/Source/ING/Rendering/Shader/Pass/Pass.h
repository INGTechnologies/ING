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

		class IState;

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

			std::unordered_map<std::string, IShader*> shaderName2Shader;
			std::unordered_map<std::string, IState*>  stateName2StateMap;

			IInputLayout*	inputLayout;

		public:
			std::string		GetName			() const { return name; }

			IShader*		GetShader		(const std::string& name) { return shaderName2Shader[name]; }

			void			SetInputLayout	(IInputLayout* inputLayout) { this->inputLayout = inputLayout; }

			IInputLayout*	GetInputLayout	() { return inputLayout; }

			IState*			GetState		(const std::string& name) { return stateName2StateMap[name]; }



			/**
			 *	Methods
			 */
		public:
			void AddShader		(const std::string& tag, IShader* shader);
			void RemoveShader	(const std::string& tag);

			void AddState		(IState* state);
			void RemoveState	(const std::string& name);

			void Apply			();

		};

	}

}