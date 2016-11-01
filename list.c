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

#include<stdio.h>
#include<string.h>
#include<ncurses.h>
#include<stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include "list.h"

/****************************************************************************************************/

//iniatialize list
void init(list *l){
	l->head = l->tail = NULL;
	l->len = 0;
}
/****************************************************/

//to remove some content of list
char *remov(list *l, int position){
	int i;
	node *p,*sudo;
	char *str;
	if(position < 0 || position > l->len-1)
		return NULL;	
	if(l->head==NULL)
		return NULL;
	p=l->head;
	if(position==0){
		l->head=p->next;
		if(l->len != 1)
			l->head->prev=NULL;
		str = (char *)malloc(strlen(p->str) + 1);
		strcpy(str,p->str);
		free(p);
		l->len--;
		return str;
	}
	if(position==l->len-1){
		p=l->tail->prev;
		p->next=NULL;
		str = (char *)malloc(strlen(l->tail->str) + 1);
		strcpy(str,l->tail->str);
		free(l->tail);
		l->tail=p;
		l->len--;
		return str;
	}
		
	for(i=0;i<position-1;i++)
		p=p->next;
	str = (char *)malloc(strlen(l->tail->str) + 1);
	strcpy(str,p->next->str);
	sudo=p->next;
	p->next=p->next->next;
	free(sudo);
	p->next->prev=p;
	l->len--;
	return str;
}
/****************************************************/

// to display list
void traverse(list *l){
	clear();
	box(stdscr,0,0);
	node *p;
	int i=0;
	int x,y;
	x=2;
	y=2;
	p = l->head;
	if(p==NULL) {
		return;
	}
	 while(i < l->len){
		mvwprintw(stdscr,y,x," %s ", p->str);
		p = p->next;
		i++;
		y++;
		}
	wgetch(stdscr);
	return;
}
/****************************************************/

// addind content to list
void append(list *l, char *str,int k) {
	node *tmp;
	tmp = (node *)malloc(sizeof(node));
	tmp->str = (char *)malloc(strlen(str) + 1);	
	strcpy(tmp->str, str);
	tmp->m=k;
	if(l->head == NULL) {
		tmp->next = tmp->prev =NULL;
		l->head = l->tail = tmp;
		l->len++;
		return;		
	}
	tmp->next=NULL;
	tmp->prev=l->tail;
	l->tail->next=tmp;
	l->tail = tmp;
	l->len++;
	return;

}
/****************************************************/

// to calculate length of list
int length(list *l) {
	return l->len;
}
/****************************************************/

// to print list for removing some content
void remove_element(list *l){
	int c,heighlight=1;
	int choice=0;
	clear();
	box(stdscr,0,0);
	keypad(stdscr,TRUE);
	refresh();
	mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
	mvprintw(36,45,"PRESS b FOR BACK");
	print_list(stdscr,heighlight,l);
		while(1){
		c=wgetch(stdscr);
		switch(c){
			case KEY_UP:
				if (heighlight==1)
					heighlight=l->len;
				else
					heighlight=heighlight-1;
				break;
			case KEY_DOWN:
				if (heighlight==l->len)
					heighlight=1;
				else
					heighlight=heighlight+1;
				break;
			case 10:
				choice=heighlight;
				break;
			case 98:
				choice= 'b';
				break;
			case 66:
				choice= 'B';
				break;
			default:
				//mvprintw(24,0,"character pressed is %3d printed well???\n",c);
				refresh();
				break;
				
		}
		print_list(stdscr,heighlight,l);
		if(choice !=0)
			break;
	}
	if(choice == 'b' || choice == 'B' ){
		clear();
		return;
		}
	remov(l,(heighlight-1));
	clear();
	remove_element(l);
	return;
}


void print_list(WINDOW *menu_win,int heighlight,list *l){
	int i,x=2,y=2;
	node *p;
	p=l->head;
	box(menu_win,0,0);
	for(i=0;i<l->len;++i){
		if (heighlight==i+1){
			wattron(menu_win,A_REVERSE | A_BOLD);
			mvwprintw(menu_win,y,x," %s ",p->str);
			wattroff(menu_win,A_REVERSE | A_BOLD);
		}
		else	
			mvwprintw(menu_win,y,x," %s ",p->str);
		++y;
		p=p->next;
	}
	wrefresh(menu_win);
}

//to print list in file
void print_in_file(list *l,char *name){
	FILE *fp;
	node *p;
	int j,i=0;
	j=l->len;
	fp=fopen(name,"a+");
	p=l->head;
	while(i<j){
		fprintf(fp,"%s\t%d\n",p->str,p->m);
		p=p->next;
		i++;
	}
	fclose(fp);
	return;
}
/****************************************************/

//ading all integer content of list
long int total(list *l){
	long int a=0;
	int t;
	node *p;
	p=l->head;
	for(t=0;t<l->len;t++){
		a= a + p->m;
		p=p->next;
	}
	return a;
}
/****************************************************/

