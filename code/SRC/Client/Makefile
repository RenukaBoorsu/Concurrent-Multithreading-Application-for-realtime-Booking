CC = g++
CFLAGS = -c -wall
LIB = ../lib
all : client

client : $ client.o
	${CC} client.o -lpthread -o client

clean:
	rm -f *.o client
