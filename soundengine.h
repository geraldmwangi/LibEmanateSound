#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H
#include <emanation.h>
#include <listener.h>
#include <sinusmodulator.h>
#include <typefactory.h>
using namespace std;
class SoundEngine
{
private:
    vector<Emanation*> mEmanations;
    vector<Listener*> mListeners;
    vector<ParameterModulator*> mModulators;
    em_integer mSamplerate;
    em_integer mPeriodBufSize;
    TypeFactory mFactory;
public:
    SoundEngine();
    void initialize(em_integer samplerate,em_integer periodBufSize);
    void process(int listener, em_audio_stream_t buf, em_integer buflen);
    void finalize();
    void addEmanation(string name);
    void addListener(string name);
};

#endif // SOUNDENGINE_H
