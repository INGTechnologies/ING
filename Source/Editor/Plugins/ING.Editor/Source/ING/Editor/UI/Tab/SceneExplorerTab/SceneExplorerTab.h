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

			class SceneTab;



			class PLUGIN_API(ING_EDITOR) SceneExplorerTab : public ITab
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				SceneExplorerTab	();
				~SceneExplorerTab	();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Properties
				 */
			private:
				SceneTab*	sceneTab;

			public:
				SceneTab*	GetSceneTab	() { return sceneTab; }

				void		SetSceneTab	(SceneTab* sceneTab){ this->sceneTab = sceneTab; }



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