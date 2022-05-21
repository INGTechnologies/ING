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



/**
 *	Include Shader
 */
#include "../Shader.h"



namespace ING {

	namespace Rendering {

		class ING_API DrawableShader : public IShader {

			/**
			 *	Constructors And Destructor
			 */
		public:
			DrawableShader	(IDevice* device, const String& name);
			DrawableShader	(const String& name);
			~DrawableShader	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() override;



			/**
			 *	Properties
			 */
		private:
			std::vector<String>			filterNameVector;

		public:
			const std::vector<String>&	GetFilterNameVector () { return filterNameVector; }
			void						SetFilterNameVector (const std::vector<String>& filterNameVector);

		};

	}

}