#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<ncurses.h>
#include<string.h>
#include <unistd.h>
#include<fcntl.h>
void print_file(char *p){
	int fd, x;
	char ch;

	if(p == NULL) {
		printw("\nSorry,Discription Not Available\n");
		return;
	}
	
	fd = open(p,O_RDONLY); 
	
	if(fd == -1) {
		printw("\nSorry,Discription Not Available\n");
		return;		
	}
	mvprintw(0,0,"*");
	while((x = read(fd, &ch, 1)))
		printw("%c",ch);
		
		//putchar(ch);
	close(fd);
	return ;
}

void get_popen(char *p)
{
    FILE *pf;
    char command[32];
    strcpy(command, p); 
    pf = popen(command,"r"); 
    if(pf==NULL){
    	printf("\nImage Not Found\n");
    	return;
    }
    pclose(pf);
    return;
}
