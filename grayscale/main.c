#include <stdio.h>
#include "grayscale.h"

int main(){
  GRAY_IMAGE *imagem;
  imagem=LoadFromFile("gray_lena.pgm");
  GRAY_IMAGE *newImage;
  saveOnFile(imagem, "file_gray.pgm");
  newImage=change_intensity(imagem, 200);
  saveOnFile(newImage,"intens_gray.pgm");
  return 0;
}
