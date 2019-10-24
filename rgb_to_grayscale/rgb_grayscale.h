#ifndef INC_00_RGB_H
#define INC_00_RGB_H

typedef struct {
	unsigned char r, g, b;

} RGB_PIXEL;

typedef struct {
	RGB_PIXEL *data;
	int n, size, h, w;

}RGB_IMAGE;

typedef struct {
  unsigned char gray;

}GRAY_PIXEL;

typedef struct {
  GRAY_PIXEL *data;
  int n, size, h, w;

}GRAY_IMAGE;

RGB_IMAGE * CreateRGBImage(int height, int width);
void AppendRGB( RGB_IMAGE *, RGB_PIXEL pix);
RGB_IMAGE * LoadFromFileRGB(char *);
void saveOnFileRGB(RGB_IMAGE *, char *nome );

GRAY_IMAGE * convertToGray(RGB_IMAGE *);

GRAY_IMAGE * CreateGRAYImage(int height, int width);
void AppendGRAY( GRAY_IMAGE *, GRAY_PIXEL pix);
GRAY_IMAGE * LoadFromFileGRAY(char *);
void saveOnFileGRAY(GRAY_IMAGE *, char *nome );

#endif //INC_00_RGB_H
