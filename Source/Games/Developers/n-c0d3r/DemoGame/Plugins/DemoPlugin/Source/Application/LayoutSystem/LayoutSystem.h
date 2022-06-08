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

		class Layout;



		class PLUGIN_API(ING_EDITOR) ApplicationLayoutSystem : public IApplicationComponent
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ApplicationLayoutSystem	(IApplication* application);
			~ApplicationLayoutSystem();



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
			std::unordered_map<String, Layout*> name2LayoutMap;

		public:
			Layout*			GetLayout		(const String& name) { if(!IsHasLayout(name)) return 0; return name2LayoutMap[name]; }

			bool			IsHasLayout		(const String& name) { return name2LayoutMap.find(name) != name2LayoutMap.end(); }



			/**
			 *	Methods
			 */
		public:
			void			AddLayout		(Layout* layout);
			void			RemoveLayout	(Layout* layout);

			virtual void	Start			() override;

			virtual void	PreUpdate		() override;
			virtual void	Update			() override;
			virtual void	LateUpdate		() override;

			virtual void	PreRender		() override;
			virtual void	Render			() override;
			virtual void	LateRender		() override;

		};

	}

}