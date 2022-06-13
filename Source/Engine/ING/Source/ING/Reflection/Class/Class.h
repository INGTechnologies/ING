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
 *	Include Debug
 */
#include <ING\_Debug/Debug.h>



/**
 *	Include Type
 */
#include <ING\Reflection\Type\Type.h>



/**
 *	Include TypeGroup
 */
#include <ING\Reflection\TypeGroup\TypeGroup.h>



/**
 *	Include ObjectFunction
 */
#include <ING\Reflection\Object\Function\Function.h>



/**
 *	Include ObjectProcedure
 */
#include <ING\Reflection\Object\Procedure\Procedure.h>



/**
 *	Include Function
 */
#include <ING\Reflection\Function\Function.h>



/**
 *	Include Procedure
 */
#include <ING\Reflection\Procedure\Procedure.h>



namespace ING {

	namespace Reflection {

		class Namespace;

		class C_Object;

		class IFunction;

		class IObjectFunction;

		class IProcedure;

		class IObjectProcedure;

		struct ClassMember;



		enum ClassMemberAccess {

			CLASS_MEMBER_ACCESS_PRIVATE = 0x0,

			CLASS_MEMBER_ACCESS_PROTECTED = 0x1,

			CLASS_MEMBER_ACCESS_PUBLIC = 0x2

		};



		enum ClassMemberTag {

			CLASS_MEMBER_TAG_EDIT_EVERYWHERE = 0x0,

			CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE = 0x1,

			CLASS_MEMBER_TAG_NO_EDIT = 0x2

		};



		struct ClassMember {

			unsigned int		memberType = 0;

			TypeGroup			typeGroup = ING::Reflection::TYPE_GROUP_NONE;

			size_t				offsetInBytes = 0;

			String				typeName;

			IObjectFunction*	(*functionCreator)(C_Object* object);
			IObjectProcedure*	(*procedureCreator)(C_Object* object);

			String				name = "";

			ClassMemberAccess	access = CLASS_MEMBER_ACCESS_PRIVATE;

			ClassMemberTag		tag = CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE;



			bool IsNull() {

				return name == "";

			}



			/**
			 *	To Use With Macros
			 */
			ClassMember& TYPE_GROUP(TypeGroup _typeGroup) {

				this->typeGroup = _typeGroup;

				return *(this);
			}

			ClassMember& ACCESS (ClassMemberAccess _access) {

				this->access = _access;

				return *(this);
			}

			ClassMember& TAG	(ClassMemberTag _tag) {

				this->tag = _tag;

				return *(this);
			}

		};



		template<class T, typename... TArgs>
		void InstanceConstructorCaller(T* object, TArgs... args) {

			object->GetProcedure("Constructor")->Specify<T*, TArgs...>()->Invoke(object, args...);

		}



		class ING_API IClass : public IType
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IClass	(const String& name, Namespace* _namespace, IClass* base);
			~IClass	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() override;



			/**
			 *	Properties
			 */
		private:
			std::unordered_map<String, ClassMember> name2MemberMap;
			IClass*			base;
			Context*		context;

		private:
			IProcedure*		instanceConstructorCaller;

		public:
			const std::unordered_map<String, ClassMember>& GetName2MemberMap () { return name2MemberMap; }

			bool			IsHasMember(const String& name) { return name2MemberMap.find(name) != name2MemberMap.end(); }

			const ClassMember& GetMember(const String& name) {

				if (!IsHasMember(name)) return {};

				return name2MemberMap[name];
			}

			ClassMember&	GetMemberReference (const String& name) {

				if (!IsHasMember(name)) {

					ClassMember noneMember;

					return noneMember;
				
				}

				return name2MemberMap[name];
			}

			void			SetMember	(const ClassMember& member){

				name2MemberMap[member.name] = member;
			
			}

			IClass*			GetBase () { return base; }

			Context*		GetContext () { return context; }

			template<class T, typename... TArgs>
			void			SetInstanceConstructorCaller() {

				if (instanceConstructorCaller != 0) {

					instanceConstructorCaller->Release();

				}

				instanceConstructorCaller = new Procedure<
					InstanceConstructorCaller<T, TArgs...>,
					T*, TArgs...
				>();

			}

			IProcedure*	GetInstanceConstructorCaller() {

				return instanceConstructorCaller;

			}



			/**
			 *	Methods
			 */
		protected:
			virtual C_Object* IMalloc();
			
			IObjectProcedure* GetConstructor(C_Object* object);

		public:
			virtual C_Object* ICreateInstance();

