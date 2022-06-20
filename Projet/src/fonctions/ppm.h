// gcc -Wall ppm.c -c -o ppm.o

#pragma once

#include <string>

typedef struct
{
  int width, height, bpp;
  unsigned char *data;
} TEXTURE_STRUCT;

TEXTURE_STRUCT  * readPpm (std::string ppmFilePath);
void writePpm (char *filename, unsigned char *data);
unsigned char * rgb2rgba(TEXTURE_STRUCT * texture);
