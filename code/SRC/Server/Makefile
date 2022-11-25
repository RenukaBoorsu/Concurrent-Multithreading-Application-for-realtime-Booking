CC = g++
CFLAGS = -c -wall
LIB = ../lib
all : server 

server : $ server.o
	${CC} server.o -lpthread -o server


clean:
	rm -f *.o server 