			template<typename... TArgs>
			C_Object*		  RCreateInstance(TArgs... args) {

				if (!IsHasMember("Constructor")) {

					Debug::Error(GetName() + " Does Not Has Any Constructor");

					return 0;
				}

				C_Object* result = IMalloc();

				GetConstructor(result)->Specify<TArgs...>()->Invoke(args...);

				return result;

			}

		};



		template<class T>
		class Class : public IClass {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Class(const String& name, Namespace* _namespace, IClass* base) :
				IClass(name, _namespace, base)
			{



			}

			Class(const String& name, Namespace* _namespace) :
				IClass(name, _namespace, 0)
			{



			}

			~Class () {



			}



			/**
			 *	Methods
			 */
		public:
			virtual C_Object* IMalloc() override;

			virtual C_Object* ICreateInstance() override;

			template<typename... TArgs>
			T*				 CreateInstance(TArgs... args) {

				if (!IsHasMember("Constructor")) {

					Debug::Error(String(IType::TypeInfoToFullName(typeid(T))) + " Does Not Has Any Constructor");

					return 0;
				}

				T* result = (T*)IMalloc();

				result->Constructor(args...);

				return result;

			}

		};

		template<class T>
		C_Object* Class<T>::IMalloc() {

			return new T(this);
		}

		template<class T>
		C_Object* Class<T>::ICreateInstance() {

			if (!IsHasMember("Constructor")) {

				Debug::Error(String(IType::TypeInfoToFullName(typeid(T))) + " Does Not Has Any Constructor");

				return 0;
			}

			T* result = (T*)IMalloc();

			result->GetFunction("Constructor")->Invoke();
		
			return result;
		}

	}

}



/**
 *	Define Macros
 */
#define ING_REFLECT_CLASS(ClassFullName, ExtendedClassFullName) \
public:\
	friend class ING::Reflection::Class<ClassFullName>;\
\
protected:\
	ClassFullName(ING::Reflection::IClass* _class);\
	\
	~ClassFullName();\
	\
public:\
	static ING::Reflection::Class<ClassFullName>*	CreateType		(ING::Reflection::Context* context);\
	static void					ReleaseType		(ING::Reflection::Context* context);\
	static ING::Reflection::Class<ClassFullName>*	GetType			(ING::Reflection::Context* context);\
	static ClassFullName*		ICreateInstance	(ING::Reflection::Context* context);\
	template<typename... TArgs>\
	static ClassFullName*		CreateInstance	(ING::Reflection::Context* context, TArgs... args) {\
		\
		if (context == 0) context = ING::Reflection::Engine::GetInstance()->GetMainContext();\
		\
		return ((ING::Reflection::Class<ClassFullName>*)(context->GetClass(ING::Reflection::IType::TypeInfoToFullName(typeid(ClassFullName)))))->CreateInstance(args...);\
	}\
	\
	static ING::Utils::String	TypeName		();

