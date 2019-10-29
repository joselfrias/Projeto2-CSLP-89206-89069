/** @file functions.c
 *  @brief Implementação das funções definidas nos header files.
 *
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "formats_bin.h"
#include "formats_gray.h"
#include "formats_rgb.h"

/*
* @brief Função que cria uma imagem em RGB.
*
* @param height Numero de linhas da imagem.
* @param width Numero de colunas da imagem.
* @return tmp Retorna uma estrutura RGB_IMAGE.
*/
RGB_IMAGE * CreateImageRGB(int height, int width){
  RGB_IMAGE *tmp;
  tmp=(RGB_IMAGE *)malloc(sizeof(RGB_IMAGE));
  tmp->data=(RGB_PIXEL *) malloc(height*width*sizeof(RGB_PIXEL));
  tmp->h=height;
  tmp->w=width;
  tmp->n=0;
  tmp->size=height*width;

  return tmp;
}

/*
*Função que carrega um ficheiro em rgb para uma estrutura RGB_IMAGE.
* @param nome Nome do ficheiro com a imagem rgb.
* @return Retorna uma estrutura RGB_IMAGE.
*/

RGB_IMAGE * LoadFromFileRGB(char *nome){
  char buff[32];
  FILE *fp;

  int nobits;
  int h,w;
  fp=fopen(nome, "rb");
  fgets(buff, sizeof(buff), fp);
  if (buff[0]!='P' || buff[1] != '6'){
    printf("Not in P6 format");
    exit(1);
  }

  fscanf(fp, "%d %d", &h, &w);
  printf("%d %d ", h,w);

  fscanf(fp, "%d \n", &nobits);
  printf("%d", nobits);
  RGB_IMAGE *img=CreateImageRGB(h,w);

  fread(img->data, img->h * 3, img->w, fp);
  return img;
}


/* Função que altera a intensidade de cada componente rgb
* de uma imagem, retornando uma nova imagem.
* @param img RGB_IMAGE que se pretende alterar.
* @param intensity Valor a alterar em cada uma das componentes de cada pixel.
* @return RGB_IMAGE Retorna uma imagem rgb com as alterações de intensidade.
*/

RGB_IMAGE * change_intensityRGB(RGB_IMAGE *img, int intensity){
  RGB_IMAGE *tmp=CreateImageRGB(img->h, img->w);
    for(int i=0; i<img->size;i++){
      if (img->data[i].r+intensity < 255){
          tmp->data[i].r=img->data[i].r+intensity;
    }
      else if (img->data[i].r+intensity > 255){
        tmp->data[i].r=255;
      }
      else if (img->data[i].r+intensity<0){
        tmp->data[i].r=0;
      }
      if (img->data[i].g+intensity < 255){
          tmp->data[i].g=img->data[i].g+intensity;
    }
      else if (img->data[i].g+intensity > 255){
        tmp->data[i].g=255;
      }
      else if (img->data[i].g+intensity<0){
        tmp->data[i].g=0;
      }
      if (img->data[i].b+intensity < 255){
          tmp->data[i].b=img->data[i].b+intensity;
    }
      else if (img->data[i].b+intensity > 255){
        tmp->data[i].b=255;
      }
      else if (img->data[i].b+intensity<0){
        tmp->data[i].b=0;
      }
    }


    return tmp;

}

