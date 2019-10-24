all: main

main: main.o func_gray.o
			gcc -o main main.o func_gray.o

main.o: main.c
			gcc -o main.o -c main.c -W -Wall

func_gray.o: func_gray.c
			gcc -o func_gray.o -c func_gray.c -W -Wall

clean:
			rm -rf *.o
