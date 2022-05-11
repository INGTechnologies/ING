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

		class Window;



		class PLUGIN_API(ING_EDITOR) ApplicationWindowSystem : public IApplicationComponent
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ApplicationWindowSystem	(IApplication* application);
			~ApplicationWindowSystem();



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
			std::unordered_map<String, Window*> name2WindowMap;

		public:
			Window*			GetWindow		(const String& name) { return name2WindowMap[name]; }



			/**
			 *	Methods
			 */
		public:
			void			AddWindow		(Window* window);
			void			RemoveWindow	(Window* window);

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