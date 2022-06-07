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



namespace ING {

	namespace Reflection {

		class Namespace;

		class Context;



		template<class T, typename U>
		std::ptrdiff_t GetMemberOffset(U T::* member)
		{
			return reinterpret_cast<std::ptrdiff_t>(
				&(reinterpret_cast<T const volatile*>(NULL)->*member)
			);
		}



		class ING_API IType
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IType	(const String& name, Namespace* _namespace);
			~IType	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			String			name;

			Namespace*		_namespace;

		public:
			const String&	GetName		() { return name; }

			Namespace*		GetNamespace() { return _namespace; }



			/**
			 *	Methods
			 */
		public:
			static String TypeInfoToFullName		(const std::type_info& typeInfo);
			static String FullNameToBaseName		(const String& fullName);
			static String FullNameToBaseName		(const std::type_info& fullName);
			static String FullNameToNamespaceName	(const String& fullName);
			static String FullNameToNamespaceName	(const std::type_info& fullName);

			static String VectorTypeNameToElementTypeName(const String& fullName);

		};



		typedef IType*	(*TypeCreator)		(Context*);
		typedef void	(*TypeDestructor)	(Context*);

	}

}