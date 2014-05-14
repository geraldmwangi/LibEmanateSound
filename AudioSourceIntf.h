#ifndef AUDIOSOURCEINTF_H
#define AUDIOSOURCEINTF_H
#include <EmanateTypes.h>
class AudioSourceIntf
{
public:
    virtual void initialize(em_integer samplerate,em_integer periodBufSize)=0;
    virtual void process(em_audio_stream_t buf,em_integer buflen)=0;
    virtual void finalize()=0;
};

#endif // AUDIOSOURCEINTF_H
