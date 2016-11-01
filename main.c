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
#include<time.h>
#include<fcntl.h>
#include "files.h"
#include "list.h"
#define WIDTH 30
#define HEIGHT 10

/*******************************************global variables and pointers*******************************************/

int startx=0;
int starty=0;
int pin=1864;
int flag=0;
list cart;		/* list stores cart items */
long int number=0;	/* mobile number	  */
long int card_number=0;
long int amount=0;
char ch,password[16],name[16],email[64];
char *choices[]={
	"Electronics    ",
	"Fashion        ",
	"Music          ",  
	"Sports         ",
	"Change Address ",
	"GO TO CART     ",
	"EXIT           ",
	};
	
char *choices1[]={  
	"APPLE : iPHONE 7 at RS 85000       ",
	"REDMI : REDMI NOTE 3 at RS 11999   ",
	"SAMSUNG: ON 7 PRO MOBILE at RS 9990",
	"DELL LAPTOP: DELL 5559 at RS 54990 ",
	"HP LAPTOP: HP PAVILLION at RS 15999",
	"SONY TV : BRAVIA KVL 32 at RS 34879",
	"GO TO CART                         ",
	"BACK                               ",
	"EXIT                               ",
	};
	
char *choices2[]={
	"VIEW IMAGE  ",
	"ADD TO CART ",
	"GO TO CART  ",
	"BACK        ",
	"EXIT        ",
	};

	
	
char *choices3[]={  
	"ACTION SHOES at RS 1240           ",
	"PUMA SHOES at RS 1999             ",
	"AMERICAN TOURISTER BAG at RS 1499 ",
	"SKYLINE TRAVEL BAG at RS 1015     ",
	"TIMEX EXPEDITION WATCH at RS 1859 ",
	"TIMEX ANALOG WATCH at RS 809      ",
	"GO TO CART                        ",
	"BACK                              ",
	"EXIT                              ",
	};
	
char *choices4[]={  
	"MI EARPHONE at RS 999          ",
	"JBL T150 EARPHONE at RS 1399   ",
	"JBL C300 HEADHONE at RS 999    ",
	"SKULLCANDY EARPHONE at RS 599  ",
	"JBL PORTABLE SPEAKER at RS 2399",
	"SONY HEADPHONE at RS 648       ",
	"GO TO CART                     ",
	"BACK                           ",
	"EXIT                           ",
	};
	

char *choices5[]={
	"PROCEED TO PAY   ",
	"VIEW CART ITEMS  ",
	"REMOVE CART ITEMS",
	"HOME             ",
	"EXIT             ",
	};
	
	
char *choices6[]={
	"CREDIT CARD     ",
	"DEBIT CARD      ",
	"CASH ON DELIVERY",
	"BACK            ",
	"EXIT            ",
	};
	
char *choices7[]={
	"NO             ",
	"YES            ",
	};

char *choices8[]={  
	"NIVIA RUNNING SHOES at RS 872",
	"GM CRICKET KIT at RS 4799    ",
	"ADIDAS FOOTBALL at RS 349    ",
	"NIVIA FOOTBALL STUD at RS899 ",
	"GO TO CART                   ",
	"BACK                         ",
	"EXIT                         ",
	};
		
int n_choices=sizeof(choices)/sizeof(char*);
int n_choices1=sizeof(choices1)/sizeof(char*);
int n_choices2=sizeof(choices2)/sizeof(char*);
int n_choices3=sizeof(choices3)/sizeof(char*);
int n_choices4=sizeof(choices4)/sizeof(char*);
int n_choices5=sizeof(choices5)/sizeof(char*);
int n_choices6=sizeof(choices6)/sizeof(char*);
int n_choices7=sizeof(choices7)/sizeof(char*);
int n_choices8=sizeof(choices8)/sizeof(char*);

/*********************************************************************************************************************************/

/*********************************************   function declaration   *******************************************************/
void menu();
void electronics();

void fashion();
void music();
void sports();
void payment();
void alert();
void card(int i);
void print();
void bill(int i);
void thank_you();
void message(int i);
void interior(WINDOW *menu_win,char *,char *caller,char *item,int m);
void go_to_cart();
void print_menu(WINDOW *menu_win,int heighlight);
void print_menu1(WINDOW *menu_win,int heighlight);
void print_menu2(WINDOW *menu_win,int heighlight);
void print_menu3(WINDOW *menu_win,int heighlight);
void print_menu4(WINDOW *menu_win,int heighlight);
void print_menu5(WINDOW *menu_win,int heighlight);
void print_menu6(WINDOW *menu_win,int heighlight);
void print_menu7(WINDOW *menu_win,int heighlight);
void print_menu8(WINDOW *menu_win,int heighlight);

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/

