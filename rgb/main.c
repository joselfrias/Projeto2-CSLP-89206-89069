#include <stdio.h>
#include "rgb.h"

int main(){
  RGB_IMAGE *imagem;
  RGB_IMAGE *newImage;
  imagem=LoadFromFile("lena.ppm");
  saveOnFile(imagem, "file.ppm");
//  AccessPixel(imagem, 501,499);
  newImage=access_region(imagem,0,100,0,100);
  saveOnFile(newImage,"newfile.ppm");
  return 0;
}
