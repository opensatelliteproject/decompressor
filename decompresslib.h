#include <szlib.h>

#ifndef __DECOMPRESS_LIB__
#define __DECOMPRESS_LIB__
extern int LritRiceDecompress(char *input, char *output, size_t inputLength, size_t outputLength, int bitsPerPixel, int pixelsPerBlock, int pixelsPerScanline, int mask);
#endif