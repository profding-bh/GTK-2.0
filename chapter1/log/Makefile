CC = gcc
all:
	$(CC) -o log  log.c `pkg-config --cflags --libs gtk+-2.0`
.PHONEY:clean
clean:
	rm log
