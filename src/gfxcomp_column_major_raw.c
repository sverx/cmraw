#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned char uint8_t;
typedef unsigned int  uint32_t;

__declspec(dllexport) const char* getName() {
	return "Column-major raw uncompressed binary";
}

__declspec(dllexport) const char* getExt() {
	return "cmraw";
}

__declspec(dllexport) int compressTilemap(uint8_t* source, uint32_t width, uint32_t height, uint8_t* dest, uint32_t destLen) {
  unsigned int x,y;
  unsigned short int *in_buf = (unsigned short int*)source;
  unsigned short int *out_buf = (unsigned short int*)dest;
  unsigned int current = 0;

  if (destLen<width*height*2)
    return (0);                 // please give me more space for the data (2 bytes per tile needed)

  for (x=0;x<width;x++)         // left to right
    for (y=0;y<height;y++)      // top to bottom,
      out_buf[current++]=in_buf[y*width+x];

  return (width*height*2);      // report final size to caller
}
