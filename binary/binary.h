#ifndef INC_00_BINARY_H
#define INC_00_BINARY_H

typedef struct {
  unsigned char bit:1;

}BIN_PIXEL;

typedef struct {
  BIN_PIXEL *data;
  int n, size, h, w;

}BIN_IMAGE;

BIN_IMAGE * CreateImage(int height, int width);
void Append( BIN_IMAGE *, BIN_PIXEL pix);
void AccessPixel(BIN_IMAGE *, int pix_h, int pix_w);
BIN_IMAGE * LoadFromFile(char *);
void saveOnFile(BIN_IMAGE *, char *nome );

#endif //INC_00_BINARY_H
