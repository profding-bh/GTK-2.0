CC = gcc
all:
	$(CC) -o   thread thread.c `pkg-config --cflags --libs gtk+-2.0 gthread-2.0` -std=gnu99 
.PHONEY:clean
clean:
	rm  thread
