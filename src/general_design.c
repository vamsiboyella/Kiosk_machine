/**
 * @file general_design.c
 *
 * @brief In this file we will be handling all the design functionalities of our system.
 *
 * @author Vamsi Boyella - vboye103@uottawa.ca
 * @author Baji Baba Shaik - bshai015@uottawa.ca
 * @author Matheen Mohammed- MatheenMohammed@cmail.carleton.ca
 * @author Sangamesh Patlolla-SangameshwarPatlolla@cmail.carleton.ca
 */

#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include "../include/general_design.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


void cls(){

	system("clear");

}

void echo(char print[]){

	printf("%s",print);
}

void br(int line){
	for(int i=0; i<line;i++){
		printf("\n");
	}
}

void pre(int tab){

	for(int i=0; i<tab;i++){
		printf("\t");
	}

}
void span(int space){

	for(int i=0; i<space;i++){
		printf(" ");
	}

}
void ccolor(int clr){

	//HANDLE  hConsole;
	//hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, clr);

}

void pwellcome(){
	//ccolor(26);

	char welcome[50]=" WELCOME ";
	char welcome2[50]=" TO  ";
	char welcome3[50]=" FOOD ORDERING  ";
	char welcome4[50]=" KIOSK MACHINE  ";
	printf("\n\n\n\n\n\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){
             //ccolor(120+(wlc*9));

		printf("%s%c",KRED,welcome[wlc]);
		sleep(0.200);
	}
	ccolor(26);
	printf("\n\n\t\t\t\t");
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){
            //ccolor(160+(wlc2*9));

		printf(" %s%c",KGRN,welcome2[wlc2]);
		sleep(0.200);
	}
	ccolor(26);
	printf("\n\n\n\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		//if(welcome3[wlc3]!='D'){
		    //ccolor(121+(wlc3*4));

			printf(" %s%c",KYEL,welcome3[wlc3]);
		//}
		//else{
		    //ccolor(11);

			//printf(" %s%c",welcome3[wlc3]);
		//}

		sleep(0.200);
	}

	//ccolor(26);
	printf("\n\n\n\t\t\t\t ");
	for(int wlc4=0; wlc4<strlen(welcome4) ;wlc4++){
		//if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){
                //ccolor(121+(wlc3*4));

			printf(" %s%c",KBLU,welcome4[wlc4]);
		//}
		//else{
		    //ccolor(11);

			//printf(" %c",welcome4[wlc3]);
		//}
		sleep(0.200);
	}
	printf("\n\n\t\t\t ");
	//ccolor(26);

}
void loadingbar(void){

	for (int i=15;i<=100;i+=5){

		cls();
		ccolor(26);

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Loading...\n\n\t\t",i);

		printf(" ");

		for (int j=0; j<i;j+=2){

			ccolor(160+j);
			printf(" ");
			ccolor(26);

		}
		sleep(0.5);
		if(i==90 || i==50 || i==96 || i==83){
			sleep(1);
		}

	}

}
void backuploader(void){

	for (int i=15;i<=100;i+=5){

		cls();
		ccolor(26);

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Backing UP DATA...\n\n\t\t",i);

		printf(" ");

		for (int j=0; j<i;j+=2){

			ccolor(120+j);
			printf(" ");
			ccolor(26);

		}
		sleep(0.8);
		if(i==90 || i==50 || i==96 || i==83){
			sleep(1);
		}
	}

}



void middle1(void){

	printf("\n\n\n\n\n\n\n");
}
void middtab1(void){
	printf("\t\t\t\t\t");
}
void main_menu(){

	cls();
	br(5); pre(3); echo("===> 1. Food List"); sleep(0.4);
	br(2); pre(3); echo("===> 2. Admin Panel"); sleep(0.4);
	br(2); pre(3); echo("===> 3. Ingredients_Info");  sleep(0.4);
	br(1);

}
