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

	return true;
}

void MucomAudioWorkletKernel::InitializeAudioBuffer()
{
	_audioBuffer.resize(2 * AudioSampleCount);
	_audioBufferL.resize(AudioSampleCount);
	_audioBufferR.resize(AudioSampleCount);
}

std::uintptr_t MucomAudioWorkletKernel::GetAudioBufferPtrL() const
{
	return reinterpret_cast<std::uintptr_t >(_audioBufferL.size() > 0 ? &_audioBufferL[0] : nullptr);
}

size_t MucomAudioWorkletKernel::GetAudioBufferSizeL() const
{
	return _audioBufferL.size();
}

std::uintptr_t MucomAudioWorkletKernel::GetAudioBufferPtrR() const
{
	return reinterpret_cast<std::uintptr_t >(_audioBufferR.size() > 0 ? &_audioBufferR[0] : nullptr);
}

size_t MucomAudioWorkletKernel::GetAudioBufferSizeR() const
{
	return _audioBufferR.size();
}

void MucomAudioWorkletKernel::Mix()
{
	_mucom.RenderAudio(&_audioBuffer[0], AudioSampleCount);
	for (size_t i = 0; i < AudioSampleCount; i++)
	{
		_audioBufferL[i] = static_cast<float>(_audioBuffer[i * 2]) / 32767.0f;
		_audioBufferR[i] = static_cast<float>(_audioBuffer[i * 2 + 1]) / 32767.0f;
	}
}
