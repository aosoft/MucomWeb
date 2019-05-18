#include <emscripten.h>
#include <emscripten/bind.h>

#include <memory>
#include <string>
#include "mucom_module.h"
#include "StreamingPlayer.h"

std::unique_ptr<StreamingPlayer> g_player;

void MainLoop()
{
	if (g_player != nullptr)
	{
		g_player->Process();
	}
}

int main()
{
	emscripten_set_main_loop(MainLoop, 60, 1);
	g_player.release();

	return 0;
}

std::string CompileMML(const std::string& mml)
{
	CMucom mucomCompiler;
	mucomCompiler.Init();
	mucomCompiler.Reset(2);
	if (mucomCompiler.Compile(const_cast<char *>(mml.c_str()), "/mucomCompiler.mub"))
	{
	}
	return std::string(mucomCompiler.GetMessageBuffer());
}

EMSCRIPTEN_BINDINGS(mucom88)
{
	emscripten::function("CompileMML", &CompileMML);
}
