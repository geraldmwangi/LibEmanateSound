#include "soundengine.h"
#include <sinustable.h>
#include <squaretable.h>
#include <sawtable.h>

SoundEngine::SoundEngine()
{
}

void SoundEngine::initialize(em_integer samplerate, em_integer periodBufSize)
{
    mSamplerate=samplerate;
    mPeriodBufSize=periodBufSize;
    for(int i=0;i<mModulators.size();i++)
        mModulators[i]->initialize(samplerate,periodBufSize);
    for(int i=0;i<mListeners.size();i++)
        mListeners[i]->initialize(samplerate,periodBufSize);
}

void SoundEngine::process(int listener,em_audio_stream_t buf, em_integer buflen)
{
    for(int i=0;i<mModulators.size();i++)
        mModulators[i]->process();
    if(listener<mListeners.size())
        mListeners[listener]->process(buf,buflen);
}

void SoundEngine::finalize()
{
    for(int i=0;i<mListeners.size();i++)
        mListeners[i]->finalize();
}

void SoundEngine::addEmanation(string name)
{
    ParameteredObject* obj=mFactory.createParameteredObject(name,"Emanation","Emanation");

    Emanation* em=dynamic_cast<Emanation*>(obj);
    if(em==0)
        throw EmException(name,"Emanation","Emanation");
    em->initialize(mSamplerate,mPeriodBufSize);

    for(int i=0;i<mListeners.size();i++)
        mListeners[i]->addAudioSource(em);

}

void SoundEngine::addListener(string name)
{
    ParameteredObject* obj=mFactory.createParameteredObject(name,"Listener","Listener");
    Listener* listen=dynamic_cast<Listener*>(obj);
    if(listen==0)
        throw EmException(name,"Listener","Listener");
    listen->initialize(mSamplerate,mPeriodBufSize);
    for(int i=0;i<mEmanations.size();i++)
        listen->addAudioSource(mEmanations[i]);
    mListeners.push_back(listen);

}
