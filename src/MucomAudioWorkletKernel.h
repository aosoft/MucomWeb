#ifndef MUCOM88_MUCOMAUDIOWORKLETKERNEL_H
#define MUCOM88_MUCOMAUDIOWORKLETKERNEL_H

#include "mucom_module.h"
#include <cstdint>

class MucomAudioWorkletKernel
{
private:
	const int AudioSampleCount = 128;

	CMucom _mucom;
	std::vector<std::int16_t> _audioBuffer;
	std::vector<float> _audioBufferL;
	std::vector<float> _audioBufferR;

public:
	MucomAudioWorkletKernel();

	bool InitializeMucom();
	void InitializeAudioBuffer();

	std::uintptr_t GetAudioBufferPtrL() const;
	size_t GetAudioBufferSizeL() const;
	std::uintptr_t GetAudioBufferPtrR() const;
	size_t GetAudioBufferSizeR() const;

	void Mix();
};

#endif //MUCOM88_MUCOMAUDIOWORKLETKERNEL_H
