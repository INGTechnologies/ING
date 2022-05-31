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

		struct ClassMember;



		enum StructMemberAccess {

			CLASS_MEMBER_ACCESS_PRIVATE = 0x0,

			CLASS_MEMBER_ACCESS_PROTECTED = 0x1,

			CLASS_MEMBER_ACCESS_PUBLIC = 0x2

		};



		enum StructMemberTag {

			CLASS_MEMBER_TAG_EDIT_EVERYWHERE = 0x0,

			CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE = 0x1,

			CLASS_MEMBER_TAG_NO_EDIT = 0x2

		};



		struct StructMember {

			size_t				offsetInBytes = 0;

			String				typeName;

			String				name = "";

			StructMemberAccess	access;

			StructMemberTag		tag;



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
				IStruct(name, _namespace, base)
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