int main(){

	init(&cart);
	initscr();
	clear();
	refresh();
	cbreak();
	start_color();
	int len,i;
	startx = (50-WIDTH)/2;
	starty = (24-HEIGHT)/2;
	/***********************************************************************************************/
    	init_pair(1,COLOR_CYAN,COLOR_BLACK);
    	wbkgd(stdscr, COLOR_PAIR(1));
    	box(stdscr,0,0);
    	mvprintw(14,20,"enter your name         >    ");
    	scanw("%s",name);
    	mvprintw(16,20,"enter your email        >    ");
    	scanw("%s",email);
    	mvprintw(18,20,"enter your mobile number>    ");
    	scanw("%ld",&number);
    	noecho();
    	mvprintw(20,20,"your  password          >    ");
   	scanw("%s",password);
   	i=0;
   	i=strcmp(password,"coep");
   	if(i != 0){				// Opps !!!  wrong password.
   		refresh();
		endwin();
		return 0;
   	}
   	clrtoeol();
   	clear();
   	refresh();
   	/***********************************************************************************************/
   	FILE *fp;
	fp=fopen("your_address.txt","w");
	fprintf(fp,"SHIVAJI NAGAR POST OFFICE\n");
	fprintf(fp,"NEAR COEP HOSTEL,\nWELESELLY ROAD,\nSHIVAJI NAGAR,\nPUNE 411 005 .\n\n");
	fclose(fp);
	/***********************************************************************************************/
	menu();
	/***********************************************************************************************/
	/************************************ to free all nodes in cart ********************************/
	len=length(&cart);
	for(i=0;i<len;i++){
		remov(&cart,0);
	}
	/***********************************************************************************************/
	refresh();
	endwin();
	return 0;
}
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
void menu(){
	clear();
	refresh();
	
	WINDOW *menu_win;
	curs_set (0);		/* to stop blinking of cursor*/
	int heighlight=1;
	int c,choice=0;
	
	menu_win=newwin(HEIGHT,WIDTH,startx,starty);
   	box(stdscr,0,0);
	keypad(menu_win,TRUE);
	init_pair(2,COLOR_RED,COLOR_WHITE);
	attron(COLOR_PAIR (2));
	mvprintw(5,20,"welcome %s",name);
	attroff(COLOR_PAIR (2));
	
	keypad(menu_win,TRUE);
	mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
	refresh();
	print_menu(menu_win,heighlight);
	while(1){
		c=wgetch(menu_win);
		switch(c){
			case KEY_UP:
				if (heighlight==1)
					heighlight=n_choices;
				else
					heighlight=heighlight-1;
				break;
			case KEY_DOWN:
				if (heighlight==n_choices)
					heighlight=1;
				else
					heighlight=heighlight+1;
				break;
			case 10:
				choice=heighlight;
				break;
			default:
				refresh();
				break;
				
		}
		print_menu(menu_win,heighlight);
		if(choice !=0)
			break;
	}
	clrtoeol();
   	clear();
   	refresh();
   	delwin(menu_win);
   	
   	if(heighlight==1){
		clear();
		refresh();
		electronics();
		refresh();
		return ;
	}
	if(heighlight==2){
		clear();
		refresh();
		fashion();
		refresh();
		return ;
	}
	if(heighlight==3){
		clear();
		refresh();
		music();
		refresh();
		return ;
	}
	if(heighlight==4){
		clear();
		refresh();
		sports();
		refresh();
		return ;
	}
	if(heighlight==5){
		clear();
		refresh();
		get_popen("gedit your_address.txt");
		menu();
		refresh();
		return ;
	}
	if(heighlight==6){
		clear();
		refresh();
		go_to_cart();
		refresh();
		return ;
	}
	if(heighlight==7){
		clear();
		refresh();
		alert();		/* alert on pressing  exit */
		refresh();
		return ;
	}
	refresh();
   	return;
}

void print_menu(WINDOW *menu_win,int heighlight){
	int i,x=2,y=2;
	box(menu_win,0,0);
	for(i=0;i<n_choices;++i){
		if (heighlight==i+1){
			wattron(menu_win,A_REVERSE | A_BOLD);
			mvwprintw(menu_win,y,x," %s ",choices[i]);
			wattroff(menu_win,A_REVERSE | A_BOLD);
		}
		else	
			mvwprintw(menu_win,y,x," %s ",choices[i]);
			++y;
	}
	wrefresh(menu_win);
}
/*********************************************************************************************************************************/

/**************************************     electronics section         **********************************************************/
void electronics(){
	WINDOW *menu_win,*menu_win2;
	int heighlight=1;
	int c,m,choice=0;
	char previous[16],item[64];
	strcpy(previous,"electronics");
	clear();
	refresh();
	startx = (50-WIDTH)/2;
	starty = (24-HEIGHT)/2;
	init_pair(3,COLOR_MAGENTA,COLOR_WHITE);
	/***********************************************************************************************/
	menu_win=newwin(21,40,8,10);
	wbkgd(menu_win, COLOR_PAIR(3));
	wrefresh(menu_win);
	box(stdscr,0,0);
	
	keypad(menu_win,TRUE);

	mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
	refresh();
	print_menu1(menu_win,heighlight);
	while(1){
		c=wgetch(menu_win);
		switch(c){
			case KEY_UP:
				if (heighlight==1)
					heighlight=n_choices1;
				else
					heighlight=heighlight-1;
				break;
			case KEY_DOWN:
				if (heighlight==n_choices1)
					heighlight=1;
				else
					heighlight=heighlight+1;
				break;
			case 10:
				choice=heighlight;
				break;
			default:
				refresh();
				break;
				
		}
		print_menu1(menu_win,heighlight);
		if(choice !=0)
			break;
	}
	clrtoeol();
   	clear();
   	refresh();
   	delwin(menu_win);
   	/***********************************************************************************************/
   	menu_win2=newwin(HEIGHT,WIDTH,startx+10,starty+20);
	wbkgd(menu_win2, COLOR_PAIR(3));
	wrefresh(menu_win2);
	box(stdscr,0,0);
	
	keypad(menu_win2,TRUE);
	attron(COLOR_PAIR (2));
	mvprintw(34,45,"PRESS KEY f TO VIEW FEATURE");
	attroff(COLOR_PAIR (2));
	mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
	refresh();
   	char arr[32];
   	
   	if(heighlight==1){
		strcpy(arr,"iphone7.txt");
		print_file(arr);
		strcpy(arr,"eog iphone7.png");
		strcpy(item,"APPLE iPHONE 7                               ");
		m=85000;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==2){
		strcpy(arr,"note3.txt");
		print_file(arr);
		strcpy(arr,"eog note3.png");
		strcpy(item,"XIOMI REDMI NOTE 3 MOBILE                    ");
		m=11999;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==3){
		strcpy(arr,"samsungon7.txt");
		print_file(arr);
		strcpy(arr,"eog samsungon7.png");
		strcpy(item,"SAMSUNG ON 7 PRO MOBILE                      ");
		m=9990;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==4){
		strcpy(arr,"dell5559.txt");
		print_file(arr);
		strcpy(arr,"eog dell5559.png");
		strcpy(item,"DELL INSPRION 5559 LAPTOP                    ");
		m=54990;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==5){
		strcpy(arr,"hp.txt");
		print_file(arr);
		strcpy(arr,"eog hp.png");
		strcpy(item,"HP PAVLLION S003TU LAPTOP                   ");
		m=15999;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==6){
		strcpy(arr,"sony.txt");
		print_file(arr);
		strcpy(arr,"eog sony.png");
		strcpy(item,"SONY BRAVIA KVL-32W562D TV                  ");
		m=34879;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
		}
	if(heighlight==7){
   		clear();
   		refresh();
		go_to_cart();
		refresh();
		return ;
	}
   	if(heighlight==8){
   		clear();
   		refresh();
		menu();
		refresh();
		return ;
	}
	if(heighlight==9){
		clear();
		refresh();
		alert();		/* alert on pressing  exit */
		refresh();
		return ;
	}
   	return;	
}
void print_menu1(WINDOW *menu_win,int heighlight){
	int i,x=2,y=2;
	box(menu_win,0,0);
	for(i=0;i<n_choices1;++i){
		if (heighlight==i+1){
			wattron(menu_win,A_REVERSE | A_BOLD);
			mvwprintw(menu_win,y,x," %s ",choices1[i]);
			wattroff(menu_win,A_REVERSE | A_BOLD);
		}
		else	
			mvwprintw(menu_win,y,x," %s ",choices1[i]);
		++y;
	}
	wrefresh(menu_win);
}


