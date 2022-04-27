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
 *	Include ApplicationComponent
 */
#include <ING/Application/Component/Component.h>



namespace ING {

	class IApplication;

	class IWindow;



	class ING_API ApplicationWindowManager : public IApplicationComponent
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ApplicationWindowManager	(IApplication* application);
		~ApplicationWindowManager	();



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
		std::unordered_map<std::string, IWindow*> name2WindowMap;

	public:
		IWindow*			GetWindow		(const std::string& name) { return name2WindowMap[name]; }



		/**
		 *	Methods
		 */
	public:
		void AddWindow		(IWindow* window);
		void RemoveWindow	(IWindow* window);

		virtual void	Start() override;

		virtual void	PreUpdate() override;
		virtual void	Update() override;
		virtual void	LateUpdate() override;

		virtual void	PreRender() override;
		virtual void	Render() override;
		virtual void	LateRender() override;

	};

}