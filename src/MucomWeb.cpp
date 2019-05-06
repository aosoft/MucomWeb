#include <emscripten.h>
#include <emscripten/bind.h>

#include <string>
#include "mucom_module.h"


std::string CompileMML(const std::string& mml)
{
	CMucom mucom;
	mucom.Init();
	mucom.Reset(2);
	if (mucom.Compile(const_cast<char *>(mml.c_str()), "/mucom.mub"))
	{
	}
	return std::string(mucom.GetMessageBuffer());
}

EMSCRIPTEN_BINDINGS(mucom88)
{
	emscripten::function("CompileMML", &CompileMML);
}