/************************************** end of electronics section  **********************************************************/

/*****************************************************************************************************************************/



/**************************************     fashion section         **********************************************************/


void fashion(){
	WINDOW *menu_win,*menu_win2;
	int heighlight=1;
	int c,m,choice=0;
	char previous[16],item[64];
	//char *array;
	strcpy(previous,"fashion");
	clear();
	refresh();
	startx = (50-WIDTH)/2;
	starty = (24-HEIGHT)/2;
	init_pair(3,COLOR_MAGENTA,COLOR_WHITE);
	/***********************************************************************************************/
	menu_win=newwin(21,40,8,10);
	wbkgd(menu_win, COLOR_PAIR(3));
	wrefresh(menu_win);
	box(stdscr,0,0);
	
	keypad(menu_win,TRUE);

	mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
	refresh();
	print_menu3(menu_win,heighlight);
	while(1){
		c=wgetch(menu_win);
		switch(c){
			case KEY_UP:
				if (heighlight==1)
					heighlight=n_choices3;
				else
					heighlight=heighlight-1;
				break;
			case KEY_DOWN:
				if (heighlight==n_choices3)
					heighlight=1;
				else
					heighlight=heighlight+1;
				break;
			case 10:
				choice=heighlight;
				break;
			default:
				refresh();
				break;
				
		}
		print_menu3(menu_win,heighlight);
		if(choice !=0)
			break;
	}
	clrtoeol();
   	clear();
   	refresh();
   	delwin(menu_win);
   	/***********************************************************************************************/
   	menu_win2=newwin(HEIGHT,WIDTH,startx+10,starty+20);
	wbkgd(menu_win2, COLOR_PAIR(3));
	wrefresh(menu_win2);
	box(stdscr,0,0);
	
	int s;
	
	keypad(menu_win2,TRUE);
	attron(COLOR_PAIR (2));
	mvprintw(34,45,"PRESS KEY f TO VIEW FEATURE");
	attroff(COLOR_PAIR (2));
	mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
	refresh();
   	char arr[32];
   	
   	if(heighlight==1){
   		/******************************************************/
   		clear();
   		refresh();
   		curs_set (1);
   		echo();
   		mvprintw(22,45,"enter your shoe size (AVAILABLE FROM 7 TO 12)>");
		scanw("%d",&s);								// taking shoe size
		clear();
		refresh();
		noecho();
		curs_set (0);
		refresh();
		
		
		
		if((s<7) || (s>12)){                      //if shoe size is wrong
			clear();
			refresh();
			fashion();
			refresh();
			return ;
		}
		
		/******************************************************/
		attron(COLOR_PAIR (2));
		mvprintw(34,45,"PRESS KEY f TO VIEW FEATURE");
		attroff(COLOR_PAIR (2));
		mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
		refresh();
		/******************************************************/
		strcpy(arr,"action.txt");
		print_file(arr);
		strcpy(arr,"eog action.png");
		
		/* copying appropriate name to "item" */
		
		if(s == 7){
			strcpy(item,"ACTION  SHOES SIZE 7                          ");
		}
		else if(s == 8){
			strcpy(item,"ACTION SHOES SIZE 8                          ");
		}
		else if(s == 9){
			strcpy(item,"ACTION SHOES SIZE 9                          ");
		}
		else if(s == 10){
			strcpy(item,"ACTION SHOES SIZE 10                          ");
		}
		else if(s == 11){
			strcpy(item,"ACTION SHOES SIZE 11                          ");
		}
		else if(s == 12){
			strcpy(item,"ACTION SHOES SIZE 12                          ");
		}
		
		m=1240;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==2){
		/******************************************************/
   		clear();
   		refresh();
   		curs_set (1);
   		echo();
   		mvprintw(22,45,"enter your shoe size>");		//taking shoe size
		scanw("%d",&s);
		clear();
		refresh();
		noecho();
		curs_set (0);
		refresh();
		
		if((s<7) || (s>12)){					//if shoe size is wrong
			clear();
			refresh();
			fashion();
			refresh();
			return ;
		}
	
		/******************************************************/
		attron(COLOR_PAIR (2));
		mvprintw(34,45,"PRESS KEY f TO VIEW FEATURE");
		attroff(COLOR_PAIR (2));
		mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
		refresh();
		/******************************************************/
		strcpy(arr,"puma.txt");
		print_file(arr);
		strcpy(arr,"eog puma.png");
		
		/* copying appropriate name to "item" */
		if(s == 7){
			strcpy(item,"PUMA   SHOES SIZE 7                          ");
		}
		else if(s == 8){
			strcpy(item,"PUMA   SHOES SIZE 8                          ");
		}
		else if(s == 9){
			strcpy(item,"PUMA   SHOES SIZE 9                          ");
		}
		else if(s == 10){
			strcpy(item,"PUMA   SHOES SIZE 10                         ");
		}
		else if(s == 11){
			strcpy(item,"PUMA   SHOES SIZE 11                         ");
		}
		else if(s == 12){
			strcpy(item,"PUMA   SHOES SIZE 12                         ");
		}
		
		m=1999;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==3){
		strcpy(arr,"american.txt");
		print_file(arr);
		strcpy(arr,"eog american.png");
		strcpy(item,"AMERICAN TOURISTER BAG                       ");
		m=1499;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==4){
		strcpy(arr,"skyline.txt");
		print_file(arr);
		strcpy(arr,"eog skyline.png");
		strcpy(item,"SKYLINE TRAVEL BAG                           ");
		m=1015;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==5){
		strcpy(arr,"timex_expedition.txt");
		print_file(arr);
		strcpy(arr,"eog timex_expedition.png");
		strcpy(item,"TIMEX EXPEDITION (ANALOG+DIGITAL) WATCH      ");
		m=1859;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==6){
		strcpy(arr,"timex_analog.txt");
		print_file(arr);
		strcpy(arr,"eog timex_analog.png");
		strcpy(item,"TIMEX EXPEDITION ANALOG WATCH                ");
		m=809;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
		}
	if(heighlight==7){
   		clear();
   		refresh();
		go_to_cart();
		refresh();
		return ;
	}
   	if(heighlight==8){
   		clear();
   		refresh();
		menu();
		refresh();
		return ;
	}
	if(heighlight==9){
		clear();
		refresh();
		alert();		/* alert on pressing  exit */
		refresh();
		return ;
	}
   	return;	
}
void print_menu3(WINDOW *menu_win,int heighlight){
	int i,x=2,y=2;
	box(menu_win,0,0);
	for(i=0;i<n_choices3;++i){
		if (heighlight==i+1){
			wattron(menu_win,A_REVERSE | A_BOLD);
			mvwprintw(menu_win,y,x," %s ",choices3[i]);
			wattroff(menu_win,A_REVERSE | A_BOLD);
		}
		else	
			mvwprintw(menu_win,y,x," %s ",choices3[i]);
		++y;
	}
	wrefresh(menu_win);
}



