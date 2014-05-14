#ifndef LIBEMANATESOUND_C_H
#define LIBEMANATESOUND_C_H
#include <libemanatesound.h>
#ifdef __cplusplus
#warning LibEmanateSound_c: compiling with extern 'c'
extern "C" {
#endif

void libEmanateInitialize(em_integer samplerate,em_integer periodbufsize);

void libEmanateProcess(em_integer listener,em_audio_stream_t buf,em_integer buflen);

void libEmanateFinalize();

void libEmanateAddEmanation();

void libEmanateAddListener();

#ifdef __cplusplus
}
#endif
#endif // LIBEMANATESOUND_C_H
