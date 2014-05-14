#ifndef EMANATION_H
#define EMANATION_H
#include <AudioSourceIntf.h>
#include <soundgenerator.h>
#include <vector>
#include "parameteredobject.h"
#include <map>
using namespace std;
class Emanation : public AudioSourceIntf,public ParameteredObject
{
public:
    Emanation(string name);
    ~Emanation();
    virtual void initialize(em_integer samplerate,em_integer periodBufSize);
    virtual void process(em_audio_stream_t buf,em_integer buflen);
    virtual void finalize();
    void addSoundGenerator(SoundGenerator *gen);

private:
    vector<SoundGenerator*> mGenerators;
    em_integer mSamplerate;
    em_integer mPeriodBufSize;


};

#endif // EMANATION_H
