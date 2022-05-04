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
 *	Include Map
 */
#include <map>



/**
 *	Include Math
 */
#include <ING/Math/Math.h>



/**
 *	Include UI Element
 */
#include <ING/UI/Element/Element.h>



namespace ING {

	class ApplicationUISystem;

	namespace UI {

		class Node;
		class Style;



		class ING_API ICanvas : public IElement
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ICanvas	(ApplicationUISystem* system);
			~ICanvas();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() override;



			/**
			 *	Properties
			 */
		private:
			ApplicationUISystem* system;

		public:
			ApplicationUISystem* GetSystem() { return system; }



			/**
			 *	Methods
			 */
		public:
			virtual void Start() override;

			virtual void PreUpdate() override;
			virtual void Update() override;
			virtual void LateUpdate() override;

			virtual void PreRender() override;
			virtual void Render() override;
			virtual void LateRender() override;

		};

	}

}