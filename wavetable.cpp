#include "wavetable.h"
#include <parameter.hxx>

#define BASE_FREQ 1.0f
WaveTable::WaveTable(string name, string className,string type):
    SoundGenerator(name,className,type),
    frequency("frequency",BASE_FREQ,880,440),transpose("transpose",-1,1,1),phase("phase",-1,1,0)
{

    mWaveTable=0;
}

WaveTable::~WaveTable()
{

}

void WaveTable::initialize(em_integer samplerate, em_integer periodBufSize)
{
    SoundGenerator::initialize(samplerate,periodBufSize);
    mWaveTableSize=mSamplerate/(BASE_FREQ);
    if(mWaveTableSize!=0)
    {
        mWaveTable=new em_scalar[mWaveTableSize];
    }
    memset(mWaveTable,0,mWaveTableSize*sizeof(em_scalar));
    initWaveform();
    curTablePos=0;
}

void WaveTable::process(em_audio_stream_t buf, em_integer buflen)
{

    curFreq=frequency*transpose;
    float ph=phase()*mWaveTableSize/2;
    for(int i=0;i<buflen;i++)
    {



        float tablepos=(((curTablePos+ph)>=mWaveTableSize)?(curTablePos+ph-mWaveTableSize):(curTablePos+ph));
        tablepos=((tablepos<0)?(mWaveTableSize+tablepos):tablepos);

        int intPos=tablepos;
        float delta=tablepos-intPos;
        buf[i]+=volume()*(mWaveTable[intPos]+delta*(mWaveTable[(intPos==mWaveTableSize-1)?0:(intPos+1)]-mWaveTable[intPos])
                +delta*delta*(mWaveTable[(intPos==0)?(mWaveTableSize-1):(intPos-1)]+mWaveTable[(intPos==mWaveTableSize-1)?0:(intPos+1)]-2*mWaveTable[intPos]));
        //buf[i]*=mWindow[i];
        //buffer[i]*=ampl;
        curTablePos+=curFreq/BASE_FREQ;

        if(curTablePos>=mWaveTableSize)
        {
            curTablePos=0;

        }

    }
    SoundGenerator::process(buf,buflen);
}

void WaveTable::finalize()
{
    SoundGenerator::finalize();
    if(mWaveTable)
        delete [] mWaveTable;
    mWaveTable=0;
    mWaveTableSize=0;
}
