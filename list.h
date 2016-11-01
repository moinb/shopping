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

#ifndef __LIST_H
#define __LIST_H

typedef struct node {
	char *str;
	int m;
	struct node *next, *prev;
}node;

typedef struct list {
	node *head, *tail;
	int len;
}list;
void init(list *l);
char *remov(list *l, int pos);
void traverse(list *l);
void append(list *l, char *str,int k);
int length(list *l);
void print_in_file(list *l,char *name);
void print_list(WINDOW *menu_win,int heighlight,list *l);
void remove_element(list *l);
long int total(list *l);
#endif
