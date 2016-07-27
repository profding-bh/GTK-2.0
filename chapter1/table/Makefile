CC = gcc
all:
	$(CC) -o table table.c `pkg-config --cflags --libs gtk+-2.0`
.PHONY:clean
clean:
	rm table
