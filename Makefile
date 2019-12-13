.PHONY: clean

OBJS = main.o

main.exe: $(OBJS)
	gcc $(OBJS) -lfreeglut -lopengl32 -lglu32 -o main.exe

main.o: main.c

clean:
	rm *.o main.exe
