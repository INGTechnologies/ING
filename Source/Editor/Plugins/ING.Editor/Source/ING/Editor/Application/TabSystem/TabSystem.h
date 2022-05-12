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

			class ITab;

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
			std::unordered_map<String, UI::ITab*> name2TabMap;

		public:
			UI::ITab*		GetTab		(const String& name) { return name2TabMap[name]; }

			bool			IsHasTab	(const String& name) { return name2TabMap.find(name) != name2TabMap.end(); }



			/**
			 *	Methods
			 */
		public:
			void			AddTab		(UI::ITab* layout);
			void			RemoveTab	(UI::ITab* layout);

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