/* Função que acede a uma região de interesse
* de uma imagem, retornando uma nova imagem.
* @param img RGB_IMAGE que se pretende alterar.
* @param pix_h_start linha onde se pretende começar a região de interesse.
* @param pix_h_end linha onde se pretende acabar a região de interesse.
* @param pix_w_start coluna onde se pretende começar a região de interesse.
* @param pix_w_end coluna onde se pretende acabar a região de interesse.
* @return image Retorna uma nova RGB_IMAGE que é a região de interesse pretendida.
*/
RGB_IMAGE * access_regionRGB(RGB_IMAGE *img, int x, int y, int w, int h){
  RGB_IMAGE * tmp=CreateImageRGB(w-x,h-y);
  int lowerBound = (x + y)*img->w;
  int upperBound = lowerBound + tmp->h;
  int imgSize = img->size;
  int counter = 0;
  for(int i = 0; i < imgSize; i++){

    if( i < upperBound && i >= lowerBound){
      //if(counter != i)
      tmp->data[counter] = img->data[i];
      counter++;
    }

    if(i == upperBound ){
      i--;
      lowerBound += img->w;
      upperBound += img->w;
    }
  }
  return tmp;
}
  /*
  RGB_IMAGE *image=CreateImageRGB(pix_h_end-pix_h_start,pix_w_end-pix_w_start);

  RGB_PIXEL **newdata=(RGB_PIXEL **)malloc(sizeof(RGB_PIXEL *) *img->h);
  for (int i=0; i<img->h;i++){
    newdata[i]=(RGB_PIXEL *) malloc(img->h * sizeof(RGB_PIXEL));
  }
  for (int i=0; i<img->h;i++){
    for (int j=0; j<img->w;j++){
      newdata[i][j]=img->data[i*(img->w)+j];
    }

  }

  RGB_PIXEL **new=(RGB_PIXEL **)malloc(sizeof(RGB_PIXEL *) *image->h);
  for (int i=0; i<image->h;i++){
    new[i]=(RGB_PIXEL *) malloc(image->w * sizeof(RGB_PIXEL));
  }


  for (int i=pix_h_start; i<pix_h_end;i++){
    for (int j=pix_w_start;j<pix_w_end;j++){
        new[i-pix_h_start][j-pix_w_start]=newdata[i][j];
    }
  }
  int k=0;
  for (int i=pix_h_start; i<pix_h_end;i++){

    for (int j=pix_w_start;j<pix_w_end;j++){
        image->data[k]=new[i][j];
        k++;

    }
  }

    return image;
}
*/

/*
*Função que aplica uma watermark a uma imagem rgb.
* @param big_img RGB_IMAGE onde se irá ser colocada a watermark.
* @param other_img Imagem da watermark.
* @return RGB_IMAGE Nova Imagem RGB com watermark aplicada.
*/

RGB_IMAGE * applyWatermarkRGB(RGB_IMAGE *original, RGB_IMAGE * watermark,int pix_h_start, int pix_w_start, int pix_h_end, int pix_w_end){
  RGB_IMAGE * tmp=CreateImageRGB(original->h, original->w);
  int counter=0;
  for (int i=0; i<original->size;i++){
    if (((i / original->w) > pix_h_start) &&  ((i / original->w)<pix_h_end)  && ((i%original->w) >pix_w_start) && ((i%original->w)<pix_w_end)) {
      tmp->data[i].r=0.6 * original->data[i].r+0.4 * watermark->data[counter].r;
      tmp->data[i].g=0.6 * original->data[i].g+0.4 * watermark->data[counter].g;
      tmp->data[i].b=0.6 * original->data[i].b+0.4 * watermark->data[counter].b;
      counter++;
    }
    else{
      tmp->data[i]=original->data[i];

    }

  }
  return tmp;
}

/*
*Função que guarda uma RGB_Image num ficheiro.
* @param img RGB_IMAGE que se quer guardar.
* @param nome Nome do ficheiro onde a imagem será guardada.
* @return Nothing
*/

void saveOnFileRGB(RGB_IMAGE *img, char *nome){
  FILE *fp;
  fp=fopen(nome ,"wb");
  fprintf(fp, "P6\n");
  fprintf(fp, "%d %d\n", img->h, img->w);
  fprintf(fp, "%d\n",255);
  fwrite(img->data, img->h * 3, img->w,fp);
}


/*Função que acede a um pixel RGB.
* @param img RGB_IMAGE onde se pretende aceder.
* @param pix_h Numero da linha do pixel.
* @param pix_w
* @return Nothing
*/

void AccessPixelRGB(RGB_IMAGE *img, int pix_h, int pix_w){
  int pos_pix=pix_h*(img->w)+ pix_w;
  printf ("%d %d %d", img->data[pos_pix].r,img->data[pos_pix].g, img->data[pos_pix].b);

}

RGB_IMAGE * applyFilter(RGB_IMAGE *img){
  RGB_IMAGE *tmp = CreateImageRGB(img->h, img->w);
  printf("\n");
  int counter = 0;
  int kernel[9] ={-1,0,1,
          0,0,0,
          1,0,-1};
  for(int i = 0; i < img->size; i++){
    if(i < img->w || i%img->w == 0 || (i+1)%img->w == 0 || i > (img->w)*(img->w-1)){
      tmp->data[i].r = 0;
      tmp->data[i].g = 0;
      tmp->data[i].b = 0;
      counter++;
      //printf("%d\n", counter);
    }
    else{
      int newPixel = 0;
      int kernelValue = 0;
      int t;
      for(int a = 0; a < 3; a++){
        //printf("%d\n", i);
        if(a == 0){
          t = -512;
        }
        else if(a == 1){
          t = 0;
        }
        else{
          t = 512;
        }
        newPixel += img->data[i+t+a].r*kernel[kernelValue];
        newPixel += img->data[i+t+a].g*kernel[kernelValue];
        newPixel += img->data[i+t+a].b*kernel[kernelValue];
        kernelValue++;
        //printf("%d %d %d\n", i, t, a);
      }
      tmp->data[i].r = newPixel/9;
      tmp->data[i].g = newPixel/9;
      tmp->data[i].b= newPixel/9;
    }
  }
  return tmp;
}


  /*
  * Função que cria uma imagem em GRAYSCALE
  * @param height Numero de linhas da imagem.
  * @param width Numero de colunas da imagem.
  * @return tmp Retorna uma estrutura GRAY_IMAGE.
  */
