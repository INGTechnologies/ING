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



/**
 *	Include Reflection Class
 */
#include <ING/Reflection/Class/Class.h>



namespace ING {

	class IApplication;

	namespace Reflection {

		class Namespace;

		class Type;

		class IClass;

		class Struct;

		class C_Object;

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

		List<Reflection::ClassCreator>		classCreatorList;
		List<Reflection::ClassDestructor>	classDestructorList;

	public:
		Reflection::Context*	GetContext	() { return context; }
		void					SetContext	(Reflection::Context*);
		void					ReleaseContext ();

		const List<Reflection::ClassCreator>& GetClassCreatorList() { return classCreatorList; }
		const List<Reflection::ClassDestructor>& GetClassDestructorList() { return classDestructorList; }



		/**
		 *	Methods
		 */
	public:
		template<class T>
		void					_RegisterClass () {

			classCreatorList.Add(
			
				[] (Reflection::Context* context) -> Reflection::IClass* {

					return T::CreateType(context);

				}
			
			);

			classDestructorList.AddAt(
			
				[] (Reflection::Context* context) -> void {

					T::ReleaseType(context);

				},

				classDestructorList.GetHeadNode()
			
			);

		}

		virtual void			Start		() override;

		virtual void			PreUpdate	() override;
		virtual void			Update		() override;
		virtual void			LateUpdate	() override;

		virtual void			PreRender	() override;
		virtual void			Render		() override;
		virtual void			LateRender	() override;

	};

}