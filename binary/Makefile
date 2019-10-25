all: main

main: main.o func_bin.o
			gcc -o main main.o func_bin.o

main.o: main.c
			gcc -o main.o -c main.c -W -Wall

func_bin.o: func_bin.c
			gcc -o func_bin.o -c func_bin.c -W -Wall

clean:
			rm -rf *.o
