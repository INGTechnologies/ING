#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include ApplicationComponent
 */
#include <ING/Application/Component/Component.h>



namespace ING {

	class IApplication;

	namespace Reflection {

		class Namespace;

		class Type;

		class Class;

		class Struct;

		class IObject;

		class Context;

	}

	class ING_API ApplicationReflectionSystem : public IApplicationComponent
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ApplicationReflectionSystem		(IApplication* application);
		~ApplicationReflectionSystem	();



		/**
		 *	Init, Release Methods
		 */
	public:
		virtual bool Init();
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		Reflection::Context*	context;

	public:
		Reflection::Context*	GetContext	() { return context; }
		void					SetContext	(Reflection::Context*);
		void					ReleaseContext ();



		/**
		 *	Methods
		 */
	public:
		virtual void			Start		() override;

		virtual void			PreUpdate	() override;
		virtual void			Update		() override;
		virtual void			LateUpdate	() override;

		virtual void			PreRender	() override;
		virtual void			Render		() override;
		virtual void			LateRender	() override;

	};

}