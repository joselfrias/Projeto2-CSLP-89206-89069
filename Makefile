all: main

main:main.o functions.o  

main.o:main.c
				gcc -o main.o -c main.c -W -Wall

functions.o: functions.c
					gcc -o functions.o -c functions.c -W -Wall

clean:
							rm -rf *.o
