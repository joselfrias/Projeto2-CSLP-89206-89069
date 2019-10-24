#include <stdio.h>
#include <stdlib.h>

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

void convertToBinary(GRAY_IMAGE * img){
  int ncols=img->w;
  int nlines=img->h;

  unsigned int b=1;
  unsigned int ret=0;
  treshold=128;
  for (int i=0; i<img->size;i++){
    if (img->data[i]>treshold){
      b=1;
    }
    else{
      b=0;
      b=b<<i;
    }

    ret=ret ^ b;
  //  return ret;

  }


}
