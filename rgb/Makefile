all: main

main: main.o func_rgb.o
			gcc -o main main.o func_rgb.o

main.o: main.c
			gcc -o main.o -c main.c -W -Wall

func_rgb.o: func_rgb.c
			gcc -o func_rgb.o -c func_rgb.c -W -Wall

clean:
			rm -rf *.o
