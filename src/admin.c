/**
 * @file admin.c
 *
 * @brief In this file we will be handling all the admin functionalities of our system.
 *
 * @author Vamsi Boyella - vboye103@uottawa.ca
 * @author Baji Baba Shaik - bshai015@uottawa.ca
 * @author Matheen Mohammed- MatheenMohammed@cmail.carleton.ca
 * @author Sangamesh Patlolla-SangameshwarPatlolla@cmail.carleton.ca
 */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include "general_design.h"
#include "admin.h"

struct Node{

	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;

};
typedef struct Node node ;

node *head, *list;

void insertfirst(int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data ;

	temp->price = price;

	strcpy(temp->foodname,foodname);

	temp-> quantity = quantity;


	temp->next = head;

	head = temp;

	list = head ;

}
void updateitem(int data, char foodname[25], int quantity, float price){

	node *temp;
	temp = list;

	
	while(temp->data!=data){
		temp = temp->next;

	}
	if(temp->data == data){
		temp->quantity = quantity;
		temp->price=price;
		strcpy(temp->foodname,foodname);
	}
}

void deletefood(int serial){

	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp = list;


	if(temp->data != serial){

		while(temp->next->data != serial){
			temp = temp->next;
		}

		if(temp->next->data == serial){

			temp->next = temp->next->next;
			cls();
			printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}

			printf("\n\n\n\n\t\t\tDeleted Successfylly \n"); Sleep(500);

		}
		else{
			printf("\n\n\n\n\t\t\tFood Item Not Found\n"); Sleep(500);
		}

		head = temp ;

	}
	else{

		temp = temp->next;
		cls();
		printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}

		printf("\n\n\n\n\t\t\tDeleted Successfylly \n"); Sleep(500);

		head = temp ;

		list=head;
	}
}

void insertend(int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->foodname,foodname);

	temp->next = NULL;


	if(head==NULL){
		head = temp;
		list = head;
	}
	else{

		while(head->next != NULL){
			head = head->next;
		}

		head->next = temp;
	}

}
void updatefood(int udata, int uquantity){

	node *temp;
	temp = list;

	while(temp->data!=udata){
		temp = temp->next;

	}
	if(temp->data == udata){
		temp->quantity = uquantity;
	}

}

void foodlist(){

	ccolor(26);

	printf("\n\t\t"); ccolor(240);
	printf("______________________________________________________ ");ccolor(26);
	printf("\n\t\t"); ccolor(240);
	printf("|  Food No.  |   FooD Name   |  Price  |   In Stock   |");ccolor(26);
	printf("\n\t\t"); ccolor(240);
	printf("-------------------------------------------------------");ccolor(26);

	node *temp;

	temp = list;

	while(temp != NULL){

		ccolor(26);


		printf("\n\t\t"); ccolor(62);
		printf("|     %d      |    %s  |    %0.2f   |    %d    |",temp->data,temp->foodname, temp->price, temp->quantity);
		ccolor(26);
		printf("\n\t\t"); ccolor(62);
		printf("-------------------------------------------------------");


		temp = temp->next ;

		Sleep(100);

	}

	ccolor(26);

	//  free(temp);

}
