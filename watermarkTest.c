#include <stdio.h>

int main(){


	//ler imagens, guardas imagens

	image[512][512];
	watermark[100][10];
	localx = 400;
	localy = 233;

	for(int i = 0; i < 100; i++){
		for(int z = 0; z < 10; z++){
			image[localx+i][localy+z]=image[localx+i][localy+z]*0.8 + watermark[i][z]+0.2;
 		}
	}

	//guardar imagem gerada

	return 0;
}