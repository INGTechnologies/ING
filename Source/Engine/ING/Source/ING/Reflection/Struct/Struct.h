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
 *	Include Function
 */
#include <ING\Reflection\Function\Function.h>



/**
 *	Include Procedure
 */
#include <ING\Reflection\Procedure\Procedure.h>



/**
 *	Include Nlohmann JSON
 */
#include <nlohmann/json.hpp>



namespace ING {

	namespace Reflection {

		class Namespace;

		class C_Object;

		class IObjectFunction;

		class IObjectProcedure;

		struct StructMember;



		struct S_Object {



		};



		enum StructMemberAccess {

			STRUCT_MEMBER_ACCESS_PRIVATE = 0x0,

			STRUCT_MEMBER_ACCESS_PROTECTED = 0x1,

			STRUCT_MEMBER_ACCESS_PUBLIC = 0x2

		};



		enum StructMemberTag {

			STRUCT_MEMBER_TAG_EDIT_EVERYWHERE = 0x0,

			STRUCT_MEMBER_TAG_VISIBLE_EVERYWHERE = 0x1,

			STRUCT_MEMBER_TAG_NO_EDIT = 0x2

		};



		struct StructMember {

			size_t				offsetInBytes = 0;

			TypeGroup			typeGroup = TYPE_GROUP_NONE;

			String				typeName;

			String				name = "";

			StructMemberAccess	access = STRUCT_MEMBER_ACCESS_PUBLIC;

			StructMemberTag		tag = STRUCT_MEMBER_TAG_EDIT_EVERYWHERE;



			bool IsNull() {

				return name == "";

			}



			/**
			 *	To Use With Macros
			 */
			StructMember& TYPE_GROUP(TypeGroup _typeGroup) {

				this->typeGroup = _typeGroup;

				return *(this);
			}

			StructMember& ACCESS (StructMemberAccess _access) {

				this->access = _access;

				return *(this);
			}

			StructMember& TAG	(StructMemberTag _tag) {

				this->tag = _tag;

				return *(this);
			}

		};



		class ING_API IStruct : public IType
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IStruct	(const String& name, Namespace* _namespace, IStruct* base, unsigned int size);
			~IStruct();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() override;



			/**
			 *	Properties
			 */
		private:
			std::unordered_map<String, StructMember> name2MemberMap;
			IStruct*		base;
			Context*		context;
			unsigned int	size;

		public:
			const std::unordered_map<String, StructMember>& GetName2MemberMap () { return name2MemberMap; }

			bool			IsHasMember(const String& name) { return name2MemberMap.find(name) != name2MemberMap.end(); }

			const StructMember& GetMember(const String& name) {

				if (!IsHasMember(name)) return {};

				return name2MemberMap[name];
			}

			StructMember&	GetMemberReference (const String& name) {

				if (!IsHasMember(name)) {

					StructMember noneMember;

					return noneMember;
				
				}

				return name2MemberMap[name];
			}

			void			SetMember	(const StructMember& member){

				name2MemberMap[member.name] = member;
			
			}

			IStruct*		GetBase () { return base; }

			Context*		GetContext () { return context; }

			unsigned int	GetSize () { return size; }

		};



		template<typename T>
		class Struct : public IStruct {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Struct(const String& name, Namespace* _namespace, IStruct* base) :
				IStruct(name, _namespace, base, sizeof(T))
			{



			}

			Struct(const String& name, Namespace* _namespace) :
				IStruct(name, _namespace, 0)
			{



			}

			~Struct() {



			}



			/**
			 *	Methods
			 */
		public:
			template<typename... TArgs>
			T			  CreateInstance(TArgs... args) {

				return T(this, args...);

			}

		};

	}

}



/**
 *	Define Macros
 */
#define ING_REFLECT_STRUCT(StructFullName, ExtendedStructFullName) \
public:\
	friend class ING::Reflection::Struct<StructFullName>;\
