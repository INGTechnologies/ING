#pragma once

/**
 *	Include Editor Entry Point
 */
#include <ING\Editor\EntryPoint\EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Map
 */
#include <map>



/**
 *	Include Math
 */
#include <ING/Math/Math.h>



/**
 *	Include UI Element
 */
#include <ING/UI/Element/Element.h>



/**
 *	Include Editor Application
 */
#include <ING/Editor/Application/Application.h>



/**
 *	Include Editor ReflectionSystem
 */
#include <ING/Editor/Application/ReflectionSystem/ReflectionSystem.h>



namespace ING {

	namespace Editor {

		namespace UI {

			class ITab;



			class PLUGIN_API(ING_EDITOR) ITabCreator
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				ITabCreator		(const String & name);
				~ITabCreator	();



				/**
				 *	Release Method
				 */
			public:
				virtual void Release();



				/**
				 *	Properties
				 */
			private:
				String			name;

			public:
				const String&	GetName() { return name; }



				/**
				 *	Methods
				 */
			public:
				virtual ITab* Create(const String& tabName);

			};



			template<class T>
			class TabCreator : public ITabCreator {

				/**
				 *	Constructors And Destructor
				 */
			public:
				TabCreator	(const String& name);
				~TabCreator	();



				/**
				 *	Methods
				 */
			public:
				virtual ITab* Create(const String& tabName) override;

			};

		}

	}

}



namespace ING {

	namespace Editor {

		namespace UI {

			/**
			 *	Constructors And Destructor
			 */
			template<class T>
			TabCreator<T>::TabCreator(const String& name) :
				ITabCreator(name)
			{



			}

			template<class T>
			TabCreator<T>::~TabCreator() {



			}



			/**
			 *	Methods
			 */
			template<class T>
			ITab* TabCreator<T>::Create(const String& tabName) {

				return T::CreateInstance(Editor::Application::GetInstance()->GetReflectionSystem()->GetContext(), tabName);
			}

		}

	}

}