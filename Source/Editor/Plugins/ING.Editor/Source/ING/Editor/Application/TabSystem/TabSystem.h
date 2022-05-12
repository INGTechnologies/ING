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
 *	Include ApplicationComponent
 */
#include <ING/Application/Component/Component.h>



namespace ING {

	class IApplication;

	class IWindow;



	namespace Editor {

		namespace UI {

			class ITabCreator;

		}



		class PLUGIN_API(ING_EDITOR) ApplicationTabSystem : public IApplicationComponent
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ApplicationTabSystem	(IApplication* application);
			~ApplicationTabSystem	();



			/**
			 *	Init, Release Methods
			 */
		public:
			virtual bool Init() override;
			virtual void Release() override;



			/**
			 *	Properties
			 */
		private:
			std::unordered_map<String, UI::ITabCreator*> name2TabCreatorMap;

		public:
			UI::ITabCreator*GetTabCreator		(const String& name) { return name2TabCreatorMap[name]; }

			bool			IsHasTabCreator	(const String& name) { return name2TabCreatorMap.find(name) != name2TabCreatorMap.end(); }



			/**
			 *	Methods
			 */
		public:
			void			AddTabCreator		(UI::ITabCreator* tabCreator);
			void			RemoveTabCreator	(UI::ITabCreator* tabCreator);

			virtual void	Start		() override;

			virtual void	PreUpdate	() override;
			virtual void	Update		() override;
			virtual void	LateUpdate	() override;

			virtual void	PreRender	() override;
			virtual void	Render		() override;
			virtual void	LateRender	() override;

		};

	}

}