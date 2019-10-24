#include <stdio.h>
#include "grayscale.h"

int main(){
  GRAY_IMAGE *imagem;
  imagem=LoadFromFile("gray_lena.pgm");

  saveOnFile(imagem, "file_gray.pgm");
  AccessPixel(imagem, 1,0);
  return 0;
}
