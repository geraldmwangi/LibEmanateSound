#ifndef LIBEMANATESOUND_H
#define LIBEMANATESOUND_H


#include <soundengine.h>
class  LibEmanateSound
{
private:


public:
    static SoundEngine mEngine;// I hate static variables, change this!!!
    static void initialize(em_integer samplerate,em_integer periodbufsize);
    static void process(int listener,em_audio_stream_t buf,em_integer buflen);
    static void finalize();
    static void addEmanation(string name);
    static void addListener(string name);

};

#endif // LIBEMANATESOUND_H
