#include <stdio.h>
#include "formats_bin.h"
#include "formats_gray.h"
#include "formats_rgb.h"
int main(){
  //Testing RGB FUNCTIONS
  RGB_IMAGE *imagem;
  RGB_IMAGE *newImage;
  //GRAY_IMAGE *imagem;
 // GRAY_IMAGE *newImage;
  //imagem = LoadFromFileGRAY("gray_lena.pgm");
  //newImage= access_regionGRAY(imagem, 0, 0, 512, 255);
  //imagem = LoadFromFileGRAY("cutOut.pgm");
  //newImage = filterImageGRAY(imagem);
  //saveOnFileGRAY(newImage, "selectExample");
  imagem=LoadFromFileRGB("lena.ppm");
  newImage = access_regionRGB(imagem, 0, 0 , 512, 255);
  //saveOnFileRGB(imagem, "file.ppm");
//  AccessPixelRGB(imagem, 501,499);
  //newImage=access_regionRGB(imagem,0,512,0,512);
  //saveOnFileRGB(newImage,"newfile.ppm");
/*
  newImage=change_intensityRGB(imagem, -100);
  saveOnFileRGB(newImage,"intensity.ppm");

*/
  //Testing Binary Images

  //BIN_IMAGE *imagem;
  //imagem=LoadFromGrayFile("gray_lena.pgm");
  //BIN_IMAGE *newBinImage;
  //saveOnFileBIN(imagem, "file_gray.pgm");
  //newBinImage=LoadFromBinFile("file_gray.pgm");
  /*saveOnFileBIN(newBinImage,"file_grayV2.pgm");

  //TODO define threshold
  //Testing Gray Image functions

  GRAY_IMAGE *imagem;
  imagem=LoadFromFileGRAY("gray_lena.pgm");
  GRAY_IMAGE *newImage;
  saveOnFileGRAY(imagem, "file_gray.pgm");
  newImage=change_intensityGRAY(imagem, 100);
  saveOnFileGRAY(newImage,"intens_gray.pgm");
  */


/*
  RGB_IMAGE *img_rgb;
  GRAY_IMAGE *img_gray;        786432
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
  printf("Done\n");
  saveOnFileRGB(imagem, "file.ppm");
  return 0;


}
