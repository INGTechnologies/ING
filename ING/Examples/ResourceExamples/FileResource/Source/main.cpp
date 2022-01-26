
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



/**
 *	Include Coder
 */
#include <ING/Coder/Coder.h> 




using namespace ING;



class OptimizeCoder : public Coder {

public:
	OptimizeCoder() {



	}
	~OptimizeCoder() {



	}

public:
	virtual std::wstring	Encode(std::wstring content, std::wstring key) override;

	virtual std::wstring	Decode(std::wstring content, std::wstring key) override;

};


std::wstring	OptimizeCoder::Encode(std::wstring content, std::wstring key) {

	std::wstring result = L"";

	std::wstring header = L"";

	std::wstring mws = L"";



	unsigned long	contentLength = content.length();



	wchar_t maxWChr = pow(2, sizeof(wchar_t) * 4) - 1;



	char wchPUl = sizeof(unsigned long) / sizeof(wchar_t);



	unsigned long mwChrOC = 0;

	unsigned long i = 0;

	for (unsigned long ci = 0; ci < contentLength; ci += 2) {

		wchar_t mwChr = content[ci + 1];

		if (mwChr == '1') {

			std::wstring emw = L"";

			for (char j = 0; j < wchPUl; ++j) {

				emw += L' ';

			}

			*((unsigned long*)(emw.c_str())) = i;

			mws += emw;

			mwChrOC++;

		}

		result += content[ci];

		++i;

	}

	for (char j = 0; j < wchPUl; ++j) {

		header += L" ";

	}

	*((unsigned long*)(header.c_str())) = mwChrOC;

	result = header + mws + result;

	return result;

}

std::wstring	OptimizeCoder::Decode(std::wstring content, std::wstring key) {

	std::wstring result = L"";



	char wchPUl = sizeof(unsigned long) / sizeof(wchar_t);



	unsigned long mwChrOC = *((unsigned long*)content.c_str());

	unsigned long* mwChrOCArr = (unsigned long*)malloc(sizeof(unsigned long) * mwChrOC);

	for (unsigned long j = 0; j < mwChrOC; ++j) {

		unsigned long tI = *((unsigned long*)((char*)content.c_str() + sizeof(unsigned long) * (j + 1) ));

		mwChrOCArr[j] = tI;

	}



	unsigned long	contentLength = content.length();



	unsigned long mwI = 0;

	unsigned long i = 0;

	for (unsigned long ci = (1 + mwChrOC) * wchPUl; ci < contentLength; ++ci) {

		result += content[ci];

		if (mwChrOC > 0) {

			if (mwChrOCArr[mwI] == i) {

				result += '1';

				++mwI;

			}
			else {

				result += '0';

			}

		}
		else {

			result += '0';

		}

		++i;

	}



	return result;

}

OptimizeCoder optimizeCoder;








class ExampleCoder : public Coder {

public:
	ExampleCoder() {



	}
	~ExampleCoder() {



	}

public:
	virtual std::wstring	Encode	(std::wstring content, std::wstring key) override;

	virtual std::wstring	Decode	(std::wstring content, std::wstring key) override;

	virtual bool			Check	(std::wstring content, std::wstring key) override;

};






std::wstring	ExampleEncode(std::wstring content, std::wstring key, unsigned int level) {

	std::wstring result = L"";



	unsigned long	contentLength = content.length();

	unsigned long	keyLength = key.length();



	wchar_t maxWChr = pow(2, sizeof(wchar_t) * 4) - 1;



	for (unsigned long i = 0; i < contentLength; ++i) {

		unsigned long keyI = i % keyLength;

		wchar_t wchrI = content[i];

		int newWChr = key[keyI] + content[i];

		if (newWChr > maxWChr) {

			result += (wchar_t)(newWChr - maxWChr);

			result += '1';

		} 
		else{

			result += (wchar_t)newWChr;

			result += '0';

		}

	}


	if (level > 1) {

		result = ExampleEncode(result, key, level - 1);

	}


	return result;

}







std::wstring	ExampleCoder::Encode	(std::wstring content, std::wstring key) {

	std::wstring result = ExampleEncode(content, key, 1);

	result = optimizeCoder.Encode(result,L"");

	return result;

}

std::wstring	ExampleCoder::Decode	(std::wstring content, std::wstring key) {

	std::wstring result = L"";

	std::wstring optimizedContent = optimizeCoder.Decode(content, L"");



	unsigned long	contentLength = optimizedContent.length();

	unsigned long	keyLength = key.length();



	wchar_t maxWChr = pow(2, sizeof(wchar_t) * 4) - 1;



	unsigned long i = 0;

	for (unsigned long ci = 0; ci < contentLength; ci += 2) {

		wchar_t mwChr = optimizedContent[ci + 1];

		int b;



		if (mwChr == '1') {

			b = maxWChr + optimizedContent[ci];

		}
		else {

			b = optimizedContent[ci];

		}



		unsigned long keyI = i % keyLength;

		wchar_t k = key[keyI];

		wchar_t a = b - key[keyI];

		result += a;

		i += 1;

	}

	return result;

}

bool			ExampleCoder::Check	(std::wstring content, std::wstring key) {

	bool result = false;



	return result;

}



int main() {
	 


	//Create ING Application
	ING::Application::CreateInstance();

	ING::Application::GetInstance()->Init();



	FileResource* fileResource = ResourceManager::GetInstance()->LoadResource<FileResource>(L"Assets/exampleFile.txt");


	Debug::Log(fileResource->content);


	ResourceManager::GetInstance()->SaveResource<FileResource>(fileResource);



	ING::Application::GetInstance()->Run();



	system("pause");
	return 0;
}