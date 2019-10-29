#include <stdio.h>
#include "formats_bin.h"
#include "formats_gray.h"
#include "formats_rgb.h"
int main(){
  //Testing RGB FUNCTIONS
  /*
  RGB_IMAGE *imagem;
  RGB_IMAGE *newImage;
  imagem=LoadFromFileRGB("lena.ppm");
  saveOnFileRGB(imagem, "file.ppm");
//  AccessPixelRGB(imagem, 501,499);
  newImage=access_regionRGB(imagem,0,0,300,350);
  saveOnFileRGB(newImage,"newfile.ppm");
  */
/*
  newImage=change_intensityRGB(imagem, -100);
  saveOnFileRGB(newImage,"intensity.ppm");

*/
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
  RGB_IMAGE *watermark=LoadFromFileRGB("girl.ppm");
  GRAY_IMAGE *gray_watermark;
  GRAY_IMAGE *gray_watermark_crop;
  gray_watermark=convertToGray(watermark);
  gray_watermark_crop=access_regionGRAY(gray_watermark ,0,0,300,300);
  saveOnFileGRAY(gray_watermark,"gray_girl.pgm");
  saveOnFileGRAY(gray_watermark_crop,"girl_access.pgm");
  GRAY_IMAGE *imagem;
  imagem=LoadFromFileGRAY("gray_lena.pgm");
  GRAY_IMAGE *newImage;
  GRAY_IMAGE *newImageV2;
  GRAY_IMAGE *newImageV3;
  saveOnFileGRAY(imagem, "file_gray.pgm");
  newImage=change_intensityGRAY(imagem, 100);
  saveOnFileGRAY(newImage,"intens_gray.pgm");
  newImageV2=access_regionGRAY(imagem ,0,0,400,400);
  saveOnFileGRAY(newImageV2, "gray_lena_region.pgm");
  newImageV3=applyWatermarkGRAY(imagem, gray_watermark_crop,0,0,301,301);
  saveOnFileGRAY(newImageV3,"watermark_lena.pgm");




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
