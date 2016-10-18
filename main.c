#include<stdio.h>
#include<string.h>
#include<ncurses.h>
#include "files.h"
#define WIDTH 30
#define HEIGHT 10

int startx=0;
int starty=0;
char ch,password[16],name[16];
char *choices[]={
	"Electronics",
	"Fashion(in progress)",
	"Music(in progress)",
	"Recharge(in progress)",
	"GO TO CART(in progress)",
	"EXIT",
	};
	
char *choices1[]={
	"APPLE MOBILE : iPHONE 7",
	"REDMI MOBILE : REDMI NOTE 3",
	"SAMSUNG MOBILE : SAMSUNG ON 7 PRO",
	"DELL LAPTOP : DELL 5559",
	"HP LAPTOP : HP PAVILLION S003TU",
	"SONY TV : BRAVIA KVL 32 W562D",
	"GO TO CART(in progress)",
	"BACK",
	"EXIT",
	};
char *choices2[]={
	"VIEW IMAGE",
	"ADD TO CART(in progress)",
	"GO TO CART(in progress)",
	"BACK",
	"EXIT",
	};
	
int n_choices=sizeof(choices)/sizeof(char*);
int n_choices1=sizeof(choices1)/sizeof(char*);
int n_choices2=sizeof(choices2)/sizeof(char*);
void menu();
void electronics();
void interior(WINDOW *menu_win,char *);
void print_menu(WINDOW *menu_win,int heighlight);
void print_menu1(WINDOW *menu_win,int heighlight);
void print_menu2(WINDOW *menu_win,int heighlight);
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
int main(){
	WINDOW *menu_win;
	initscr();
	clear();
	cbreak();
	start_color();
	
	startx = (50-WIDTH)/2;
	starty = (24-HEIGHT)/2;
	/***********************************************************************************************/
	menu_win=newwin(HEIGHT,WIDTH,startx,starty);
	keypad(menu_win,TRUE);
    	init_pair(1,COLOR_CYAN,COLOR_BLACK);
    	wbkgd(stdscr, COLOR_PAIR(1));
    	box(stdscr,0,0);
    	mvprintw(20,20,"enter your name>");
    	scanw("%s",name);
    	noecho();
    	mvprintw(22,20,"your  password>");
   	scanw("%s",password);
   	clrtoeol();
   	clear();
   	delwin(menu_win);
   	/***********************************************************************************************/
	menu();
	refresh();
	endwin();
	return 0;
}
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
void menu(){
	WINDOW *menu_win;
	
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
				//mvprintw(24,0,"character pressed is %3d printed well???\n",c);
				refresh();
				break;
				
		}
		print_menu(menu_win,heighlight);
		if(choice !=0)
			break;
	}
	clrtoeol();
   	clear();
   	delwin(menu_win);
   	if(heighlight==1){
		electronics();
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
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
void electronics(){
	WINDOW *menu_win,*menu_win2;
	int heighlight=1;
	int c,choice=0;
	clear();
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
				//mvprintw(24,0,"character pressed is %3d printed well???\n",c);
				refresh();
				break;
				
		}
		print_menu1(menu_win,heighlight);
		if(choice !=0)
			break;
	}
	clrtoeol();
   	clear();
   	delwin(menu_win);
   	/***********************************************************************************************/
   	menu_win2=newwin(HEIGHT,WIDTH,startx+10,starty+10);
	wbkgd(menu_win2, COLOR_PAIR(3));
	wrefresh(menu_win2);
	box(stdscr,0,0);
	
	keypad(menu_win2,TRUE);
	mvprintw(34,45,"PRESS KEY f TO VIEW FEATURE");
	mvprintw(35,45,"use arrow keys to go up,down,enter to select choice");
	refresh();
   	char arr[32];
   	if(heighlight==1){
		strcpy(arr,"iphone7.txt");
		print_file(arr);
		strcpy(arr,"eog iphone7.png");
		interior(menu_win2,arr);
		refresh();
		return ;
	}
	if(heighlight==2){
		strcpy(arr,"note3.txt");
		print_file(arr);
		strcpy(arr,"eog note3.png");
		interior(menu_win2,arr);
		refresh();
		return ;
	}
	if(heighlight==3){
		strcpy(arr,"samsungon7.txt");
		print_file(arr);
		strcpy(arr,"eog samsungon7.png");
		interior(menu_win2,arr);
		refresh();
		return ;
	}
	if(heighlight==4){
		strcpy(arr,"dell5559.txt");
		print_file(arr);
		strcpy(arr,"eog dell5559.png");
		interior(menu_win2,arr);
		refresh();
		return ;
	}
	if(heighlight==5){
		strcpy(arr,"hp.txt");
		print_file(arr);
		strcpy(arr,"eog hp.png");
		interior(menu_win2,arr);
		refresh();
		return ;
	}
	if(heighlight==6){
		strcpy(arr,"sony.txt");
		print_file(arr);
		strcpy(arr,"eog sony.png");
		interior(menu_win2,arr);
		refresh();
		return ;
		}
   	if(heighlight==8){
		menu();
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

void interior(WINDOW *menu_win,char *arr){
		int heighlight=1;
		int c,choice=0;
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
				//mvprintw(24,0,"character pressed is %3d printed well???\n",c);
				refresh();
				break;
				
		}
		print_menu2(menu_win,heighlight);
		if(choice !=0)
			break;
	}
	if(heighlight == 1){
			get_popen(arr);
			interior(menu_win,arr);
			return;
	}
	if(heighlight == 4){
		electronics();
		return;
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