/**************************************   end of fashion section       **********************************************************/

/********************************************************************************************************************************/


/**************************************   music section       *******************************************************************/

void music(){
	WINDOW *menu_win,*menu_win2;
	int heighlight=1;
	int c,m,choice=0;
	char previous[16],item[64];
	strcpy(previous,"music");
	clear();
	refresh();
	startx = (50-WIDTH)/2;
	starty = (24-HEIGHT)/2;
	init_pair(3,COLOR_MAGENTA,COLOR_WHITE);
	/***********************************************************************************************/
	menu_win=newwin(21,40,8,10);
	wbkgd(menu_win, COLOR_PAIR(3));
	wrefresh(menu_win);
	box(stdscr,0,0);
	
	keypad(menu_win,TRUE);

	mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
	refresh();
	print_menu4(menu_win,heighlight);
	while(1){
		c=wgetch(menu_win);
		switch(c){
			case KEY_UP:
				if (heighlight==1)
					heighlight=n_choices4;
				else
					heighlight=heighlight-1;
				break;
			case KEY_DOWN:
				if (heighlight==n_choices4)
					heighlight=1;
				else
					heighlight=heighlight+1;
				break;
			case 10:
				choice=heighlight;
				break;
			default:
				refresh();
				break;
				
		}
		print_menu4(menu_win,heighlight);
		if(choice !=0)
			break;
	}
	clrtoeol();
   	clear();
   	refresh();
   	delwin(menu_win);
   	/***********************************************************************************************/
   	menu_win2=newwin(HEIGHT,WIDTH,startx+10,starty+20);
	wbkgd(menu_win2, COLOR_PAIR(3));
	wrefresh(menu_win2);
	box(stdscr,0,0);
	
	keypad(menu_win2,TRUE);
	attron(COLOR_PAIR (2));
	mvprintw(34,45,"PRESS KEY f TO VIEW FEATURE");
	attroff(COLOR_PAIR (2));
	mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
	refresh();
   	char arr[32];
   	
   	if(heighlight==1){
		strcpy(arr,"mi.txt");
		print_file(arr);
		strcpy(arr,"eog mi.png");
		strcpy(item,"MI EARPHONE                                 ");
		m=999;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==2){
		strcpy(arr,"jbl.txt");
		print_file(arr);
		strcpy(arr,"eog jbl.png");
		strcpy(item,"JBL EARPHONE   T150A                        ");
		m=1399;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==3){
		strcpy(arr,"jbl_c300.txt");
		print_file(arr);
		strcpy(arr,"eog jbl_c300.png");
		strcpy(item,"JBL C300 HEADPHONE                          ");
		m=999;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==4){
		strcpy(arr,"skullcandy.txt");
		print_file(arr);
		strcpy(arr,"eog skullcandy.png");
		strcpy(item,"SKULLCANDY EARPHONE                          ");
		m=599;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==5){
		strcpy(arr,"jbl_speaker.txt");
		print_file(arr);
		strcpy(arr,"eog jbl_speaker.png");
		strcpy(item,"JBL PORTABLE SPEAKER                         ");
		m=2399;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==6){
		strcpy(arr,"sony_headphone.txt");
		print_file(arr);
		strcpy(arr,"eog sony_headphone.png");
		strcpy(item,"SONY HEADPHONE                               ");
		m=648;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
		}
	if(heighlight==7){
   		clear();
   		refresh();
		go_to_cart();
		refresh();
		return ;
	}
   	if(heighlight==8){
   		clear();
   		refresh();
		menu();
		refresh();
		return ;
	}
	if(heighlight==9){
		clear();
		refresh();
		alert();		/* alert on pressing  exit */
		refresh();
		return ;
	}
   	return;	
}
void print_menu4(WINDOW *menu_win,int heighlight){
	int i,x=2,y=2;
	box(menu_win,0,0);
	for(i=0;i<n_choices4;++i){
		if (heighlight==i+1){
			wattron(menu_win,A_REVERSE | A_BOLD);
			mvwprintw(menu_win,y,x," %s ",choices4[i]);
			wattroff(menu_win,A_REVERSE | A_BOLD);
		}
		else	
			mvwprintw(menu_win,y,x," %s ",choices4[i]);
		++y;
	}
	wrefresh(menu_win);
}




