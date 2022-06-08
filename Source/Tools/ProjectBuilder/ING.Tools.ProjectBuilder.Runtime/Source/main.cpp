
/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING;
using namespace ING::Utils;



/**
 *	Include ProjectBuilder
 */
#include <ING/Tools/ProjectBuilder/ProjectBuilder.h>



#ifdef USE_MSVC
int wmain(int argc, wchar_t* argv_cstr[], wchar_t* envp[])
{

	std::vector<WString> argv(argc);

	for (unsigned int i = 0; i < argc; ++i) {

		argv[i] = ToWString(argv_cstr[i]);

	}

	Tools::ProjectBuilder* builder = new Tools::ProjectBuilder(argv);

	builder->Build();

	builder->Release();

	return 0;
}
#endif