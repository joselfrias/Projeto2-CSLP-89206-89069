/*
* @file main.c
* @brief Teste das funções desenvolvidas
*/
#include <stdio.h>
#include "formats_bin.h"
#include "formats_gray.h"
#include "formats_rgb.h"
int main(){
  //Teste para funções com Imagens RGB
  /*De salientar que a função de watermark não permite obter um resultado
  * correto quando a watermark é retangular.Para mais, a posição final da colocação
  * do watermark terá de ser altura da watermark +1 e largura +1.
  */

  RGB_IMAGE *imagem;
  //Carregar ficheiro em ppm
  imagem=LoadFromFileRGB("lena.ppm");

  //Guardar imagem num ficheiro
  saveOnFileRGB(imagem, "file.ppm");
  RGB_IMAGE *girl;
  girl=LoadFromFileRGB("girl.ppm");

  //Aceder a um pixel
  AccessPixelRGB(imagem, 501,499);
  RGB_IMAGE *newImage;
  //Aceder a uma regiao de interesse numa RGB_IMAGE.
  newImage=access_regionRGB(girl,0,0,300,300);
  saveOnFileRGB(newImage,"newfile.ppm");
  RGB_IMAGE *newImageV2;
  //Mudar a intensidade de uma imagem acrescentando o valor passado como segundo argumento.
  newImageV2=change_intensityRGB(imagem, 100);
  saveOnFileRGB(newImageV2,"intensity.ppm");
  RGB_IMAGE *newImageV3;
  //Aplicar watermark a uma imagem, watermark é colocado de acordo com os últimos quatro argumentos.
  newImageV3=applyWatermarkRGB(imagem, newImage,0,0,newImage->h+1, newImage->w+1);
  saveOnFileRGB(newImageV3,"watermark_lena.ppm");
  RGB_IMAGE *newRGBImage;
  //Aplicar um filtro a uma imagem.
  newRGBImage=applyFilter(imagem);
  saveOnFileRGB(newRGBImage,"filtro.ppm");



  //Testing Binary Images

  BIN_IMAGE *imagemBIN;
  imagemBIN=LoadFromGrayFile("gray_lena.pgm",128);
  BIN_IMAGE *newBinImage;
  saveOnFileBIN(imagemBIN, "file_gray.pgm");
  newBinImage=LoadFromBinFile("file_gray.pgm");
  saveOnFileBIN(newBinImage,"file_grayV2.pgm");

  //Testing Gray Image functions

  GRAY_IMAGE *imagemGRAY;
  imagemGRAY=LoadFromFileGRAY("gray_lena.pgm");
  saveOnFileGRAY(imagemGRAY,"file_gray.pgm");
  RGB_IMAGE *watermark=LoadFromFileRGB("girl.ppm");
  GRAY_IMAGE *gray_watermark;
  GRAY_IMAGE *gray_watermark_crop;
  gray_watermark=convertToGray(watermark);
  saveOnFileGRAY(gray_watermark,"gray_girl.pgm");
  gray_watermark_crop=access_regionGRAY(gray_watermark ,0,0,400,400);

  saveOnFileGRAY(gray_watermark_crop,"girl_access.pgm");

  GRAY_IMAGE *newImageGRAY;

  newImageGRAY=applyWatermarkGRAY(imagemGRAY, gray_watermark_crop,0,0,401,401);
  saveOnFileGRAY(newImageGRAY, "watermark_pgm");
  GRAY_IMAGE *newImageGRAYV2;
  newImageGRAYV2=filterImageGRAY(gray_watermark);
  saveOnFileGRAY(newImageGRAYV2,"filtro.pgm");


  RGB_IMAGE *img_rgb;
  GRAY_IMAGE *img_gray;
  GRAY_IMAGE *img_grayv1;
  GRAY_IMAGE *img_grayv2;
  img_rgb=LoadFromFileRGB("lena.ppm");
  img_gray=convertToGray(img_rgb);
  saveOnFileGRAY(img_gray, "gray_lena.pgm");
  img_gray=convertToChannel(img_rgb,"Red");
  saveOnFileGRAY(img_gray,"red_gray_lena.pgm");
  img_grayv1=convertToChannel(img_rgb,"Green");
  saveOnFileGRAY(img_grayv1,"green_gray_lena.pgm");
  img_grayv2=convertToChannel(img_rgb,"Blue");
  saveOnFileGRAY(img_grayv2,"blue_gray_lena.pgm");


  return 0;


}
