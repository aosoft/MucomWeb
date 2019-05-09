#include <emscripten.h>
#include <emscripten/bind.h>

#include <cstdint>
#include <string>
#include <stdio.h>
#include "mucom_module.h"
#include "MucomAudioWorkletKernel.h"


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
	emscripten::class_<MucomAudioWorkletKernel>("MucomAudioWorkletKernel")
		.constructor()
		.function("InitializeMucom",&MucomAudioWorkletKernel::InitializeMucom, emscripten::allow_raw_pointers())
		.function("GetAudioBufferPtr", &MucomAudioWorkletKernel::GetAudioBufferPtr, emscripten::allow_raw_pointers())
		.function("GetAudioBufferSize", &MucomAudioWorkletKernel::GetAudioBufferSize)
		.function("Mix", &MucomAudioWorkletKernel::Mix);
}
