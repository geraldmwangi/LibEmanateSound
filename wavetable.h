#ifndef WAVETABLE_H
#define WAVETABLE_H
#include <soundgenerator.h>
class WaveTable:public SoundGenerator
{
public:
    WaveTable(string name, string className,string type);
    ~WaveTable();
    virtual void initialize(em_integer samplerate,em_integer periodBufSize);
    virtual void process(em_audio_stream_t buf,em_integer buflen);
    virtual void finalize();
    TemplatedParameter<float> frequency;
    TemplatedParameter<float> transpose;
    TemplatedParameter<float> phase;
protected:
    virtual void initWaveform()=0;
    float*  mWaveTable;
    int     mWaveTableSize;
private:

    float curTablePos;
    float curFreq;
};

#endif // WAVETABLE_H
