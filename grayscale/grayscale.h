#ifndef INC_00_GRAYSCALE_H
#define INC_00_GRAYSCALE_H

typedef struct {
  unsigned char gray;

}GRAY_PIXEL;

typedef struct {
  GRAY_PIXEL *data;
  int n, size, h, w;

}GRAY_IMAGE;

GRAY_IMAGE * CreateImage(int height, int width);
void Append( GRAY_IMAGE *, GRAY_PIXEL pix);
void AccessPixel(GRAY_IMAGE *, int pix_h, int pix_w);
GRAY_IMAGE * LoadFromFile(char *);
void saveOnFile(GRAY_IMAGE *, char *nome );

#endif //INC_00_GRAYSCALE_H
