#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<time.h>
#include <unistd.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void electronics();
void home();
void fashion();
void music();
void recharge();

int welcome(){
	 system("clear");
	 int i;
	 printf("\t\t%sWELCOME TO SHOPPING MALL\n",KGRN);
	 printf("\n%sSHOP BY CATEGORY :\n\n\t\t\v%s1)ELECTRONICS\n\t\t%s2)FASHION",KBLU,KWHT,KCYN);
	 printf("\n\t\t%s3)MUSIC\n\t\t%s4)BAGS\n\t\t%s5)RECHARGE\n",KWHT,KCYN,KWHT);
	 printf("%sYOUR CHOICE>",KRED);
	 scanf("%d",&i);
	 return i;
}


void main(){
	int choice;
	while(1){
	system("clear");
	choice = welcome();
		switch(choice){
			case 1:
				electronics();
				break;
			case 2:
				home();
				break;
			case 3:
				fashion();
				break;
			case 4:
				music();
				break;
			case 5:
				recharge();
				break;
			default:
				continue;
		}
	
	} 
}


