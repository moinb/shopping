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

void bottom(){
	printf("\n\n--------------------VIEW IMAGE>11--------------------\n");
	printf("--------------------ADD TO CART>22--------------------\n");
	printf("--------------------GO TO CART >33-------------\n");
	printf("--------------------BACK>44--------------------\n");
	printf("--------------------HOME>55------------------\n");
	
	
}

void sony(){
	system("clear");
	int i;
	printf("\t\t%sWELCOME TO SONY :",KBLU);
	printf("\n%s1)SONY BRAVIA KVL32W562D\n\n%s2)SONY BRAVIA KVL24P423D\n\n%s3)SONY BRAVIA KVL40W562D",KGRN,KBLU,KWHT);
	printf("\n\n\n--------------------BACK>44--------------------\n");
	printf("--------------------HOME>55------------------\n");
	printf("%sYOUR CHOICE>",KRED);
        scanf("%d",&i);
        if(i==1){
		discription_sony_KVL32W562D();
		bottom();
		return;
	}
	else if(i==2){
		discription_sony_KVL24P423D();
		bottom();
		return;
	}
	else if(i==3){
		discription_sony_KVL40W562D();
		bottom();
		return;
	}
	else if(i==44){
		electronics();
		return;
	}
	else if(i==55){
		main();
		return;
	}
	else{
		sony();
		return;	
	}
}

void hp(){
	system("clear");
	int i;
	printf("\t\t%sWELCOME TO HP :",KBLU);
	printf("\n%s1)HP 14-AM081TU\n\n%s2)HP 15-AU003TX\n\n%s3)HP PAVILLION S003TU",KGRN,KBLU,KWHT);
	printf("\n\n\n--------------------BACK>44--------------------\n");
	printf("--------------------HOME>55------------------\n");
	printf("%sYOUR CHOICE>",KRED);
        scanf("%d",&i);
        if(i==1){
		discription_hp_am081tu();
		bottom();
		return;
	}
	else if(i==2){
		discription_hp_au003tx();
		bottom();
		return;
	}
	else if(i==3){
		discription_hp_s003tu();
		bottom();
		return;
	}
	else if(i==44){
		electronics();
		return;
	}
	else if(i==55){
		main();
		return;
	}
	else{
		hp();
		return;	
	}
}


void dell(){
	system("clear");
	int i;
	printf("\t\t%sWELCOME TO DELL :",KBLU);
	printf("\n%s1)DELL 3558\n\n%s2)DELL INSPRION 5559\n\n%s3)DELL 3543",KGRN,KBLU,KWHT);
	printf("\n\n\n--------------------BACK>44--------------------\n");
	printf("--------------------HOME>55------------------\n");
	printf("%sYOUR CHOICE>",KRED);
        scanf("%d",&i);
        if(i==1){
		discription_3558();
		bottom();
		return;
	}
	else if(i==2){
		discription_5559();
		bottom();
		return;
	}
	else if(i==3){
		discription_3543();
		bottom();
		return;
	}
	else if(i==44){
		electronics();
		return;
	}
	else if(i==55){
		main();
		return;
	}
	else{
		dell();
		return;	
	}
}

void samsung(){
	system("clear");
	int i;
	printf("\t\t%sWELCOME TO SAMSUNG :",KBLU);
	printf("\n%s1)SAMSUNG ON7 PRO\n\n%s2)SAMSUNG Z1 SMZ130H\n\n%s3)SAMSUNG ON 5 PRO",KGRN,KBLU,KWHT);
	printf("\n\n\n--------------------BACK>44--------------------\n");
	printf("--------------------HOME>55------------------\n");
	printf("%sYOUR CHOICE>",KRED);
        scanf("%d",&i);
        if(i==1){
		discription_on7_pro();
		bottom();
		return;
	}
	else if(i==2){
		discription_z1_smz130h();
		bottom();
		return;
	}
	else if(i==3){
		discription_on5_pro();
		bottom();
		return;
	}
	else if(i==44){
		electronics();
		return;
	}
	else if(i==55){
		main();
		return;
	}
	else{
		samsung();
		return;	
	}
}

void apple(){
	system("clear");
	int i;
	printf("\t\t%sWELCOME TO APPLE :",KBLU);
	printf("\n%s1) APPLE iPHONE 7\n\n%s2)APPLE iPHONE 6s\n\n%s3)APPLE iPHONE 6 plus",KGRN,KBLU,KWHT);
	printf("\n\n\n--------------------BACK>44--------------------\n");
	printf("--------------------HOME>55------------------\n");
	printf("%sYOUR CHOICE>",KRED);
        scanf("%d",&i);
        if(i==1){
		discription_iphone_7();
		bottom();
		return;
	}
	else if(i==2){
		discription_iphone_6s();
		bottom();
		return;
	}
	else if(i==3){
		discription_iphone_6_plus();
		bottom();
		return;
	}
	else if(i==44){
		electronics();
		return;
	}
	else if(i==55){
		main();
		return;
	}
	else{
		apple();
		return;	
	}
}


void electronics(){
	 system("clear");
	 int i;
	 printf("\t\tWELCOME TO ELECTRONICS\n%sSHOP BY CATEGORY :",KBLU);
	 printf("\n\n\t\t\v%s* MOBILES *",KWHT);
	 printf("\n%s1)APPLE\n%s2)SAMSUNG",KCYN,KGRN);
	 printf("\n\n\t\t\v%s* LAPTOPS *",KWHT);
	 printf("\n%s3)DELL\n%s4)HP",KCYN,KGRN);
	 printf("\n\n\t\t\v%s* TELEVISION *",KWHT);
	 printf("\n%s5)SONY\n",KCYN);
	 printf("\n\n\n--------------------HOME>55------------------\n");
	 printf("%sYOUR CHOICE>",KRED);
	 scanf("%d",&i);
	 switch(choice){
			case 1:
				apple();
				return;
			case 2:
				samsung();
				return;
			case 3:
				dell();
				return;
			case 4:
				hp();
				return;
			case 5:
				sony();
				return;
			case 55:
				main();
				return;
			default:
				electronics();
		} 
return;
}


