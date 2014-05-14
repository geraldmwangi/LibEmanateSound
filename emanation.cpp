#include "emanation.h"

#include <parameter.hxx>
Emanation::Emanation(string name)
    :ParameteredObject(name,"Emanation","Emanation")
{

}

Emanation::~Emanation()
{
    finalize();
    for(int i=0;i<mGenerators.size();i++)
    {
        delete mGenerators[i];
    }
    mGenerators.clear();

}

void Emanation::initialize(em_integer samplerate, em_integer periodBufSize)
{
    mSamplerate=samplerate;
    mPeriodBufSize=periodBufSize;

    for(int i=0;i<mGenerators.size();i++)
        mGenerators[i]->initialize(samplerate,periodBufSize);
}

void Emanation::process(em_audio_stream_t buf, em_integer buflen)
{
    for(int i=0;i<mGenerators.size();i++)
        mGenerators[i]->process(buf,buflen);
}

void Emanation::finalize()
{
    for(int i=0;i<mGenerators.size();i++)
        mGenerators[i]->finalize();
}

void Emanation::addSoundGenerator(SoundGenerator* gen)
{

    mGenerators.push_back(gen);
}
