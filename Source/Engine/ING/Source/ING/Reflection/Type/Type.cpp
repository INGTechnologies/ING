
/**
 *	Include Header
 */
#include "Type.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Namespace
 */
#include <ING/Reflection/Namespace/Namespace.h>



namespace ING {

	namespace Reflection {

		/**
		 *	Constructors And Destructor
		 */
		IType::IType(const String& name, Namespace* _namespace) :
			name(name),
			_namespace(_namespace)
		{

			_namespace->AddType(this);

		}

		IType::~IType() {



		}



		/**
		 *	Release Methods
		 */
		void IType::Release() {

			_namespace->RemoveType(this);

			delete this;
		}



		/**
		 *	Methods
		 */
		String IType::TypeInfoToFullName(const std::type_info& typeInfo) {

			String tiName = typeInfo.name();

			int startingIndex = 0;
			int endIndex = 0;

			int fullNameLength = tiName.length();

			for (int i = 0; i < tiName.length(); ++i) {

				if (
					(tiName[i] == ' ' && tiName.substr(0, i) == "class")
					|| (tiName[i] == ' ' && tiName.substr(0, i) == "enum")
					|| (tiName[i] == ' ' && tiName.substr(0, i) == "struct")
					|| (tiName[i] == ' ' && tiName.substr(0, i) == "union")
				) {

					startingIndex = i + 1;

					break;

				}

			}

			return tiName.substr(startingIndex, tiName.length() - startingIndex);

		}

		String IType::FullNameToBaseName(const String& fullName) {

			int startingIndex = fullName.length() - 1;

			for (int i = startingIndex; i >= 0; i--) {

				if (fullName[i] == ':') {

					break;

				}

				if (
					(fullName[i] == ' ' && fullName.substr(0, i) == "class")
					|| (fullName[i] == ' ' && fullName.substr(0, i) == "enum")
					|| (fullName[i] == ' ' && fullName.substr(0, i) == "struct")
					|| (fullName[i] == ' ' && fullName.substr(0, i) == "union")
				) {

					break;

				}

				startingIndex = i;

			}

			return fullName.substr(startingIndex, fullName.length() - startingIndex);

		}

		String IType::FullNameToNamespaceName(const String& fullName) {

			int cC = 0;

			for (unsigned int i = 0; i < fullName.length(); ++i) {

				if (fullName[i] == ':') {

					cC++;

				}

			}

			if (cC < 2) {

				return "";

			}

			int startingIndex = 0;
			int endIndex = 0;

			int fullNameLength = fullName.length();

			for (int i = 0; i < fullName.length(); ++i) {

				if (
					(fullName[i] == ' ' && fullName.substr(0, i) == "class")
					|| (fullName[i] == ' ' && fullName.substr(0, i) == "enum")
					|| (fullName[i] == ' ' && fullName.substr(0, i) == "struct")
					|| (fullName[i] == ' ' && fullName.substr(0, i) == "union")
				) {

					startingIndex = i + 1;

					break;

				}

			}

			for (int i = fullNameLength; i >= 0; i--) {

				if (fullName[i] == ':') {

					endIndex = i - 2;

					break;

				}

			}

			if (startingIndex <= endIndex) {

				return fullName.substr(startingIndex, endIndex - startingIndex + 1);

			}
			else {

				return "";

			}

		}

		String IType::FullNameToBaseName(const std::type_info& fullName) {

			return FullNameToBaseName(fullName.name());

		}

		String IType::FullNameToNamespaceName(const std::type_info& fullName) {

			return FullNameToNamespaceName(fullName.name());

		}

		String IType::VectorTypeNameToElementTypeName(const String& fullName) {

			unsigned int startIndex = 0;
			unsigned int endIndex = fullName.size() - 1;

			for (; startIndex < endIndex; ++startIndex) {

				if (fullName[startIndex] == '<') {

					++startIndex;

					break;

				}

			}

			unsigned int l = 0;

			for (endIndex = startIndex; endIndex < fullName.size(); ++endIndex) {

				if (fullName[endIndex] == '<' && l == 0) {

					++l;

				}

				if (fullName[endIndex] == '>' && l == 0) {

					--l;

				}

				if (fullName[endIndex] == ',' && l == 0) {

					--endIndex;

					break;

				}

			}

			String elementTypeName = fullName.substr(startIndex, endIndex - startIndex + 1);

			elementTypeName = FullNameToNamespaceName(elementTypeName) + ToString("::") + FullNameToBaseName(elementTypeName);

			return elementTypeName;
		}

	}

}