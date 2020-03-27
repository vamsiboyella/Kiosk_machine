#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include "general_design.h"


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