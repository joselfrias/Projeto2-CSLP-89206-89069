#include <stdio.h>

int main(){


	FILE *fp = fopen("gray_lena.pgm", "rb");
	unsigned char buff[512][512];
	unsigned char n;
	for(int i = 0; i < 15; i++){
		fread(&n, sizeof(char), 1, fp);
	}

	for(int i = 0; i < 512; i++){
		for(int x = 0; x < 512; x++){
			fread(&n, sizeof(char), 1, fp);
			buff[i][x] = n;
		}
	}

	int kernel[9] ={-1,0,1,
					0,0,0,
					1,0,-1};

	unsigned char newBuff[512][512];
	for(int i = 0; i < 512; i++){
		for(int z = 0; z < 512; z++){
			if(i == 0 || z == 0){
				newBuff[i][z] == 255;
			}
			else{
				int x = 0;
				int y = 0;
				for(int w = -1; w < 2; w++){
					for(int u = -1; u < 2; u++){
						x = x + (buff[i+u][z+w]*kernel[y]);
						y++;
					}	
				}
				newBuff[i][z] = x/10;
			}
		}
	}
	pclose(fp);

	FILE *wp = fopen("coisa.pgm", "wb");
	fprintf(wp, "P5\n%d %d\n255\n", 512, 512);
	for(int i = 0; i < 512; i++){
		for(int z = 0; z < 512; z++){
			fwrite(&newBuff[i][z], sizeof(char), 1, wp);
		}
	}
	return 0;
}