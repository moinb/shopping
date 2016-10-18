pro: main.o files.o
	cc main.o files.o -lncurses -o pro
main.o: main.c files.h 
	cc -c main.c -lncurses
files.o: files.c files.h
	cc -c files.c files.h -lncurses
