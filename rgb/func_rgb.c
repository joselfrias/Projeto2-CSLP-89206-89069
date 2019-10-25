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

  fscanf(fp, "%d\n", &nobits);
  RGB_IMAGE *img=CreateImage(h,w);

  fread(img->data, img->h * 3, img->w, fp);
  return img;


}
void saveOnFile(RGB_IMAGE *img, char *nome){
  FILE *fp;
  fp=fopen(nome ,"wb");
  fprintf(fp, "P6\n");
  fprintf(fp, "%d %d\n", img->h, img->w);
  fprintf(fp, "%d\n",255);
  fwrite(img->data, img->h * 3, img->w,fp);
}

void AccessPixel(RGB_IMAGE *img, int pix_h, int pix_w){
  int pos_pix=pix_h*(img->w)+ pix_w;
  printf ("%d %d %d", img->data[pos_pix].r,img->data[pos_pix].g, img->data[pos_pix].b);

}


RGB_IMAGE * change_intensity(RGB_IMAGE *img, int intensity){
  RGB_IMAGE *tmp=CreateImage(img->h, img->w);
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



RGB_IMAGE * access_region(RGB_IMAGE *img, int pix_h_start, int pix_h_end, int pix_w_start, int pix_w_end){
  int initial_pos=(pix_w_start * (img->w))+pix_h_start;
  int final_pos=(pix_w_end * (img->w))+pix_h_end;
  printf ("%d\n",initial_pos);
  printf ("%d\n",final_pos);
  int nlines=0;
  int j=0;
  RGB_IMAGE *image=CreateImage(pix_h_end-pix_h_start,pix_w_end-pix_w_start);
  /*for (int i=initial_pos; i<=final_pos;i++){
    if ((i<=pix_w_end * image->w+nlines-1) && (i>=pix_w_start*image->w+nlines-1)){
      image->data[j]=img->data[i];
      j++;

    }
    else{
      nlines++;
      img->data+=img->w-image->w;

    }

  }
  */
  

  printf ("%d ", nlines);
  printf("%d ",j);
  return image;
}


RGB_IMAGE * applyWatermark(RGB_IMAGE *big_img, RGB_IMAGE * other_img){



}