/**************************************   end of music section       **********************************************************/

/******************************************************************************************************************************/



/**************************************   SPORTS section       *******************************************************************/

void sports(){
	WINDOW *menu_win,*menu_win2;
	int heighlight=1;
	int c,m,s,choice=0;
	char previous[16],item[64];
	strcpy(previous,"sports");
	clear();
	refresh();
	startx = (50-WIDTH)/2;
	starty = (24-HEIGHT)/2;
	init_pair(3,COLOR_MAGENTA,COLOR_WHITE);
	/***********************************************************************************************/
	menu_win=newwin(21,40,8,10);
	wbkgd(menu_win, COLOR_PAIR(3));
	wrefresh(menu_win);
	box(stdscr,0,0);
	
	keypad(menu_win,TRUE);

	mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
	refresh();
	print_menu8(menu_win,heighlight);
	while(1){
		c=wgetch(menu_win);
		switch(c){
			case KEY_UP:
				if (heighlight==1)
					heighlight=n_choices8;
				else
					heighlight=heighlight-1;
				break;
			case KEY_DOWN:
				if (heighlight==n_choices8)
					heighlight=1;
				else
					heighlight=heighlight+1;
				break;
			case 10:
				choice=heighlight;
				break;
			default:
				refresh();
				break;
				
		}
		print_menu8(menu_win,heighlight);
		if(choice !=0)
			break;
	}
	clrtoeol();
   	clear();
   	refresh();
   	delwin(menu_win);
   	/***********************************************************************************************/
   	menu_win2=newwin(HEIGHT,WIDTH,startx+10,starty+20);
	wbkgd(menu_win2, COLOR_PAIR(3));
	wrefresh(menu_win2);
	box(stdscr,0,0);
	
	keypad(menu_win2,TRUE);
	attron(COLOR_PAIR (2));
	mvprintw(34,45,"PRESS KEY f TO VIEW FEATURE");
	attroff(COLOR_PAIR (2));
	mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
	refresh();
   	char arr[32];
   	
   	if(heighlight==1){
		clear();
   		refresh();
   		curs_set (1);
   		echo();
   		mvprintw(22,45,"enter your shoe size>");
		scanw("%d",&s);					//taking shoe size
		clear();
		refresh();
		noecho();
		curs_set (0);
		refresh();
		
		if((s<7) || (s>12)){						//if shoe size is wrong
			clear();
			refresh();
			sports();
			refresh();
			return ;
		}
	
		/******************************************************/
		attron(COLOR_PAIR (2));
		mvprintw(34,45,"PRESS KEY f TO VIEW FEATURE");
		attroff(COLOR_PAIR (2));
		mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
		refresh();
		/******************************************************/
		strcpy(arr,"nivia.txt");
		print_file(arr);
		strcpy(arr,"eog nivia.png");
		
		/* copying appropriate name to "item" */
		
		if(s == 7){
			strcpy(item,"NIVIA RUNNING SHOES  SIZE 7                  ");
		}
		else if(s == 8){
			strcpy(item,"NIVIA RUNNING SHOES SIZE 8                    ");
		}
		else if(s == 9){
			strcpy(item,"NIVIA RUNNING SHOES SIZE 9                     ");
		}
		else if(s == 10){
			strcpy(item,"NIVIA RUNNING SHOES SIZE 10                    ");
		}
		else if(s == 11){
			strcpy(item,"NIVIA RUNNING  SHOES SIZE 11                   ");
		}
		else if(s == 12){
			strcpy(item,"NIVIA RUNNING SHOES SIZE 12                    ");
		}
		
		m=872;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==2){
		strcpy(arr,"cricket.txt");
		print_file(arr);
		strcpy(arr,"eog cricket.png");
		strcpy(item,"GM CRICKET KIT                               ");
		m=4799;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==3){
		strcpy(arr,"adidas.txt");
		print_file(arr);
		strcpy(arr,"eog adidas.png");
		strcpy(item,"ADIDAS FOOTBALL                             ");
		m=349;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==4){
		clear();
   		refresh();
   		curs_set (1);
   		echo();
   		mvprintw(22,45,"enter your stud size>");
		scanw("%d",&s);					//taking stud size
		clear();
		refresh();
		noecho();
		curs_set (0);
		refresh();
		
		if((s<7) || (s>12)){				//if stud size is wrong
			clear();
			refresh();
			sports();
			refresh();
			return ;
		}
	
		/******************************************************/
		attron(COLOR_PAIR (2));
		mvprintw(34,45,"PRESS KEY f TO VIEW FEATURE");
		attroff(COLOR_PAIR (2));
		mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
		refresh();
		/******************************************************/
		strcpy(arr,"fooball_stud.txt");
		print_file(arr);
		strcpy(arr,"eog football_stud.png");
		
		/* copying appropriate name to "item" */
		
		if(s == 7){
			strcpy(item,"NIVIA FOOTBALL STUD  SIZE 7                  ");
		}
		else if(s == 8){
			strcpy(item,"NIVIA FOOTBALL STUD SIZE 8                    ");
		}
		else if(s == 9){
			strcpy(item,"NIVIA FOOTBALL STUD SIZE 9                     ");
		}
		else if(s == 10){
			strcpy(item,"NIVIA RUNNING SHOES SIZE 10                    ");
		}
		else if(s == 11){
			strcpy(item,"NIVIA FOOTBALL STUD  SIZE 11                   ");
		}
		else if(s == 12){
			strcpy(item,"NIVIA FOOTBALL STUD SIZE 12                    ");
		}
		
		m=899;
		interior(menu_win2,arr,previous,item,m);
		refresh();
		return ;
	}
	if(heighlight==5){
   		clear();
   		refresh();
		go_to_cart();
		refresh();
		return ;
	}
   	if(heighlight==6){
   		clear();
   		refresh();
		menu();
		refresh();
		return ;
	}
	if(heighlight==7){
		clear();
		refresh();
		alert();		/* alert on pressing  exit */
		refresh();
		return ;
	}
   	return;	
}
void print_menu8(WINDOW *menu_win,int heighlight){
	int i,x=2,y=2;
	box(menu_win,0,0);
	for(i=0;i<n_choices8;++i){
		if (heighlight==i+1){
			wattron(menu_win,A_REVERSE | A_BOLD);
			mvwprintw(menu_win,y,x," %s ",choices8[i]);
			wattroff(menu_win,A_REVERSE | A_BOLD);
		}
		else	
			mvwprintw(menu_win,y,x," %s ",choices8[i]);
		++y;
	}
	wrefresh(menu_win);
}


