#include <stdlib.h>
#include <stdio.h>
#include "rgb_grayscale.h"

int main(){

  RGB_IMAGE *img_rgb;
  GRAY_IMAGE *img_gray;
  GRAY_IMAGE *img_grayv1;
  GRAY_IMAGE *img_grayv2;
  img_rgb=LoadFromFileRGB("lena.ppm");
  /*img_gray=convertToGray(img_rgb);
  saveOnFileGRAY(img_gray, "gray_lena.pgm");*/
  img_gray=convertToChannel(img_rgb,"Red");
  saveOnFileGRAY(img_gray,"red_lena.pgm");
  img_grayv1=convertToChannel(img_rgb,"Green");
  saveOnFileGRAY(img_grayv1,"green_lena.pgm");
  img_grayv2=convertToChannel(img_rgb,"Blue");
  saveOnFileGRAY(img_grayv2,"blue_lena.pgm");



}
