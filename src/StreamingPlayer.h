#ifndef MUCOM88_STREAMINGPLAYER_H
#define MUCOM88_STREAMINGPLAYER_H

#include <cstdint>
#include <AL/al.h>
#include <AL/alc.h>

typedef void (*FnStreamingPlayerCallback)(ALuint buffer, int sampleRate);

class StreamingPlayer
{
private:
	static const int BufferCount = 2;

	ALCdevice *_device;
	ALCcontext *_context;
	ALuint _buffers[BufferCount];
	ALuint _source;
	int _sampleRate;

	bool _isPlaying;
	FnStreamingPlayerCallback _callback;
public:
	StreamingPlayer(FnStreamingPlayerCallback callback);
	~StreamingPlayer();

	bool IsPlaying() const
	{
		return _isPlaying;
	}

	void Play(int sampleRate);
	void Stop();
	void Process();

private:
	void InternalProcess(ALuint buffer);
};


#endif //MUCOM88_STREAMINGPLAYER_H
