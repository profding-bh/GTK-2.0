CC = gcc
all:
	$(CC) -o hello hello.c `pkg-config --cflags --libs gtk+-2.0`
.PHONY:clean
clean:
	rm hello
