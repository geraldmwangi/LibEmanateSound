#include "sinusmodulator.h"
#include <math.h>
SinusModulator::SinusModulator(string name)
    :ParameterModulator(name,"SinusModulator")
{
}


void SinusModulator::initModulationTable()
{
    for(int i=0;i<mModTableSize;i++)
        mModTable[i]=sin(2*M_PI*i/(mModTableSize));
}
