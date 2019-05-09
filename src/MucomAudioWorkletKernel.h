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

public:
	MucomAudioWorkletKernel();

	bool InitializeMucom();

	std::uintptr_t GetAudioBufferPtr() const;
	size_t GetAudioBufferSize() const;

	void Mix();
};

#endif //MUCOM88_MUCOMAUDIOWORKLETKERNEL_H
