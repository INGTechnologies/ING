
/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



int main() {

	ING::Engine::CreateInstance();

	ING::Engine::GetInstance()->Init();

	ING::Engine::GetInstance()->Run();

	return 0;
}