
/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



#ifdef USE_MSVC
int wmain(int argc, wchar_t* argv_cstr[], wchar_t* envp[])
{

	std::vector<WString> argv(argc);

	for (unsigned int i = 0; i < argc; ++i) {

		argv[i] = ToWString(argv_cstr[i]);

	}

	ING::Engine::CreateInstance(argv);

	if (!ING::Engine::GetInstance()->Init()) return 1;

	if (!ING::Engine::GetInstance()->Run()) return 1;

	return 0;
}
#endif