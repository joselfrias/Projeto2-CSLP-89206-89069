#include <stdlib.h>
#include <stdio.h>
#include "rgb.h"

RGB_IMAGE * CreateImage(int height, int width){
  RGB_IMAGE *tmp;
  tmp=(RGB_IMAGE *)malloc(sizeof(RGB_IMAGE));
  tmp->data=(RGB_PIXEL *) malloc(height*width*sizeof(RGB_PIXEL));
  tmp->h=height;
  tmp->w=width;
  tmp->n=0;
  tmp->size=height*width;

  return tmp;
}


RGB_IMAGE * LoadFromFile(char *nome){
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

  fscanf(fp, "%d", &nobits);
  RGB_IMAGE *img=CreateImage(h,w);

  fread(img->data, img->h * 3, img->w, fp);
  return img;


}
void saveOnFile(RGB_IMAGE *img, char *nome){
  FILE *fp;
  fp=fopen(nome ,"wb");
  fprintf(fp, "P6\n");
  fprintf(fp, "%d %d\n", img->h, img->w);
  fprintf(fp, "%d",255);
  fwrite(img->data, img->h * 3, img->w,fp);
}

void AccessPixel(RGB_IMAGE *img, int pix_h, int pix_w){
  int pos_pix=pix_h*(img->w)+ pix_w;
  printf ("%d %d %d", img->data[pos_pix].r,img->data[pos_pix].g, img->data[pos_pix].b);

}

RGB_IMAGE * access_region(RGB_IMAGE *img, int pix_h_start, int pix_h_end, int pix_w_start, int pix_w_end){
  int initial_pos=(pix_h_start * (img->w))+pix_w_start;
  int final_pos=(pix_h_end * (img->w))+pix_w_end;
  printf ("%d\n",initial_pos);
  printf ("%d\n",final_pos);
  RGB_IMAGE *image=CreateImage(512,512);
  for (int i=initial_pos; i<=final_pos;i++){
    image->data[i]=img->data[i];
    printf("%d %d %d\n", image->data[i].r,image->data[i].g, image->data[i].b);

  }

  return image;
}
