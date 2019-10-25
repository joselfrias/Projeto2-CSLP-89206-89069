#include <stdio.h>
#include "binary.h"

int main(){
  BIN_IMAGE *imagem;
  imagem=LoadFromGrayFile("gray_lena.pgm");
  BIN_IMAGE *newBinImage;
  saveOnFile(imagem, "file_gray.pgm");
  newBinImage=LoadFromBinFile("file_gray.pgm");
  saveOnFile(newBinImage,"file_grayV2.pgm");

  //TODO define treshold
  return 0;
}
