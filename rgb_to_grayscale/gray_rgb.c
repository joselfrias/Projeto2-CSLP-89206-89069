#include <stdlib.h>
#include <stdio.h>
#include "rgb_grayscale.h"

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

  fscanf(fp, "%d", &nobits);
  printf("%d ", nobits);
  RGB_IMAGE *img=CreateImageRGB(h,w);

  fread(img->data, img->h * 3, img->w, fp);
  return img;


}

GRAY_IMAGE * convertToGray(RGB_IMAGE * img){

  GRAY_IMAGE *tmp=CreateImageGRAY(img->h,img->w);
  for (int i=0; i<img->h * img->w;i++){
    tmp->data[i].gray=(img->data[i].r+ img->data[i].g+ img->data[i].b)/3;
  }
  return tmp;


}

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
void saveOnFileGRAY(GRAY_IMAGE *img, char *nome){
  FILE *fp;
  fp=fopen(nome ,"wb");
  fprintf(fp, "P5\n");
  fprintf(fp, "%d %d\n", img->h, img->w);
  fprintf(fp, "%d\n",255);
  fwrite(img->data, img->h, img->w,fp);
}
