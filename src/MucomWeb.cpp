#include <emscripten.h>
#include <emscripten/bind.h>

#include <memory>
#include <vector>
#include <string>
#include "mucom_module.h"
#include "StreamingPlayer.h"

static const int ChannelCount = 2;
static const int SamplesPerBlock = 16;
static const int BufferSampleCount = 32000;

std::unique_ptr<StreamingPlayer> g_player;
std::unique_ptr<CMucom> g_mucom;

std::vector<short> g_audioBuffer;

void MainLoop()
{
	if (g_player != nullptr)
	{
		g_player->Process();
	}
}

int main()
{
	g_audioBuffer.resize(BufferSampleCount * ChannelCount);
	emscripten_set_main_loop(MainLoop, 60, 1);
	g_player.release();
	g_mucom.release();

	return 0;
}

void Process(ALuint buffer, int sampleRate)
{
	int32_t temp2[SamplesPerBlock * ChannelCount];

	int32_t processSampleCount = std::min(BufferSampleCount, (sampleRate + 3) / 4);
	int32_t blockCount = (processSampleCount + (SamplesPerBlock - 1)) / SamplesPerBlock;

	short *p = &g_audioBuffer[0];
	for (int n = 0; n < blockCount; n++)
	{
		g_mucom->RenderAudio(temp2, SamplesPerBlock);
		for (int i = 0; i < SamplesPerBlock * ChannelCount; i++)
		{
			*p = temp2[i];
			p++;
		}
	}
	alBufferData(
			buffer, AL_FORMAT_STEREO16, &g_audioBuffer[0],
			blockCount * SamplesPerBlock * ChannelCount * sizeof(short), sampleRate);
}

std::string CompileMML(const std::string& mml, int sampleRate)
{
	static const char *mubPath = "/mucom.mub";

	CMucom mucomCompiler;
	mucomCompiler.Init();
	mucomCompiler.Reset(2);
	if (mucomCompiler.Compile(const_cast<char *>(mml.c_str()), mubPath) >= 0)
	{
		if (g_player == nullptr)
		{
			g_player = std::make_unique<StreamingPlayer>(&Process);
		}
		g_player->Stop();
		g_mucom = nullptr;
		g_mucom = std::make_unique<CMucom>();
		g_mucom->Init(nullptr, MUCOM_CMPOPT_STEP, sampleRate);
		g_mucom->Reset(0);
		if (g_mucom->LoadMusic(mubPath) >= 0 &&
			g_mucom->Play(0) >= 0)
		{
			g_player->Play(sampleRate);
		}
	}
	return std::string(mucomCompiler.GetMessageBuffer());
}

void StopMusic()
{
	if (g_player != nullptr)
	{
		g_player->Stop();
	}
}

EMSCRIPTEN_BINDINGS(mucom88)
{
	emscripten::function("compileMML", &CompileMML);
	emscripten::function("stopMusic", &StopMusic);
}