/**************************************   end of sports section       **********************************************************/


/*******************************************************************************************************************************/


/**************************************interior function called in all above sections *****************************************/



void interior(WINDOW *menu_win,char *arr,char *caller,char *item,int m){
		int heighlight=1;
		int c,len,choice=0;
		print_menu2(menu_win,heighlight);
		while(1){
		c=wgetch(menu_win);
		switch(c){
			case KEY_UP:
				if (heighlight==1)
					heighlight=n_choices2;
				else
					heighlight=heighlight-1;
				break;
			case KEY_DOWN:
				if (heighlight==n_choices2)
					heighlight=1;
				else
					heighlight=heighlight+1;
				break;
			case 10:
				choice=heighlight;
				break;
			default:
				refresh();
				break;
				
		}
		print_menu2(menu_win,heighlight);
		if(choice !=0)
			break;
	}
	if(heighlight == 1){
			get_popen(arr);
			interior(menu_win,arr,caller,item,m);
			return;
	}
	if(heighlight == 2){
		len = length(&cart);
		if(len >= 25){
			message(1);
			
			// going back
			
			if(strcmp("electronics",caller) == 0)
					electronics();
				
			else if(strcmp("fashion",caller) == 0)
					fashion();
				
			else if(strcmp("music",caller) == 0)
					music();
				
			else if(strcmp("sports",caller) == 0)
					sports();
				
			refresh();
			return;	
		}
		
		append(&cart, item,m);
		message(0);
		
		// going back
		
		if(strcmp("electronics",caller) == 0)
				electronics();
			
		else if(strcmp("fashion",caller) == 0)
				fashion();
			
		else if(strcmp("music",caller) == 0)
				music();
			
		else if(strcmp("sports",caller) == 0)
				sports();
			
		refresh();
		return;	
	}
	if(heighlight==3){
   		clear();
   		refresh();
		go_to_cart();
		refresh();
		return ;
	}
	if(heighlight == 4){
		
		// going back
	
		if(strcmp("electronics",caller) == 0)
				electronics();
			
		else if(strcmp("fashion",caller) == 0)
				fashion();
				
		else if(strcmp("music",caller) == 0)
				music();
				
		else if(strcmp("sports",caller) == 0)
				sports();
				
		refresh();
		return;
	}
	if(heighlight==5){
		clear();
		refresh();
		alert();		/* alert on pressing  exit */
		refresh();
		return ;
	} 
	return;	
}

void print_menu2(WINDOW *menu_win,int heighlight){
	int i,x=2,y=2;
	box(menu_win,0,0);
	for(i=0;i<n_choices2;++i){
		if (heighlight==i+1){
			wattron(menu_win,A_REVERSE | A_BOLD);
			mvwprintw(menu_win,y,x," %s ",choices2[i]);
			wattroff(menu_win,A_REVERSE | A_BOLD);
		}
		else	
			mvwprintw(menu_win,y,x," %s ",choices2[i]);
		++y;
	}
	wrefresh(menu_win);
}

/************************************************************************************************************************/
void print(){
mvprintw(37,45,"PRODTCT ADDED TO CART SUCCESSFULLY !");
return;
	}
/************************************************************************************************************************/	
	

