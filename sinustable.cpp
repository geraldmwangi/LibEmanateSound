#include "sinustable.h"
#include <math.h>



SinusTable::SinusTable(string name)
    :WaveTable( name,  "WaveTable", "Sinus")
{

}

void SinusTable::initWaveform()
{
    for(int i=0;i<mWaveTableSize;i++)
        mWaveTable[i]=sin(2*M_PI*i/(mWaveTableSize));


}
