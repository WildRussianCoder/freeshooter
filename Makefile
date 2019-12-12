all: main.out

main.out: main.o
	gcc main.o -o main.out -lSDL2

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm *.o*
