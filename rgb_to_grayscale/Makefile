all: main

main: main.o gray_rgb.o
			gcc -o main main.o gray_rgb.o

main.o: main.c
			gcc -o main.o -c main.c -W -Wall

func_rgb.o: gray_rgb.c
			gcc -o gray_rgb.o -c gray_rgb.c -W -Wall

clean:
			rm -rf *.o
