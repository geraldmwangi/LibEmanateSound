#include "sawtable.h"
#include<stdlib.h>
SawTable::SawTable(string name):
    WaveTable(name,"WaveTable","SawTable")
{
}

void SawTable::initWaveform()
{
    //assert(mWaveTableSize>0);
    double slope=2/mWaveTableSize;
    for(int i=0;i<mWaveTableSize;i++)
        mWaveTable[i]=-1+slope*i;


}
