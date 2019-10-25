#include <stdlib.h>
#include <stdio.h>
#include "grayscale.h"

GRAY_IMAGE * CreateImage(int height, int width){
  GRAY_IMAGE *tmp;
  tmp=(GRAY_IMAGE *)malloc(sizeof(GRAY_IMAGE));
  tmp->data=(GRAY_PIXEL *) malloc(height*width*sizeof(GRAY_PIXEL));
  tmp->h=height;
  tmp->w=width;
  tmp->n=0;
  tmp->size=height*width;

  return tmp;
}
GRAY_IMAGE * LoadFromFile(char *nome){
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
  GRAY_IMAGE *img=CreateImage(h,w);

  fread(img->data, img->h, img->w, fp);
  return img;

}

void saveOnFile(GRAY_IMAGE *img, char *nome){
  FILE *fp;
  fp=fopen(nome ,"wb");
  fprintf(fp, "P5\n");
  fprintf(fp, "%d %d\n", img->h, img->w);
  fprintf(fp, "%d\n",255);
  fwrite(img->data, img->h, img->w,fp);
}


void AccessPixel(GRAY_IMAGE *img, int pix_h, int pix_w){
  int pos_pix=pix_h*(img->h)+ pix_w*(img->w);
  printf ("%d ", img->data[pos_pix].gray);

}

GRAY_IMAGE * change_intensity(GRAY_IMAGE *img, int intensity){
  GRAY_IMAGE *tmp = CreateImage(img->h, img->w);
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
