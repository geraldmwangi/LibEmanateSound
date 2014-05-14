#include "listener.h"

Listener::Listener(string name)
    :ParameteredObject(name,"Listener","Listener")
{
}

Listener::~Listener()
{
    finalize();
}

void Listener::initialize(em_integer samplerate, em_integer periodBufSize)
{
    mSamplerate=samplerate;
    mPeriodBufSize=periodBufSize;
    for(int i=0;i<mAudioSources.size();i++)
        mAudioSources[i]->initialize(samplerate,periodBufSize);

}

void Listener::process(em_audio_stream_t buf, em_integer buflen)
{
    for(int i=0;i<mAudioSources.size();i++)
        mAudioSources[i]->process(buf,buflen);
}

void Listener::finalize()
{
    for(int i=0;i<mAudioSources.size();i++)
        mAudioSources[i]->finalize();
}

void Listener::addAudioSource(AudioSourceIntf *source)
{
    source->initialize(mSamplerate,mPeriodBufSize);
    mAudioSources.push_back(source);

}
