#include <sdtio.h>
#include <stdlib.h>


int main(){

  GRAY_IMAGE * img;
  img=LoadFromFile("gray_lena.pgm");

  convertToBinary(img);
  

}
