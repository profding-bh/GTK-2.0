CC = gcc
all:
	$(CC) -o login login.c `pkg-config --cflags --libs gtk+-2.0`
.PHONY:clean
clean:
	rm login
