#ifndef LISTENER_H
#define LISTENER_H
#include <AudioSourceIntf.h>
#include "parameteredobject.h"
#include <vector>
using namespace std;
class Listener : public AudioSourceIntf,public ParameteredObject
{
public:
    Listener(string name);
    ~Listener();
    virtual void initialize(em_integer samplerate,em_integer periodBufSize);
    virtual void process(em_audio_stream_t buf,em_integer buflen);
    virtual void finalize();
    void addAudioSource(AudioSourceIntf* source);
private:
    vector<AudioSourceIntf*> mAudioSources;
    em_integer mSamplerate;
    em_integer mPeriodBufSize;
};

#endif // LISTENER_H