/**************************************    handeling cart     ***********************************************************/
void go_to_cart(){
	WINDOW *menu_win;
	int heighlight=1;
	int c,len,choice=0;
	box(stdscr,0,0);
	mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
   	menu_win=newwin(HEIGHT,WIDTH,startx,starty);
	wbkgd(menu_win, COLOR_PAIR(2));
	wrefresh(menu_win);
	//box(stdscr,0,0);
	keypad(menu_win,TRUE);
	refresh();
	print_menu5(menu_win,heighlight);
		while(1){
		c=wgetch(menu_win);
		switch(c){
			case KEY_UP:
				if (heighlight==1)
					heighlight=n_choices5;
				else
					heighlight=heighlight-1;
				break;
			case KEY_DOWN:
				if (heighlight==n_choices5)
					heighlight=1;
				else
					heighlight=heighlight+1;
				break;
			case 10:
				choice=heighlight;
				break;
			default:
				refresh();
				break;
				
		}
		print_menu5(menu_win,heighlight);
		if(choice !=0)
			break;
	}
   	if(heighlight==1){
   		len=length(&cart);
   		//if there are no items in cart
   		if(len==0){
   			attron(COLOR_PAIR (2));
   			mvprintw(36,45,"your cart is empty");
   			attroff(COLOR_PAIR (2));
   			refresh();
   			go_to_cart();
   			refresh();
			return ;
		}
   	        payment();
		refresh();
		return ;
	}
	if(heighlight==2){
		len=length(&cart);
		//if there are no items in cart
		if(len==0){		
   			attron(COLOR_PAIR (2));
   			mvprintw(36,45,"your cart is empty");
   			attroff(COLOR_PAIR (2));
   			refresh();
   			go_to_cart();
   			refresh();
			return ;
		}
		
		traverse(&cart);
		clear();
		refresh();
		go_to_cart();
		refresh();
		return ;
	}
	if(heighlight==3){
		remove_element(&cart);
		clear();
		refresh();
		go_to_cart();
		refresh();
		return ;
	}
		
	if(heighlight==4){
		menu();
		refresh();
		return ;
	}
	if(heighlight==5){
		clear();
		refresh();
		alert();		/* alert on pressing  exit */
		refresh();
		return ;
	}
		
}
void print_menu5(WINDOW *menu_win,int heighlight){
	int i,x=2,y=2;
	box(menu_win,0,0);
	for(i=0;i<n_choices5;++i){
		if (heighlight==i+1){
			wattron(menu_win,A_REVERSE | A_BOLD);
			mvwprintw(menu_win,y,x," %s ",choices5[i]);
			wattroff(menu_win,A_REVERSE | A_BOLD);
		}
		else	
			mvwprintw(menu_win,y,x," %s ",choices5[i]);
		++y;
	}
	wrefresh(menu_win);
}

/********************************************************************************************************************/

/*********************************      handeling payment    ********************************************************/
void payment(){
	WINDOW *menu_win;
	int heighlight=1;
	int c,choice=0;
	box(stdscr,0,0);
	mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
   	menu_win=newwin(HEIGHT,WIDTH,startx,starty);
	wbkgd(menu_win, COLOR_PAIR(2));
	wrefresh(menu_win);
	keypad(menu_win,TRUE);
	refresh();
	print_menu6(menu_win,heighlight);
		while(1){
		c=wgetch(menu_win);
		switch(c){
			case KEY_UP:
				if (heighlight==1)
					heighlight=n_choices6;
				else
					heighlight=heighlight-1;
				break;
			case KEY_DOWN:
				if (heighlight==n_choices6)
					heighlight=1;
				else
					heighlight=heighlight+1;
				break;
			case 10:
				choice=heighlight;
				break;
			default:
				refresh();
				break;
				
		}
		print_menu6(menu_win,heighlight);
		if(choice !=0)
			break;
	}
   	if(heighlight==1){
		card(0);
		refresh();
		return ;
	}
	if(heighlight==2){
		card(0);
		refresh();
		return ;
	}
	if(heighlight==3){
		bill(0);
		refresh();
		return ;
	}	
	if(heighlight==4){
		go_to_cart();
		refresh();
		return ;
	}
	if(heighlight==5){
		clear();
		refresh();
		alert();		/* alert on pressing  exit */
		refresh();
		return ;
	}
	refresh();
	return ;
}
void print_menu6(WINDOW *menu_win,int heighlight){
	int i,x=2,y=2;
	box(menu_win,0,0);
	for(i=0;i<n_choices6;++i){
		if (heighlight==i+1){
			wattron(menu_win,A_REVERSE | A_BOLD);
			mvwprintw(menu_win,y,x," %s ",choices6[i]);
			wattroff(menu_win,A_REVERSE | A_BOLD);
		}
		else	
			mvwprintw(menu_win,y,x," %s ",choices6[i]);
		++y;
	}
	wrefresh(menu_win);
}


/*******************************************************************************************************************/

/*********************************      handeling payment    by card        ****************************************/
void card(int i){
	int p;
	clear();
	refresh();
	box(stdscr,0,0);
	keypad(stdscr,TRUE);
	refresh();
	if(i!=0){
		attron(COLOR_PAIR (2));
		mvprintw(35,25,"WRONG PIN ");
		attroff(COLOR_PAIR (2));
		}
	echo();
	mvprintw(14,20,"enter card number         >    ");
    	scanw("%ld",&card_number);
    	noecho();
    	mvprintw(16,20,"enter card pin         >    ");
    	scanw("%d",&p);
    	if(p != pin){
    		card(1);
    		refresh();
		return ;
    	}
    	bill(1);
    	refresh();
	return ;
}

/********************************************************************************************************************/

/*********************************      generating bill      ********************************************************/
void bill(int i){
	char *p="bill.txt";
	char *a;
	char tim[32];
	time_t t;
	time(&t);
	a=ctime(&t);
	FILE *fp;
	int fd,x;
	char ch;
	fp=fopen(p,"w");
	time(&t);
	strcpy(tim,a);
	fprintf(fp,"---------------------------------\tBILL\t----------------------------\n\n");
	fprintf(fp,"COSTOMER NAME :                 %s\nCOSTOMER MOBILE NUMBER :      %ld\n",name,number);
	fprintf(fp,"COSTOMER E_MAIL :            %s\n\n",email);
	fprintf(fp,"--------------------------------------------------------------------------\nCOSTOMER ADDRESS :\n\n");
	fd=open("your_address.txt",O_RDONLY);
	while((x = read(fd, &ch, 1)))
		fprintf(fp,"%c",ch);
	fprintf(fp,"--------------------------------------------------------------------------\n\n");
	fprintf(fp,"THIS BILL GENERATED ON %s\n",tim);
	if(i == 1)
		fprintf(fp,"PAYMENT METHOD -> BY CARD\n\n");
	else
		fprintf(fp,"PAYMENT METHOD -> CASH ON DILEVERY\n\n");
	fprintf(fp,"--------------------------------------------------------------------------\n\n");
	fprintf(fp,"PRODUCTS				      PRICE\n\n");
	fclose(fp);
	close(fd);
	print_in_file(&cart,p);
	amount=total(&cart);
	fp=fopen(p,"a+");
	fprintf(fp,"--------------------------------------------------------------------------\n\n");
	fprintf(fp,"		TOTAL AMOUNT : %ld\n\n",amount);
	fprintf(fp,"--------------------------------------------------------------------------\n\n");
	fclose(fp);
	thank_you();
	return;
}