GRAY_IMAGE * CreateImageGRAY(int height, int width){
  GRAY_IMAGE *tmp;
  tmp=(GRAY_IMAGE *)malloc(sizeof(GRAY_IMAGE));
  tmp->data=(GRAY_PIXEL *) malloc(height*width*sizeof(GRAY_PIXEL));
  tmp->h=height;
  tmp->w=width;
  tmp->n=0;
  tmp->size=height*width;

  return tmp;
}

/*
* Função que converte uma imagem RGB para uma em Grayscale.
* @param img Imagem RGB que se quer converter.
* @return tmp Imagem Grayscale que se quer obter.
*/
GRAY_IMAGE * convertToGray(RGB_IMAGE * img){

  GRAY_IMAGE *tmp=CreateImageGRAY(img->h,img->w);
  for (int i=0; i<img->h * img->w;i++){
    tmp->data[i].gray=(img->data[i].r+ img->data[i].g+ img->data[i].b)/3;
  }
  return tmp;

}

/*
* Função que converte uma imagem RGB para uma em grayscale de acordo
* com o channel pretendido.
* @param img RGB_IMAGE que se quer converter.
* @param channel Channel que se quer obter na imagem grayscale.
* @return tmp Imagem em grayscale de acordo com a imagem rgb e o channel pretendido.
*/

GRAY_IMAGE * convertToChannel(RGB_IMAGE * img, char * channel){
  GRAY_IMAGE *tmp=CreateImageGRAY(img->h,img->w);
  printf("%s\n", channel);
  if (strcmp(channel, "Red")){
    for (int i=0; i<img->h * img->w;i++){
      tmp->data[i].gray=img->data[i].r;
  }
}
  else if (strcmp(channel,"Green")){
    for (int i=0; i<img->h * img->w;i++){
      tmp->data[i].gray=img->data[i].g;
  }
  }
  else if (strcmp(channel, "Blue")){
    for (int i=0; i<img->h * img->w;i++){
      tmp->data[i].gray=img->data[i].b;
  }
  }

  return tmp;

}
/*
* Função que carrega de um ficheiro que contém uma Imagem GRAYSCALE
* para uma estrutura GRAY_IMAGE.
* @param nome Nome do ficheiro da imagem pretendida.
* @return img Retorna uma nova estrutura GRAY_IMAGE.
*/
GRAY_IMAGE * LoadFromFileGRAY(char *nome){
  char buff[32];
  FILE *fp;

  int nobits;
  int h,w;
  fp=fopen(nome, "rb");
  fgets(buff, sizeof(buff), fp);
  if (buff[0]!='P' || buff[1] != '5'){
    printf("Not in P5 format");
    exit(1);
  }

  fscanf(fp, "%d %d", &h, &w);
  printf("%d %d ", h,w);

  fscanf(fp, "%d", &nobits);
  printf("%d ", nobits);
  GRAY_IMAGE *img=CreateImageGRAY(h,w);

  fread(img->data, img->h, img->w, fp);
  return img;

}

/*
*Função que guarda uma Gray_Image num ficheiro.
* @param img GRAY_IMAGE que se quer guardar.
* @param nome Nome do ficheiro onde a imagem será guardada.
* @return Nothing
*/
void saveOnFileGRAY(GRAY_IMAGE *img, char *nome){
  FILE *fp;
  fp=fopen(nome ,"wb");
  fprintf(fp, "P5\n");
  fprintf(fp, "%d %d\n", img->h, img->w);
  fprintf(fp, "%d\n",255);
  fwrite(img->data, img->h, img->w,fp);
}

/*
*Função que acede a um pixel numa imagem Grayscale.
* @param img Imagem em grayscale a que se pretende aceder.
* @param pix_h Linha do pixel a que se pretende obter.
* @param pix_w Coluna do pixel a que se pretende aceder.
* @return Nothing.
*/

