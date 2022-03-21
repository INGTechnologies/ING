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
 *	Include Rendering Material
 */
#include <ING/Rendering/Material/Material.h>



namespace ING {

	namespace Rendering {

		class IDrawableCategory;

		class IDrawble;

		class IShader;

		class IState;



		class ING_API DrawableMaterial : public IMaterial
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			DrawableMaterial	(const std::string& name, IShader* shader);
			~DrawableMaterial	();



			/**
			 *	Properties
			 */
		private:
			std::unordered_map<std::string, IState*>			stateName2StateMap;

		public:
			const std::unordered_map<std::string, IState* >&	GetStateName2StateMap	() { return stateName2StateMap; }



			/**
			 *	Methods
			 */
		public:
			void	AddState	(const std::string& name, IState* state);
			IState*	GetState	(const std::string& name);
			void	RemoveState	(const std::string& name);
			void	Destroy		(const std::string& name);

			virtual void Apply	(const std::string& passName) override;

		};

	}

}