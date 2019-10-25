#include <stdio.h>
#include "rgb.h"

int main(){
  RGB_IMAGE *imagem;
  RGB_IMAGE *newImage;
  imagem=LoadFromFile("lena.ppm");
  saveOnFile(imagem, "file.ppm");
//  AccessPixel(imagem, 501,499);
  newImage=access_region(imagem,0,255,0,255);
  printf("%d\n",newImage->size);
  saveOnFile(newImage,"newfile.ppm");
  /*
  newImage=change_intensity(imagem, -100);
  saveOnFile(newImage,"intensity.ppm");
*/

  return 0;
}
