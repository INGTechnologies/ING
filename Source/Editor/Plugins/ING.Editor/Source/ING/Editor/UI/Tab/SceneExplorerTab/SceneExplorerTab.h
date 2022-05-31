#pragma once

/**
 *	Include Editor Entry Point
 */
#include <ING\Editor\EntryPoint\EntryPoint.h>



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
 *	Include UI Tab
 */
#include <ING/Editor/UI/Tab/Tab.h>



namespace ING {

	namespace Editor {

		namespace UI {

			class C_SceneTab;



			class PLUGIN_API(ING_EDITOR) C_SceneExplorerTab : public C_Tab
			{

				ING_REFLECT_CLASS(C_SceneExplorerTab, C_Tab)



				/**
				 *	Constructor
				 */
			protected:
				void Constructor(const String& name);



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Properties
				 */
			private:
				C_SceneTab*	sceneTab;

			public:
				C_SceneTab*	GetSceneTab	() { return sceneTab; }

				void		SetSceneTab	(C_SceneTab* sceneTab){ this->sceneTab = sceneTab; }



				/**
				 *	Methods
				 */
			public:
				virtual void Start()		override;

				virtual void PreUpdate()	override;
				virtual void Update()		override;
				virtual void LateUpdate()	override;

				virtual void PreRender()	override;
				virtual void Render()		override;
				virtual void LateRender()	override;

				virtual void Resize()		override;

			};

		}

	}

}