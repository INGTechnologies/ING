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



		class ING_API IShader {

			/**
			 *	Constructors And Destructor
			 */
		public:
			IShader		(const std::string& name);
			~IShader	();



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

			std::unordered_map<std::string, IShaderPass*>	passName2PassMap;

		public:
			std::string		GetName	() const { return name; }

			const std::unordered_map<std::string, IShaderPass*>&	GetPassName2PassMap() const { return passName2PassMap; }

			IShaderPass*	GetPass(const std::string& name);



			/**
			 *	Methods
			 */
		public:
			IShaderPass*	AddPass		(const std::string& name);
			void			RemovePass	(const std::string& name);

			virtual void	Apply		(const std::string& name);

		};

	}

}