#include "MucomAudioWorkletKernel.h"

MucomAudioWorkletKernel::MucomAudioWorkletKernel()
{
}

bool MucomAudioWorkletKernel::InitializeMucom()
{
	_mucom.Init();
	_mucom.Reset();
	if (_mucom.LoadMusic("/mucom.mub") < 0 || _mucom.Play(0) < 0)
	{
		return false;
	}

	_audioBuffer.resize(2 * AudioSampleCount);

	return true;
}

std::uintptr_t MucomAudioWorkletKernel::GetAudioBufferPtr() const
{
	return reinterpret_cast<std::uintptr_t >(_audioBuffer.size() > 0 ? &_audioBuffer[0] : nullptr);
}

size_t MucomAudioWorkletKernel::GetAudioBufferSize() const
{
	return _audioBuffer.size();
}

void MucomAudioWorkletKernel::Mix()
{
	_mucom.RenderAudio(&_audioBuffer[0], AudioSampleCount);
}
