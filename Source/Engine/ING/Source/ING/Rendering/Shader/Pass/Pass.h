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
			IShaderPass		(const String& name);
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
			String		name;

			std::unordered_map<String, IShader*> shaderName2Shader;
			std::unordered_map<String, IState*>  stateName2StateMap;

			IInputLayout*	inputLayout;

		public:
			String		GetName			() const { return name; }

			IShader*		GetShader		(const String& name) { return shaderName2Shader[name]; }

			void			SetInputLayout	(IInputLayout* inputLayout) { this->inputLayout = inputLayout; }

			IInputLayout*	GetInputLayout	() { return inputLayout; }

			IState*			GetState		(const String& name) { return stateName2StateMap[name]; }



			/**
			 *	Methods
			 */
		public:
			void AddShader		(const String& tag, IShader* shader);
			void RemoveShader	(const String& tag);

			void AddState		(IState* state);
			void RemoveState	(const String& name);

			void Apply			();

		};

	}

}