\
public:\
	static ING::Reflection::Struct<StructFullName>*	CreateType		(ING::Reflection::Context* context);\
	static void					ReleaseType		(ING::Reflection::Context* context);\
	static ING::Reflection::Struct<StructFullName>*	GetType			(ING::Reflection::Context* context);\
	template<typename... TArgs>\
	static StructFullName		CreateInstance	(TArgs... args) {\
		return {args...};\
	}\
	\
	static ING::Utils::String	TypeName		();\
	\


#define ING_BEGIN_REFLECTED_STRUCT(StructFullName, ExtendedStructFullName) \
\
ING::Utils::String	StructFullName::TypeName	() {\
\
	return ING::Reflection::IType::TypeInfoToFullName(typeid(StructFullName));\
\
}\
\
void StructFullName::ReleaseType(ING::Reflection::Context * context) {\
\
	if (context == 0) context = ING::Reflection::Engine::GetInstance()->GetMainContext();\
\
ING::Utils::String className = ING::Reflection::IType::TypeInfoToFullName(typeid(StructFullName));\
\
ING::Reflection::IStruct* _class = context->GetStruct(className);\
_class->Release();\
\
}\
\
ING::Reflection::Struct<StructFullName>* StructFullName::GetType(ING::Reflection::Context* context) {\
\
	if (context == 0) context = ING::Reflection::Engine::GetInstance()->GetMainContext();\
\
	ING::Utils::String namespaceFullName = ING::Reflection::IType::FullNameToNamespaceName(typeid(StructFullName).name());\
	ING::Reflection::Namespace* _namespace = context->CreateNamespace(namespaceFullName);\
\
	ING::Utils::String structBaseName = ING::Reflection::IType::FullNameToBaseName(typeid(StructFullName).name());\
\
	return (ING::Reflection::Struct<StructFullName>*)context->GetStruct(ING::Reflection::IType::TypeInfoToFullName(typeid(StructFullName)));\
\
}\
\
ING::Reflection::Struct<StructFullName>* StructFullName::CreateType(ING::Reflection::Context* context) {\
\
	if (context == 0) context = ING::Reflection::Engine::GetInstance()->GetMainContext();\
\
	ING::Utils::String structFullName = ING::Reflection::IType::TypeInfoToFullName(typeid(StructFullName));\
\
	if (context->IsHasStruct(structFullName)) return (ING::Reflection::Struct<StructFullName>*)context->GetStruct(structFullName);\
\
	ING::Utils::String namespaceFullName = ING::Reflection::IType::FullNameToNamespaceName(typeid(StructFullName).name());\
	ING::Reflection::Namespace* _namespace = context->CreateNamespace(namespaceFullName);\
\
	ING::Utils::String structBaseName = ING::Reflection::IType::FullNameToBaseName(typeid(StructFullName).name());\
\
	ING::Reflection::Struct<StructFullName>* structType = new ING::Reflection::Struct<StructFullName>(\
		structBaseName,\
		_namespace,\
		context->GetStruct(ING::Reflection::IType::TypeInfoToFullName(typeid(ExtendedStructFullName)))\
	);\
\
	ING::Reflection::StructMember currentMember;\
\

#define ING_END_REFLECTED_STRUCT() \
	return structType;\
}

#define ING_STRUCT_PROPERTY(StructFullName, MemberBaseName, ...) \
{\
	unsigned int memberOffset = GetMemberOffset(&StructFullName::##MemberBaseName);\
	String typeName = ING::Reflection::IType::TypeInfoToFullName(typeid(StructFullName::##MemberBaseName));\
	currentMember = { \
		memberOffset, \
		ING::Reflection::TYPE_GROUP_NONE, \
		typeName, \
		#MemberBaseName, \
		##__VA_ARGS__ \
	};\
	structType->SetMember(currentMember);\
}\
structType->GetMemberReference(currentMember.name)