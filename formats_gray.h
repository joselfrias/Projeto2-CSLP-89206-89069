#ifndef INC_00_FORMATS_GRAY_H
#define INC_00_FORMATS_GRAY_H
#include "formats_bin.h"
#include "formats_rgb.h"
typedef struct {
  unsigned char gray;

}GRAY_PIXEL;

typedef struct {
  GRAY_PIXEL *data;
  int n, size, h, w;

}GRAY_IMAGE;

GRAY_IMAGE * CreateImageGRAY(int height, int width);
GRAY_IMAGE * convertToGray(RGB_IMAGE *);
GRAY_IMAGE * convertToChannel(RGB_IMAGE *, char *);
GRAY_IMAGE * CreateImageGRAY(int height, int width);
void AppendGRAY( GRAY_IMAGE *, GRAY_PIXEL pix);
GRAY_IMAGE * LoadFromFileGRAY(char *);
void saveOnFileGRAY(GRAY_IMAGE *, char *nome );
void AccessPixelGRAY(GRAY_IMAGE *, int pix_h, int pix_w);
GRAY_IMAGE * change_intensityGRAY(GRAY_IMAGE *, int intensity);

#endif //INC_00_FORMATS_GRAY_H
