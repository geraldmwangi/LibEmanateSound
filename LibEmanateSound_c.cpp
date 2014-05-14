#include <libemanatesound.h>

#ifdef __cplusplus
#warning LibEmanateSound_c: compiling with extern 'c'
extern "C" {
#endif

void libEmanateInitialize(em_integer samplerate,em_integer periodbufsize)
{
    LibEmanateSound::initialize(samplerate,periodbufsize);
}

void libEmanateProcess(em_integer listener,em_audio_stream_t buf,em_integer buflen)
{
    LibEmanateSound::process(listener,buf,buflen);
}

void libEmanateFinalize()
{
    LibEmanateSound::finalize();
}

void libEmanateAddEmanation(char* str)
{
    string name(str);
    LibEmanateSound::addEmanation(name);
}

void libEmanateAddListener(char* str)
{
    string name(str);

    LibEmanateSound::addListener(name);
}

#ifdef __cplusplus
}
#endif
