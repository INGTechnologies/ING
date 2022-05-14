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
 *	Include Type
 */
#include <ING\Reflection\Type\Type.h>



namespace ING {

	namespace Reflection {

		class Namespace;

		class IObject;



		enum ClassMemberAccess {

			CLASS_MEMBER_ACCESS_PUBLIC,

			CLASS_MEMBER_ACCESS_PROTECTED,

			CLASS_MEMBER_ACCESS_PRIVATE

		};



		enum ClassMemberTag {

			CLASS_MEMBER_TAG_EDIT_EVERYWHERE

		};



		struct ClassMember {

			size_t				offsetInBytes = 0;

			String				typeName;

			String				name = "";

			ClassMemberAccess	access;

			ClassMemberTag		tag;



			bool IsNull() {

				return name == "";

			}

		};



		class ING_API IClassType : public IType
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IClassType	(const String& name, Namespace* _namespace);
			~IClassType	();



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

		public:
			bool			IsHasMember(const String& name) { return name2MemberMap.find(name) != name2MemberMap.end(); }

			const ClassMember& GetMember(const String& name) {

				if (!IsHasMember(name)) return {};

				return name2MemberMap[name];
			}

			void			SetMember	(const ClassMember& member){

				name2MemberMap[member.name] = member;
			
			}



			/**
			 *	Methods
			 */
		public:
			virtual IObject* CreateInstance();

		};



		template<class T>
		class ClassType : public IClassType {

			/**
			 *	Constructors And Destructor
			 */
		public:
			ClassType(const String& name, Namespace* _namespace) :
				IClassType(name, _namespace)
			{



			}

			~ClassType () {



			}



			/**
			 *	Methods
			 */
		public:
			virtual IObject* CreateInstance() override;

		};

		template<class T>
		IObject* ClassType<T>::CreateInstance() {

			return new T(this);
		}

	}

}



/**
 *	Define Macros
 */
#define ING_REFLECT_CLASS(ClassFullName, ExtendedClassFullName) \
public:\
	friend class ClassType<ClassFullName>;\
\
private:\
	ClassFullName(ING::Reflection::IClassType* _class);\
	\
	~ClassFullName();\
	\
public:\
	static ING::Reflection::ClassType<ClassFullName>*	CreateType		(ING::Reflection::Context* context);\
	static ClassFullName*				CreateInstance	(ING::Reflection::Context* context);

#define ING_BEGIN_REFLECTED_CLASS(ClassFullName, ExtendedClassFullName) \
ClassFullName::ClassFullName	(ING::Reflection::IClassType* _class) : ExtendedClassFullName(_class) {\
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
ClassFullName*	ClassFullName::CreateInstance	(ING::Reflection::Context* context) {\
\
	return new ClassFullName(context->GetClass(ING::Reflection::IType::TypeInfoToFullName(typeid(ClassFullName))));\
\
}\
\
ING::Reflection::ClassType<ClassFullName>* ClassFullName::CreateType(ING::Reflection::Context* context) {\
\
	ING::Utils::String namespaceFullName = ING::Reflection::IType::FullNameToNamespaceName(typeid(ClassFullName).name());\
	ING::Reflection::Namespace* _namespace = context->CreateNamespace(namespaceFullName);\
\
	ING::Utils::String classBaseName = ING::Reflection::IType::FullNameToBaseName(typeid(ClassFullName).name());\
\
	ING::Reflection::ClassType<ClassFullName>* classType = new ING::Reflection::ClassType<ClassFullName>(classBaseName, _namespace);

#define ING_END_REFLECTED_CLASS() \
	return classType;\
}

#define ING_CLASS_PROPERTY(MemberFullName, ...) \
{\
	ING::Utils::String memberBaseName = ING::Reflection::IType::FullNameToBaseName(#MemberFullName);\
	unsigned int memberOffset = GetMemberOffset(&MemberFullName);\
	String typeName = ING::Reflection::IType::TypeInfoToFullName(typeid(MemberFullName));\
	classType->SetMember({ memberOffset, typeName, memberBaseName, ##__VA_ARGS__ });\
}
