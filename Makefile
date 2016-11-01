pro: main.o files.o list.o
	cc main.o files.o list.o -lncurses -o project
main.o: main.c files.h list.h
	cc -c main.c -Wall -lncurses
list.o: list.c list.h
	cc -c list.c -Wall -lncurses
files.o: files.c files.h
	cc -c files.c files.h -Wall -lncurses
clean:
	rm *.o
