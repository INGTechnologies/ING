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
 *	Include Reflection Type
 */
#include <ING/Reflection/Type/Type.h>



namespace ING {

	class IApplication;

	namespace Reflection {

		class Namespace;

		class IType;

		class IClass;

		class IStruct;

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

		List<Reflection::TypeCreator>		typeCreatorList;
		List<Reflection::TypeDestructor>	typeDestructorList;

		std::unordered_map<String, List<Reflection::TypeCreator>::Node*>name2TypeCreatorNodeMap;
		std::unordered_map<String, List<Reflection::TypeDestructor>::Node*>name2TypeDestructorNodeMap;

		bool					isTypesRegistered;

	public:
		Reflection::Context*	GetContext	() { return context; }
		void					SetContext	(Reflection::Context*);
		void					ReleaseContext ();

		const List<Reflection::TypeCreator>& GetTypeCreatorList() { return typeCreatorList; }
		const List<Reflection::TypeDestructor>& GetTypeDestructorList() { return typeDestructorList; }

		bool					IsTypesRegistered () { return isTypesRegistered; }



		/**
		 *	Methods
		 */
	public:
		template<class T>
		void					RegisterType () {

			String typeName = Reflection::IType::TypeInfoToFullName(typeid(T));

			name2TypeCreatorNodeMap[typeName] = typeCreatorList.Add(
			
				[] (Reflection::Context* context) -> Reflection::IType* {

					return T::CreateType(context);

				}
			
			);

			name2TypeDestructorNodeMap[typeName] = typeDestructorList.AddAt(
			
				[] (Reflection::Context* context) -> void {

					T::ReleaseType(context);

				},

				typeDestructorList.GetHeadNode()
			
			);

		}

		template<class T>
		void					UnregisterType() {

			String typeName = Reflection::IType::TypeInfoToFullName(typeid(T));

			typeCreatorList.Remove(name2TypeCreatorNodeMap[typeName]);
			typeDestructorList.Remove(name2TypeDestructorNodeMap[typeName]);

			name2TypeCreatorNodeMap.erase(typeName);
			name2TypeDestructorNodeMap.erase(typeName);

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