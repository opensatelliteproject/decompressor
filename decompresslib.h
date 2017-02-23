#include <szlib.h>

#ifdef _WIN32
#define LIBSATDECOMPRESS_API __declspec(dllexport)
#define size_t unsigned int
#else
#define LIBSATDECOMPRESS_API
#endif

#ifndef __DECOMPRESS_LIB__
#define __DECOMPRESS_LIB__
extern int LIBSATDECOMPRESS_API LritRiceDecompress(char *input, char *output, size_t inputLength, size_t outputLength, int bitsPerPixel, int pixelsPerBlock, int pixelsPerScanline, int mask);
#endif