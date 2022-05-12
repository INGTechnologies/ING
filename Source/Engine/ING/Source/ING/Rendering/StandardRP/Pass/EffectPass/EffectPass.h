#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>



namespace ING {

	class Camera;



	namespace Rendering {

		namespace StandardRP {

			class ING_API EffectPass : public IPass
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				EffectPass	(const String& name);
				~EffectPass	();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Properties
				 */
			private:
				IPass*	skyPass;
				IPass*	opaquePass;
				IPass*	transparentPass;

			public:
				IPass*	GetSkyPass			() { return skyPass; }
				IPass*	GetOpaquePass		() { return opaquePass; }
				IPass*	GetTransparentPass	() { return transparentPass; }

				void	SetSkyPass			(IPass* pass) { this->skyPass = pass; }
				void	SetOpaquePass		(IPass* pass) { this->opaquePass = pass; }
				void	SetTransparentPass	(IPass* pass) { this->transparentPass = pass; }



				/**
				 *	Methods
				 */
			public:
				virtual bool Render(IDeviceContext* context, Camera* camera) override;

			};

		}

	}

}