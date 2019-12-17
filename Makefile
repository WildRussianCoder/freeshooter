.PHONY: clean

TARGET = freeshooter

OBJS = main.o

LIBS = -lGL -lGLU -lglfw -lGLEW -lX11 -lpthread -lXrandr -lXi

$(TARGET): $(OBJS)
	gcc -o $(TARGET) $(OBJS) $(LIBS)

main.o: main.c

clean:
	rm $(OBJS) $(TARGET)
