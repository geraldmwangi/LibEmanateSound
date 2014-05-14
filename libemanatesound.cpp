#include "libemanatesound.h"


SoundEngine LibEmanateSound::mEngine;

void LibEmanateSound::initialize(em_integer samplerate, em_integer periodbufsize)
{
    mEngine.initialize(samplerate,periodbufsize);
}

void LibEmanateSound::process(int listener, em_audio_stream_t buf, em_integer buflen)
{
    mEngine.process(listener,buf,buflen);
}

void LibEmanateSound::finalize()
{
    mEngine.finalize();
}

void LibEmanateSound::addEmanation(string name)
{
    mEngine.addEmanation(name);
}

void LibEmanateSound::addListener(string name)
{
    mEngine.addListener(name);
}
