#ifndef SOUNDGENERATOR_H
#define SOUNDGENERATOR_H
#include <AudioSourceIntf.h>
#include <parameteredobject.h>
class SoundGenerator: public AudioSourceIntf, public ParameteredObject
{
public:
    SoundGenerator(string name="", string className="",string type="");
    ~SoundGenerator();
    TemplatedParameter<float> volume;
    virtual void initialize(em_integer samplerate,em_integer periodBufSize);
    virtual void process(em_audio_stream_t buf,em_integer buflen){};
    virtual void finalize();
protected:
    em_integer mSamplerate;
    em_integer mPeriodBufSize;
    em_audio_stream_t mWindow;


};

#endif // SOUNDGENERATOR_H
