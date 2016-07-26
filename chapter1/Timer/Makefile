CC = gcc
all:
	$(CC) -o timer timer.c `pkg-config --cflags --libs gtk+-2.0`
.PHONEY:clean
clean:
	rm timer
