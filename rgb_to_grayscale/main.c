#include <stdlib.h>
#include <stdio.h>
#include "rgb_grayscale.h"

int main(){

  RGB_IMAGE *img_rgb;
  GRAY_IMAGE *img_gray;
  img_rgb=LoadFromFileRGB("lena.ppm");
  img_gray=convertToGray(img_rgb);
  saveOnFileGRAY(img_gray, "gray_lena.pgm");

}
