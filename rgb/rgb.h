#ifndef INC_00_RGB_H
#define INC_00_RGB_H

typedef struct {
	unsigned char r, g, b;

} RGB_PIXEL;

typedef struct {
	RGB_PIXEL *data;
	int n, size, h, w;

}RGB_IMAGE;

RGB_IMAGE * CreateImage(int height, int width);
void Append( RGB_IMAGE *, RGB_PIXEL pix);
void AccessPixel(RGB_IMAGE *, int pix_h, int pix_w);
RGB_IMAGE * access_region(RGB_IMAGE *, int pix_h_start, int pix_h_end, int pix_w_start, int pix_w_end);
RGB_IMAGE * LoadFromFile(char *);
void saveOnFile(RGB_IMAGE *, char *nome );
RGB_IMAGE * change_intensity(RGB_IMAGE *, int intensity);
RGB_IMAGE * applyWatermark(RGB_IMAGE *, RGB_IMAGE *);
#endif //INC_00_RGB_H
