#ifndef SQUARETABLE_H
#define SQUARETABLE_H
#include <wavetable.h>
class SquareTable:public WaveTable
{
public:
    SquareTable(string name);
protected:
    virtual void initWaveform();
};

#endif // SQUARETABLE_H
