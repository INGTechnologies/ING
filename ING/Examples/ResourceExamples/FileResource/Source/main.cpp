﻿
/**
 *	Include IOStream
 */
#include <iostream>



 /**
  *	Include Application
  */
#include <ING/Application/Application.h>



  /**
   *	Include Thread And Thread Manager
   */
#include <ING/Thread/Thread.h>

#include <ING/Thread/Manager/Manager.h>



/**
 *	Include Event And Event Manager
 */
#include <ING/Event/Event.h>

#include <ING/Event/Manager/Manager.h>



/**
 *	Include Rendering
 */
#include <ING/Rendering/Rendering.h>

using namespace ING::Rendering;



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h> 



/**
 *	Include Resource Manager
 */
#include <ING/Resource/Manager/Manager.h> 



/**
 *	Include File Resource
 */
#include <ING/Resource/File/File.h> 




using namespace ING;



int main() {
	 


	//Create ING Application
	ING::Application::CreateInstance();

	ING::Application::GetInstance()->Init();



	FileResource* fileResource = ResourceManager::GetInstance()->LoadResource<FileResource>(L"Assets/exampleFile.txt");

	fileResource->content += fileResource->content;

	ResourceManager::GetInstance()->SaveResource<FileResource>(fileResource);



	ING::Application::GetInstance()->Run();



	system("pause");
	return 0;
}