/******************************************************************************************************************/

/*********************************** say "THANK YOU TO COSTOMER" !!! **********************************************/
void thank_you(){
	    char *text = "                    CREATED BY  MOIN BANGI                                  ";
	    char *text1 = "                    THANK YOU FOR SHOPPING WITH US                    ";
	    char *text2 = "                    conditions appied,all rights reserved                    ";
	    char *scroll;
	    int text_length;
	    int i, max_x;
	    initscr();
	    // Don't show cursor
	    curs_set(0);
	    clear();
	    refresh();
	    box(stdscr,0,0);
	    init_pair(1,COLOR_CYAN,COLOR_BLACK);
	    init_pair(2,COLOR_RED,COLOR_WHITE);
	    start_color();
	    getmaxyx(stdscr, i, max_x);
	    attron(COLOR_PAIR (2));
	    mvprintw(2,25,"THANK YOU %s",name);
	    mvprintw(5,25,"PRODUCTS WILL BE DILIVEID TO YOU SOON");
	    mvprintw(8,25,"WE WILL SEND YOU MESSAGE AND INFORM YOU SOON");
	    mvprintw(11,25,"GENERATING TOUR BILL...");
	    attroff(COLOR_PAIR (2));
	    text_length = strlen(text1);
	    scroll = malloc(2 * max_x + 1);
	    for (i=0; i< 2*max_x; i++) {
		    scroll[i] = text1[i % text_length];
	    }
	    scroll[2*max_x - 1]='\0';
	    for (i=0; i < 10; i++) {
	    	     mvaddnstr(14,0,&scroll[i%max_x], max_x);
		     refresh();
		     usleep(200000);
	    }
	    free(scroll);
	    
	    text_length = strlen(text2);
	    scroll = malloc(2 * max_x + 1);
	    for (i=0; i< 2*max_x; i++) {
		    scroll[i] = text2[i % text_length];
	    }
	    scroll[2*max_x - 1]='\0';
	    for (i=0; i < 10; i++) {
	    	     mvaddnstr(40,0,&scroll[i%max_x], max_x);
		     refresh();
		     usleep(200000);
	    }
	    free(scroll);
	    
	    
	   text_length = strlen(text);
	    scroll = malloc(2 * max_x + 1);
	    for (i=0; i< 2*max_x; i++) {
		    scroll[i] = text[i % text_length];
	    }
	    scroll[2*max_x - 1]='\0';
	    for (i=0; i < 15; i++) {
	    	     mvaddnstr(28,0,&scroll[i%max_x], max_x);
		     refresh();
		     usleep(200000);
	    }
	    free(scroll);
	    get_popen("gedit bill.txt");    // TO DISPLAY BILL
	    return;
}
/******************************************************************************************************************/

/****************************** ALERT function     ***************************************************************/
void alert(){
	clear();
	refresh();
	refresh();
	WINDOW *menu_win;
	int c,choice,heighlight;
	choice=0;
	heighlight=1;
	box(stdscr,0,0);
	attron(COLOR_PAIR (2));
	mvprintw(25,25,"%s ARE YOU SHURE TO EXIT ???",name);
	attroff(COLOR_PAIR (2));
	refresh();
	menu_win=newwin(HEIGHT,WIDTH,startx,starty);
	keypad(menu_win,TRUE);
	wbkgd(menu_win, COLOR_PAIR(2));
	wrefresh(menu_win);
	print_menu7(menu_win,heighlight);
		while(1){
		c=wgetch(menu_win);
		switch(c){
			case KEY_UP:
				if (heighlight==1)
					heighlight=n_choices7;
				else
					heighlight=heighlight-1;
				break;
			case KEY_DOWN:
				if (heighlight==n_choices7)
					heighlight=1;
				else
					heighlight=heighlight+1;
				break;
			case 10:
				choice=heighlight;
				break;
			default:
				refresh();
				break;
				
		}
		print_menu7(menu_win,heighlight);
		if(choice !=0)
			break;
	}
	
	if(heighlight==1){
		menu();
		refresh();
		return ;
	}
	if(heighlight==2){
		refresh();
		return ;
	}
	refresh();
	return ;
}



void print_menu7(WINDOW *menu_win,int heighlight){
	int i,x=2,y=2;
	box(menu_win,0,0);
	for(i=0;i<n_choices7;++i){
		if (heighlight==i+1){
			wattron(menu_win,A_REVERSE | A_BOLD);
			mvwprintw(menu_win,y,x," %s ",choices7[i]);
			wattroff(menu_win,A_REVERSE | A_BOLD);
		}
		else	
			mvwprintw(menu_win,y,x," %s ",choices7[i]);
		++y;
	}
	wrefresh(menu_win);
}

/********************************* end of ALERT function   *********************************************************/



void message(int i){
	clear();
	box(stdscr,0,0);
	if(i==0) {
		mvwprintw(stdscr,22,27," CONGRATULATIONS !!! ,");
		mvwprintw(stdscr,23,27," PRODUCT IS ADDED TO CART ");
	}
	else {
		mvwprintw(stdscr,22,27," YOU CANNOT BUY ");
		mvwprintw(stdscr,23,27," MORE THAN 25 ITEMS !!!");
	}
	wgetch(stdscr);
	return;
}

