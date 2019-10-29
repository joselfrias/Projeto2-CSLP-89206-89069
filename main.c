#include <stdio.h>
#include "formats_bin.h"
#include "formats_gray.h"
#include "formats_rgb.h"
int main(){
  //Testing RGB FUNCTIONS

  RGB_IMAGE *imagem;
  imagem=LoadFromFileRGB("lena.ppm");
  saveOnFileRGB(imagem, "file.ppm");
  RGB_IMAGE *girl;
  girl=LoadFromFileRGB("girl.ppm");
  AccessPixelRGB(imagem, 501,499);
  RGB_IMAGE *newImage;
  newImage=access_regionRGB(girl,0,0,300,300);
  saveOnFileRGB(newImage,"newfile.ppm");
  RGB_IMAGE *newImageV2;
  newImageV2=change_intensityRGB(imagem, 100);
  saveOnFileRGB(newImageV2,"intensity.ppm");
  RGB_IMAGE *newImageV3;
  newImageV3=applyWatermarkRGB(imagem, newImage,0,0,newImage->h+1, newImage->w+1);
  saveOnFileRGB(newImageV3,"watermark_lena.ppm");
  RGB_IMAGE *newRGBImage;
  newRGBImage=applyFilter(imagem);
  saveOnFileRGB(newRGBImage,"filtro.ppm");



  //Testing Binary Images
/*
  BIN_IMAGE *imagem;
  imagem=LoadFromGrayFile("gray_lena.pgm");
  BIN_IMAGE *newBinImage;
  saveOnFileBIN(imagem, "file_gray.pgm");
  newBinImage=LoadFromBinFile("file_gray.pgm");
  saveOnFileBIN(newBinImage,"file_grayV2.pgm");
*/
  //TODO define threshold
  //Testing Gray Image functions
  /*
  GRAY_IMAGE *imagem;
  imagem=LoadFromFileGRAY("gray_lena.pgm");
  saveOnFileGRAY(imagem,"file_gray.pgm");
  RGB_IMAGE *watermark=LoadFromFileRGB("girl.ppm");
  GRAY_IMAGE *gray_watermark;
  GRAY_IMAGE *gray_watermark_crop;
  gray_watermark=convertToGray(watermark);
  saveOnFileGRAY(gray_watermark,"gray_girl.pgm");
  gray_watermark_crop=access_regionGRAY(gray_watermark ,0,0,400,400);

  saveOnFileGRAY(gray_watermark_crop,"girl_access.pgm");

  GRAY_IMAGE *newImage;

  newImage=applyWatermarkGRAY(imagem, gray_watermark_crop,0,0,401,401);
  saveOnFileGRAY(newImage, "watermark_pgm");
  GRAY_IMAGE *newImageV2;
  newImageV2=filterImageGRAY(gray_watermark);
  saveOnFileGRAY(newImageV2,"filtro.pgm");
  */







/*
  RGB_IMAGE *img_rgb;
  GRAY_IMAGE *img_gray;
  GRAY_IMAGE *img_grayv1;
  GRAY_IMAGE *img_grayv2;
  img_rgb=LoadFromFileRGB("lena.ppm");
  img_gray=convertToGray(img_rgb);
  saveOnFileGRAY(img_gray, "gray_lena.pgm");
  img_gray=convertToChannel(img_rgb,"Red");
  saveOnFileGRAY(img_gray,"red_lena.pgm");
  img_grayv1=convertToChannel(img_rgb,"Green");
  saveOnFileGRAY(img_grayv1,"green_lena.pgm");
  img_grayv2=convertToChannel(img_rgb,"Blue");
  saveOnFileGRAY(img_grayv2,"blue_lena.pgm");

*/
  return 0;


}
