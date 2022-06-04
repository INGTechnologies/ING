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
 *	Include ObjectFunction
 */
#include <ING\Reflection\Object\Function\Function.h>



/**
 *	Include ObjectProcedure
 */
#include <ING\Reflection\Object\Procedure\Procedure.h>



namespace ING {

	namespace Reflection {

		class Namespace;

		class C_Object;

		class IObjectFunction;

		class IObjectProcedure;

		struct StructMember;



		struct S_Base {



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
			StructMember& ACCESS (StructMemberAccess access) {

				this->access = access;

				return *(this);
			}

			StructMember& TAG	(StructMemberTag tag) {

				this->tag = tag;

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

			void			SetMember	(const StructMember& member){

				name2MemberMap[member.name] = member;
			
			}

			IStruct*		GetBase () { return base; }

			Context*		GetContext () { return context; }

			unsigned int	GetSize () { return size; }

		};



		template<class T>
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
	static ING::Utils::String	TypeName		();

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
ING::Utils::String className = ING::Reflection::IType::TypeInfoToFullName(typeid(StructFullName));\
\
ING::Reflection::IStruct* _class = context->GetStruct(className);\
_class->Release();\
\
}\
\
ING::Reflection::Struct<StructFullName>* StructFullName::GetType(ING::Reflection::Context* context) {\
\
	ING::Utils::String namespaceFullName = ING::Reflection::IType::FullNameToNamespaceName(typeid(StructFullName).name());\
	ING::Reflection::Namespace* _namespace = context->CreateNamespace(namespaceFullName);\
\
	ING::Utils::String classBaseName = ING::Reflection::IType::FullNameToBaseName(typeid(StructFullName).name());\
\
	return (ING::Reflection::Struct<StructFullName>*)context->GetStruct(ING::Reflection::IType::TypeInfoToFullName(typeid(StructFullName)));\
\
}\
\
ING::Reflection::Struct<StructFullName>* StructFullName::CreateType(ING::Reflection::Context* context) {\
\
	ING::Utils::String namespaceFullName = ING::Reflection::IType::FullNameToNamespaceName(typeid(StructFullName).name());\
	ING::Reflection::Namespace* _namespace = context->CreateNamespace(namespaceFullName);\
\
	ING::Utils::String classBaseName = ING::Reflection::IType::FullNameToBaseName(typeid(StructFullName).name());\
\
	ING::Reflection::Struct<StructFullName>* classType = new ING::Reflection::Struct<StructFullName>(\
		classBaseName,\
		_namespace,\
		context->GetStruct(ING::Reflection::IType::TypeInfoToFullName(typeid(ExtendedStructFullName)))\
	);\
\
	ING::Reflection::StructMember currentMember;\
\

#define ING_END_REFLECTED_STRUCT() \
	return classType;\
}

#define ING_STRUCT_PROPERTY(StructFullName, MemberBaseName, ...) \
{\
	unsigned int memberOffset = GetMemberOffset(&StructFullName::##MemberBaseName);\
	String typeName = ING::Reflection::IType::TypeInfoToFullName(typeid(StructFullName::##MemberBaseName));\
	currentMember = { \
		memberOffset, \
		typeName, \
		#MemberBaseName, \
		##__VA_ARGS__ \
	};\
	classType->SetMember(currentMember);\
}\
currentMember