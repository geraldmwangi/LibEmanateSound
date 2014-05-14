#ifndef SAWTABLE_H
#define SAWTABLE_H
#include "wavetable.h"
class SawTable:public WaveTable
{
public:
    SawTable(string name);
protected:
    void initWaveform();
};

#endif // SAWTABLE_H
