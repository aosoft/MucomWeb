#include "StreamingPlayer.h"
#include <iterator>

StreamingPlayer::StreamingPlayer(FnStreamingPlayerCallback callback) :
	_callback(callback),
	_device(nullptr),
	_context(nullptr),
	_source(0),
	_isPlaying(false)
{
	_device = alcOpenDevice(nullptr);
	_context = alcCreateContext(_device, nullptr);
	alcMakeContextCurrent(_context);

	alGetError();

	alGenBuffers(2, _buffers);
}

StreamingPlayer::~StreamingPlayer()
{
	Stop();
	if (_buffers[0] != 0)
	{
		alDeleteBuffers(2, _buffers);
	}
	if (_context != nullptr)
	{
		alcDestroyContext(_context);
	}
	if (_device != nullptr)
	{
		alcCloseDevice(_device);
	}
}

void StreamingPlayer::Play()
{
	if (!_isPlaying)
	{
		if (_source != 0)
		{
			alDeleteSources(1, &_source);
		}
		alGenSources(1, &_source);
		alSourcef(_source, AL_GAIN, 1);
		alSource3f(_source, AL_POSITION, 0, 0, 0);

		for (auto buf : _buffers)
		{
			InternalProcess(buf);
		}
		alSourcePlay(_source);
		_isPlaying = true;
	}
}

void StreamingPlayer::Stop()
{
	if (_isPlaying)
	{
		alSourceStop(_source);
		if (_source != 0)
		{
			alDeleteSources(1, &_source);
		}

		_isPlaying = false;
	}
}

void StreamingPlayer::Process()
{
	if (_isPlaying)
	{
		int processed;
		alGetSourcei(_source, AL_BUFFERS_PROCESSED, &processed);
		//printf("procrssed = %d\n", processed);
		while (processed > 0)
		{
			ALuint buffer;
			alSourceUnqueueBuffers(_source, 1, &buffer);
			InternalProcess(buffer);
			processed--;
		}
	}
}

void StreamingPlayer::InternalProcess(ALuint buffer)
{
	(*_callback)(buffer);
	alSourceQueueBuffers(_source, 1, &buffer);
}
