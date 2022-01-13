
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
 *	First Example Square Class
 */
class FirstExampleSquare :
	public Singleton<FirstExampleSquare>,
	public Square
{

		/**
		 *	Constructors And Destructor
		 */
	public:
		FirstExampleSquare();
		~FirstExampleSquare();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;

};



/**
 *	Define FirstExampleSquare's Constructors And Destructor
 */
FirstExampleSquare::FirstExampleSquare() {

	

}

FirstExampleSquare::~FirstExampleSquare() {



}



/**
 *	Define FirstExampleSquare's Init, Run, Release Methods
 */
bool FirstExampleSquare::Init() {

	std::cout << "FirstExampleSquare Init" << std::endl;

	return Square::Init();
}

bool FirstExampleSquare::Run() {

	std::cout << "FirstExampleSquare Run" << std::endl;

	return Square::Run();
}

bool FirstExampleSquare::Release() {

	std::cout << "FirstExampleSquare Release" << std::endl;

	return Square::Release();
}






/**
 *	Second Example Square Class
 */
class SecondExampleSquare :
	public Singleton<SecondExampleSquare>,
	public Square
{

	/**
	 *	Constructors And Destructor
	 */
public:
	SecondExampleSquare();
	~SecondExampleSquare();



	/**
	 *	Init, Run, Release Methods
	 */
public:
	virtual bool Init()		override;
	virtual bool Run()		override;
	virtual bool Release()	override;

};



/**
 *	Define SecondExampleSquare's Constructors And Destructor
 */
SecondExampleSquare::SecondExampleSquare() {



}

SecondExampleSquare::~SecondExampleSquare() {



}



/**
 *	Define SecondExampleSquare's Init, Run, Release Methods
 */
bool SecondExampleSquare::Init() {

	std::cout << "SecondExampleSquare Init" << std::endl;

	return Square::Init();
}

bool SecondExampleSquare::Run() {

	std::cout << "SecondExampleSquare Run" << std::endl;

	return Square::Run();
}

bool SecondExampleSquare::Release() {

	std::cout << "SecondExampleSquare Release" << std::endl;

	return Square::Release();
}






/**
 *	Example Board Class
 */
class ExampleBoard : public Board<ExampleBoard> {

	/**
	 *	Constructors And Destructor
	 */
public:
	ExampleBoard();
	~ExampleBoard();



	/**
	 *	Init, Run, Release, Create Methods
	 */
public:
	virtual bool			Init()		override;
	virtual bool			Run()		override;
	virtual bool			Release()	override;

};



/**
 *	Define ExampleBoard's Constructors And Destructor
 */
ExampleBoard::ExampleBoard() {

	/**
	 *	Add Squares
	 */
	AddSquare<FirstExampleSquare>();

	AddSquare<SecondExampleSquare>();

}

ExampleBoard::~ExampleBoard() {



}



/**
 *	Define ExampleBoard's Init, Run, Release Methods
 */
bool ExampleBoard::Init() {

	std::cout << "ExampleBoard Init" << std::endl;

	return Board<ExampleBoard>::Init();
}

bool ExampleBoard::Run() {

	std::cout << "ExampleBoard Run" << std::endl;

	return Board<ExampleBoard>::Run();
}

bool ExampleBoard::Release() {

	std::cout << "ExampleBoard Release" << std::endl;

	return Board<ExampleBoard>::Release();
}



int main() {


	
	ING::Application::CreateInstance();

	ING::Application::GetInstance()->Init();

	ING::Application::GetInstance()->Run();



	ExampleBoard::CreateInstance();

	ExampleBoard::GetInstance()->Init();

	ExampleBoard::GetInstance()->Run();

	ExampleBoard::GetInstance()->Release();



	system("pause");
	return 0;
}