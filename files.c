/********************************************************************************************************
 * 		Copyright (C) MOIN BANGI moin.bangi@live.com                            		*
 *									          	  		*
 *		 This program is free software; you can redistribute it and/or modify it        	*
 *		 under the terms of the GNU Lesser General Public License as published by		*
 * 		 the Free Software Foundation; either version 2.1 of the License, or      		*
 * 		 (at your option) any later version.                                      		*
 *        								          	 		*
 *		 This program is distributed in the hope that it will be useful,         		*
 * 		 but WITHOUT ANY WARRANTY; without even the implied warranty of	          		*
 * 		 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                   	*
 *		 GNU Lesser General Public License for more details.                      		*
 * 									     		  		*
 * 		 You should have received a copy of the GNU Lesser General Public License 		*
 * 		 along with this program; if not, write to the Free Software Foundation,  		*
 * 		 Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.        		*
 ********************************************************************************************************/


/******************************************* header files *******************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<ncurses.h>
#include<string.h>
#include <unistd.h>
#include<fcntl.h>

/****************************************************************************************************/

//function to print given file

void print_file(char *p){
	int fd, x;
	char ch;

	if(p == NULL) {
		mvprintw(2,2,"\nSorry,Discription Not Available\n");
		return;
	}
	
	fd = open(p,O_RDONLY); 
	
	if(fd == -1) {
		mvprintw(2,2,"\nSorry,Discription Not Available\n");
		return;		
	}
	mvprintw(0,0,"|*");
	while((x = read(fd, &ch, 1)))
		printw("%c",ch);
		
	close(fd);
	return ;
}
/***********************************************************************/

// function to display image or text file
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
/***********************************************************************/
