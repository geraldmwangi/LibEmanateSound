#include "soundgenerator.h"
#include <math.h>

SoundGenerator::SoundGenerator(string name, string className, string type)
    :ParameteredObject(name,className,type),volume("volume",0,1)
{
    mWindow=0;
}

SoundGenerator::~SoundGenerator()
{
    finalize();
}

void SoundGenerator::initialize(em_integer samplerate, em_integer periodBufSize)
{
    mSamplerate=samplerate;
    mPeriodBufSize=periodBufSize;
    if(mWindow)
        delete [] mWindow;
    if(mPeriodBufSize!=0)
        mWindow=new float[mPeriodBufSize];
    float a=0.5;
    for(int i=0;i<mPeriodBufSize;i++)
    {
        mWindow[i]=(1-a)/2-1/2*cos(2*M_PI*i/(mPeriodBufSize-1))
                +a/2*cos(4*M_PI*i/(mPeriodBufSize-1));
    }

}

void SoundGenerator::finalize()
{
    if(mWindow)
        delete [] mWindow;
    mWindow=0;
}