#define ING_BEGIN_REFLECTED_CLASS(ClassFullName, ExtendedClassFullName) \
ClassFullName::ClassFullName	(ING::Reflection::IClass* _class) : ExtendedClassFullName(_class) {\
\
\
\
}\
\
ClassFullName::~ClassFullName	()  {\
\
\
\
}\
\
ClassFullName*	ClassFullName::ICreateInstance	(ING::Reflection::Context* context) {\
\
	if (context == 0) context = ING::Reflection::Engine::GetInstance()->GetMainContext();\
\
	return (ClassFullName*)((ING::Reflection::Class<ClassFullName>*)(context->GetClass(ING::Reflection::IType::TypeInfoToFullName(typeid(ClassFullName)))))->ICreateInstance();\
\
}\
\
ING::Utils::String	ClassFullName::TypeName	() {\
\
	return ING::Reflection::IType::TypeInfoToFullName(typeid(ClassFullName));\
\
}\
\
void ClassFullName::ReleaseType(ING::Reflection::Context * context) {\
\
	if (context == 0) context = ING::Reflection::Engine::GetInstance()->GetMainContext();\
\
ING::Utils::String className = ING::Reflection::IType::TypeInfoToFullName(typeid(ClassFullName));\
\
ING::Reflection::IClass* _class = context->GetClass(className);\
_class->Release();\
\
}\
\
ING::Reflection::Class<ClassFullName>* ClassFullName::GetType(ING::Reflection::Context* context) {\
\
	if (context == 0) context = ING::Reflection::Engine::GetInstance()->GetMainContext();\
\
	ING::Utils::String namespaceFullName = ING::Reflection::IType::FullNameToNamespaceName(typeid(ClassFullName).name());\
	ING::Reflection::Namespace* _namespace = context->CreateNamespace(namespaceFullName);\
\
	ING::Utils::String classBaseName = ING::Reflection::IType::FullNameToBaseName(typeid(ClassFullName).name());\
\
	return (ING::Reflection::Class<ClassFullName>*)context->GetClass(ING::Reflection::IType::TypeInfoToFullName(typeid(ClassFullName)));\
\
}\
\
ING::Reflection::Class<ClassFullName>* ClassFullName::CreateType(ING::Reflection::Context* context) {\
\
	if (context == 0) context = ING::Reflection::Engine::GetInstance()->GetMainContext();\
\
	ING::Utils::String classFullName = ING::Reflection::IType::TypeInfoToFullName(typeid(ClassFullName));\
\
	if (context->IsHasClass(classFullName)) return (ING::Reflection::Class<ClassFullName>*)context->GetClass(classFullName);\
\
	ING::Utils::String namespaceFullName = ING::Reflection::IType::FullNameToNamespaceName(typeid(ClassFullName).name());\
	ING::Reflection::Namespace* _namespace = context->CreateNamespace(namespaceFullName);\
\
	ING::Utils::String classBaseName = ING::Reflection::IType::FullNameToBaseName(typeid(ClassFullName).name());\
\
	ING::Reflection::Class<ClassFullName>* classType = new ING::Reflection::Class<ClassFullName>(\
		classBaseName,\
		_namespace,\
		context->GetClass(ING::Reflection::IType::TypeInfoToFullName(typeid(ExtendedClassFullName)))\
	);\
\
	ING::Reflection::ClassMember currentMember;\
\

#define ING_END_REFLECTED_CLASS() \
	return classType;\
}

#define ING_CLASS_PROPERTY(ClassFullName, MemberBaseName, ...) \
{\
	unsigned int memberOffset = GetMemberOffset(&ClassFullName::##MemberBaseName);\
	String typeName = ING::Reflection::IType::TypeInfoToFullName(typeid(ClassFullName::##MemberBaseName));\
	currentMember = { \
		0, \
		ING::Reflection::TYPE_GROUP_NONE, \
		memberOffset, \
		typeName, \
		[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectFunction*{return 0;}, \
		[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectProcedure*{return 0;}, \
		#MemberBaseName, \
		##__VA_ARGS__ \
	};\
	classType->SetMember(currentMember);\
}\
classType->GetMemberReference(currentMember.name)

#define ING_CLASS_FUNCTION(ClassFullName, MemberBaseName, ...) \
{\
	currentMember = { 1, ING::Reflection::TYPE_GROUP_NONE, 0, "",\
		[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectFunction*{\
				return new ING::Reflection::ObjectFunction<ClassFullName, &ClassFullName::##MemberBaseName,##__VA_ARGS__>((ClassFullName*)object); \
		},\
		[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectProcedure*{return 0;}, \
		#MemberBaseName\
	};\
	classType->SetMember(currentMember);\
}\
classType->GetMemberReference(currentMember.name)

#define ING_CLASS_PROCEDURE(ClassFullName, MemberBaseName, ...) \
{\
	currentMember = { 2, ING::Reflection::TYPE_GROUP_NONE, 0, "",\
		[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectFunction*{return 0;}, \
		[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectProcedure*{\
				return new ING::Reflection::ObjectProcedure<ClassFullName, &ClassFullName::##MemberBaseName,##__VA_ARGS__>((ClassFullName*)object); \
		},\
		#MemberBaseName\
	};\
	classType->SetMember(currentMember);\
}\
classType->GetMemberReference(currentMember.name)

#define ING_CLASS_CONSTRUCTOR(ClassFullName, ...) \
{\
	currentMember = { 2, ING::Reflection::TYPE_GROUP_NONE, 0, "",\
		[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectFunction*{return 0;}, \
		[](ING::Reflection::C_Object* object)->ING::Reflection::IObjectProcedure*{\
				return new ING::Reflection::ObjectProcedure<ClassFullName, &ClassFullName::Constructor,##__VA_ARGS__>((ClassFullName*)object); \
		},\
		"Constructor"\
	};\
	classType->SetMember(currentMember);\
	classType->SetInstanceConstructorCaller<ClassFullName, ##__VA_ARGS__>(); \
}\
classType->GetMemberReference(currentMember.name)