void AccessPixelGRAY(GRAY_IMAGE *img, int pix_h, int pix_w){
  int pos_pix=pix_h*(img->h)+ pix_w*(img->w);
  printf ("%d ", img->data[pos_pix].gray);

}


/* Função que altera a intensidade da componente grayscale
* de uma imagem, retornando uma nova imagem.
* @param img GRAY_IMAGE que se pretende alterar.
* @param intensity Valor a alterar na componente grayscale de cada pixel.
* @return GRAY_IMAGE Retorna uma imagem grayscale com as alterações de intensidade.
*/
GRAY_IMAGE * change_intensityGRAY(GRAY_IMAGE *img, int intensity){
  GRAY_IMAGE *tmp = CreateImageGRAY(img->h, img->w);
  for (int i=0; i<img->size;i++){
    if (img->data[i].gray+intensity<256){
      tmp->data[i].gray=img->data[i].gray+intensity;
    }
    else if (img->data[i].gray+intensity>=256){
      tmp->data[i].gray=255;
    }
    else if (img->data[i].gray+intensity<0){
      tmp->data[i].gray=0;
    }

  }
  return tmp;

}

GRAY_IMAGE * access_regionGRAY(GRAY_IMAGE *img, int x, int y, int w, int h){
  GRAY_IMAGE *tmp = CreateImageGRAY(h-y,w-x);
  int lowerBound = (x + y)*img->w;
  int upperBound = lowerBound + tmp->h;
  int imgSize = img->size;
  int counter = 0;
  for(int i = 0; i < imgSize; i++){
    if( i < upperBound && i >= lowerBound){
      //if(counter != i)
      tmp->data[counter].gray = img->data[i].gray;
      counter++;
    }
    if(i == upperBound ){
      i--;
      lowerBound += img->w;
      upperBound += img->w;
    }
  }
  return tmp;
}
  /*GRAY_IMAGE *image=CreateImageGRAY(pix_h_end-pix_h_start,pix_w_end-pix_w_start);
  int counter=0;


  GRAY_PIXEL **newdata=(GRAY_PIXEL **)malloc(sizeof(GRAY_PIXEL *) *img->h);
  for (int i=0; i<img->h;i++){
    newdata[i]=(GRAY_PIXEL *) malloc(img->h * sizeof(GRAY_PIXEL));
  }
  for (int i=0; i<img->h;i++){
    for (int j=0; j<img->w;j++){
      newdata[i][j]=img->data[i*(img->w)+j];
    }

  }

  GRAY_PIXEL **new=(GRAY_PIXEL **)malloc(sizeof(GRAY_PIXEL *) *image->h);
  for (int i=0; i<image->h;i++){
    new[i]=(GRAY_PIXEL *) malloc(image->w * sizeof(GRAY_PIXEL));
  }


  for (int i=pix_h_start; i<pix_h_end;i++){
    for (int j=pix_w_start;j<pix_w_end;j++){
        new[i-pix_h_start][j-pix_w_start]=newdata[i][j];
    }
  }
  int k=0;
  for (int i=pix_h_start; i<pix_h_end;i++){

    for (int j=pix_w_start;j<pix_w_end;j++){
        image->data[k]=new[i][j];
        k++;

    }
  }


    return image;

    }
    */


/*
* Função que cria uma imagem em binario
* @param height Numero de linhas da imagem.
* @param width Numero de colunas da imagem.
* @return tmp Retorna uma estrutura BIN_IMAGE.
*/

GRAY_IMAGE * applyWatermarkGRAY(GRAY_IMAGE *original , GRAY_IMAGE *watermark,int pix_h_start, int pix_w_start,int  pix_h_end, int pix_w_end){

  GRAY_IMAGE * tmp=CreateImageGRAY(original->h, original->w);
  int counter=0;
  int k=0;
  for (int i=0; i<original->size;i++){
    if (((i / original->w) > pix_h_start) &&  ((i / original->w)<pix_h_end)  && ((i%original->w) >pix_w_start) && ((i%original->w)<pix_w_end)) {
      tmp->data[i].gray=0.6 * original->data[i].gray+0.4 * watermark->data[counter].gray;
      counter++;
    }
    else{
      tmp->data[i]=original->data[i];

    }

  }
  return tmp;
}
  /*
  GRAY_PIXEL * src = original->data;
  GRAY_PIXEL * wm = watermark->data;
  GRAY_PIXEL * buffer = malloc(original->size * sizeof(GRAY_PIXEL));
  GRAY_IMAGE * ret = CreateImageGRAY(original->h, original->w);

  GRAY_PIXEL result;
  GRAY_PIXEL src_px, wm_px;

  for (int i = 0; i < original->size; i++) {
    if(i>=pix_w_start *(watermark->w) + pix_h_start && i<=pix_w_end*(watermark->w) + pix_h_end) // check if i is in bounds of watermark
    {

      src_px = *src;
      wm_px = *wm;
      result.gray = src_px.gray * 0.8 + wm_px.gray * 0.2;
      buffer[i] = result;
      wm++;

    }
    else
    {

      buffer[i] = *src;

    }

    src++;

  }

  ret->data = buffer;


  return ret;


}
*/

