#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

BIN_IMAGE * CreateImage(int height, int width){
  BIN_IMAGE *tmp;
  tmp=(BIN_IMAGE *)malloc(sizeof(BIN_IMAGE));
  tmp->data=(BIN_PIXEL *) malloc(height*width*sizeof(BIN_PIXEL));
  tmp->h=height;
  tmp->w=width;
  tmp->n=0;
  tmp->size=height*width;

  return tmp;
}
BIN_IMAGE * LoadFromFile(char *nome){
  char buff[32];
  FILE *fp;

  //int nobits;
  int h,w;
  fp=fopen(nome, "rb");
  fgets(buff, sizeof(buff), fp);
  if (buff[0]!='P' || buff[1] != '4'){
    printf("Not in P4 format");
    exit(1);
  }

  fscanf(fp, "%d %d", &h, &w);
  printf("%d %d ", h,w);

//  fscanf(fp, "%d", &nobits);
//  printf("%d ", nobits);
  BIN_IMAGE *img=CreateImage(h,w);

  fread(img->data, img->h, img->w, fp);
  return img;

}
void saveOnFile(GRAY_IMAGE *img, char *nome){
  FILE *fp;
  fp=fopen(nome ,"wb");
  fprintf(fp, "P4\n");
  fprintf(fp, "%d %d\n", img->h, img->w);
  //fprintf(fp, "%d",255);
  fwrite(img->data, img->h, img->w,fp);
}
