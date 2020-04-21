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
#include<windows.h>
#include<time.h>
#include "../include/general_design.h"


void cls(){

	system("cls");

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

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, clr);

}

void pwellcome(){
	ccolor(26);

	char welcome[50]=" WELCOME ";
	char welcome2[50]=" TO  ";
	char welcome3[50]=" FOOD ORDERING  ";
	char welcome4[50]=" KIOSK MACHINE  ";
	printf("\n\n\n\n\n\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){
             ccolor(120+(wlc*9));

		printf(" %c",welcome[wlc]);
		Sleep(200);
	}
	ccolor(26);
	printf("\n\n\t\t\t\t ");
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){
            ccolor(160+(wlc2*9));

		printf(" %c",welcome2[wlc2]);
		Sleep(200);
	}
	ccolor(26);
	printf("\n\n\n\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){
		    ccolor(121+(wlc3*4));

			printf(" %c",welcome3[wlc3]);
		}
		else{
		    ccolor(11);

			printf(" %c",welcome3[wlc3]);
		}

		Sleep(200);
	}
	ccolor(26);
	printf("\n\n\n\t\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){
                ccolor(121+(wlc3*4));

			printf(" %c",welcome4[wlc3]);
		}
		else{
		    ccolor(11);

			printf(" %c",welcome4[wlc3]);
		}
		Sleep(200);
	}
	ccolor(26);

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
		Sleep(100);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(100);
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
		Sleep(50);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(50);
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
	br(5); pre(3); echo("===> 1. Food List"); Sleep(400);
	br(2); pre(3); echo("===> 2. Admin Panel"); Sleep(400);
	br(2); pre(3); echo("===> 3. Ingredients_Info");  Sleep(400);
	br(1);

}