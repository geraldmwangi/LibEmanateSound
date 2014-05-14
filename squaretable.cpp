#include "squaretable.h"

SquareTable::SquareTable(string name):
    WaveTable(name,"WaveTable","Square")
{

}

void SquareTable::initWaveform()
{
    for(int i=0;i<mWaveTableSize/2;i++)
        mWaveTable[i]=1;
    for(int i=mWaveTableSize/2;i<mWaveTableSize;i++)
        mWaveTable[i]=-1;


}
