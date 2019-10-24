#include <stdio.h>
#include "binary.h"

int main(){
  BIN_IMAGE *imagem;
  imagem=LoadFromFile("bin_lena.pbm");

  saveOnFile(imagem, "file_gray.pbm");
  return 0;
}