GRAY_IMAGE * filterImageGRAY(GRAY_IMAGE *img){
  GRAY_IMAGE *tmp = CreateImageGRAY(img->h, img->w);
  printf("\n");
  int counter = 0;
  int kernel[9] ={-1,0,1,
          0,0,0,
          1,0,-1};
  for(int i = 0; i < img->size; i++){
    if(i < img->w || i%img->w == 0 || (i+1)%img->w == 0 || i > (img->w)*(img->w-1)){
      tmp->data[i].gray = 0;
      counter++;
      //printf("%d\n", counter);
    }
    else{
      int newPixel = 0;
      int kernelValue = 0;
      int t;
      for(int a = 0; a < 3; a++){
        //printf("%d\n", i);
        if(a == 0){
          t = -512;
        }
        else if(a == 1){
          t = 0;
        }
        else{
          t = 512;
        }
        newPixel += img->data[i+t+a].gray*kernel[kernelValue];
        kernelValue++;
        //printf("%d %d %d\n", i, t, a);
      }
      tmp->data[i].gray = newPixel/9;
    }
  }
  return tmp;

}
BIN_IMAGE * CreateImageBIN(int height, int width){
  BIN_IMAGE *tmp;
  tmp=(BIN_IMAGE *)malloc(sizeof(BIN_IMAGE));
  tmp->data=(BIN_PIXEL *) malloc(height*width*sizeof(BIN_PIXEL));
  tmp->h=height;
  tmp->w=width;
  tmp->n=0;
  tmp->size=height*width;

  return tmp;
}

/*
* Função que carrega de um ficheiro que contém uma Imagem EM BINARIO
* para uma estrutura BIN_IMAGE.
* @param nome Nome do ficheiro da imagem pretendida.
* @return img Retorna uma nova estrutura BIN_IMAGE.
*/
BIN_IMAGE * LoadFromBinFile(char * nome){
  char buff[32];
  FILE *fp;

  int nobits;
  int h,w;
  fp=fopen(nome, "rb");
  fgets(buff, sizeof(buff), fp);
  if (buff[0]!='P' || buff[1] != '5'){
    printf("Not in P5 format");
    exit(1);
  }

  fscanf(fp, "%d %d", &h, &w);

  fscanf(fp, "%d", &nobits);

  BIN_IMAGE *img=CreateImageBIN(h,w);
  fread(img->data,img->h, img->w,fp);

  return img;

}

/*
* Função que carrega de um ficheiro que contém uma Imagem EM Grayscale
* para uma estrutura BIN_IMAGE.
* @param nome Nome do ficheiro da imagem pretendida.
* @return img Retorna uma nova estrutura BIN_IMAGE.
*/
BIN_IMAGE * LoadFromGrayFile(char *nome){
  char buff[32];
  FILE *fp;

  int nobits;
  int h,w;
  fp=fopen(nome, "rb");
  fgets(buff, sizeof(buff), fp);
  if (buff[0]!='P' || buff[1] != '5'){
    printf("Not in P5 format");
    exit(1);
  }

  fscanf(fp, "%d %d", &h, &w);

  fscanf(fp, "%d", &nobits);
  int threshold=128;
  BIN_IMAGE *img=CreateImageBIN(h,w);
  fread(img->data,img->h, img->w,fp);
  for (int i=0; i<img->size;i++){
    if (img->data[i].bit>threshold){
      img->data[i].bit=255;
    }
    else{
      img->data[i].bit=0;
    }
  }

  return img;

}

/*
*Função que guarda uma BIN_Image num ficheiro.
* @param img BIN_IMAGE que se quer guardar.
* @param nome Nome do ficheiro onde a imagem será guardada.
* @return Nothing
*/
void saveOnFileBIN(BIN_IMAGE *img, char *nome){
  FILE *fp;
  fp=fopen(nome ,"wb");
  fprintf(fp, "P5\n");
  fprintf(fp, "%d %d\n", img->h, img->w);
  fprintf(fp, "255\n");
  fwrite(img->data, img->h, img->w,fp);
}
