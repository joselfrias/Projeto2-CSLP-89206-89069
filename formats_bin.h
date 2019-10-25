#ifndef INC_00_FORMATS_BIN_H
#define INC_00_FORMATS_BIN_H
#include "formats_gray.h"
#include "formats_rgb.h"

typedef struct {
  unsigned char bit;

}BIN_PIXEL;

typedef struct {
  BIN_PIXEL *data;
  int n, size, h, w;

}BIN_IMAGE;

BIN_IMAGE * CreateImageBIN(int height, int width);
void AppendBIN( BIN_IMAGE *, BIN_PIXEL pix);
void AccessPixelBIN(BIN_IMAGE *, int pix_h, int pix_w);
BIN_IMAGE * LoadFromGrayFile(char *);
BIN_IMAGE * LoadFromBinFile(char *);
void saveOnFileBIN(BIN_IMAGE *, char *nome );

#endif //INC_00_FORMATS_BIN_H
