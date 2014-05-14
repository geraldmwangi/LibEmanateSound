#ifndef SINUSTABLE_H
#define SINUSTABLE_H
#include <wavetable.h>
class SinusTable : public WaveTable
{
public:
    SinusTable(string name);
protected:
    virtual void initWaveform();
};

#endif // SINUSTABLE_H
