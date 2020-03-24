/**
 * @file main.c
 *
 * @brief Implementation of the main portion of the kioskmachine.
 *
 * @author Vamsi Boyella - 
 * @author Baji Baba Shaik - 
 * @author Matheen Mohammad- 
 * @author Sangamesh Patlolla-
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
 ///Global Type

typedef struct Node node ;

node *head, *list;

int main(){

	system("title ..................GroupE_Food Ordering kiosk Machine.......................");
	system("mode con: cols=80 lines=30");


	loadingbar(); cls();
	pwellcome();
	Sleep(300);
	cls();

	
	head = NULL;
	insertfirst(5,"Burger   ",23,5.23);
	insertend(6,"Pizza    ",13,10.67);
	insertend(1,"Hot Cake ",8,7.83);
	insertend(2,"Coffee   ",96,6.23);
	insertend(3,"Ice-Cream",56,4.12);
	insertend(4,"Sandwich ",34,11.23);
	insertend(7,"Grill Chicken",7,15.00);
	insertend(8,"Nun-Bread",120,3.00);
	insertend(9,"Cold Drinks",75,4.50);
	insertend(10,"Muffin ",85,5.53);




	mainmenu:
	br(1);

	main_menu();

	int main_menu_choice;

	br(1); pre(4); fflush(stdin); scanf("%d",&main_menu_choice);

	if((main_menu_choice >=1 && main_menu_choice <=3)){

		if(main_menu_choice == 1){

			foodlist:

			cls();
			printf("=> 0. Main Menu ");
			foodlist();


		}

		else if( main_menu_choice == 2){

			adminpanelchoice: ;

			int admin_panel_choice;

			cls(); middle1() ;   pre(4);  printf("1. Main Menu\n\n\t"); Sleep(300);
			printf("Please Enter Password or ( 1 to Back in Main Menu ) : ");


			fflush(stdin);  scanf("%d",&admin_panel_choice);

			if(admin_panel_choice==12345678){

				node *temp;

				temp = list;

				adminchoice:

				cls();  br(5); pre(4); echo("You are on Admin Pannel\n\n");
				pre(4);
				printf(" 1. Total Cash Today \n\n");Sleep(250);pre(4);
				printf(" 2. View Card Pay \n\n");Sleep(250);pre(4);
				printf(" 3. Add Food \n\n");Sleep(250);pre(4);
				printf(" 4. Delete Food \n\n");Sleep(250);pre(4);
				printf(" 5. Instant Food List \n\n");Sleep(250);pre(4);
				printf(" 6. Update Food \n\n");Sleep(250);pre(4);
				printf(" 7. Backup System\n\n");Sleep(250);pre(4);
				printf(" 8. Instant Order Preview\n\n");Sleep(250);pre(4);
				printf(" 0. Main Menu ");Sleep(250);

				int adminchoise;



				fflush(stdin);   scanf("%d",&adminchoise);

				if(adminchoise==1){					

					goto adminchoice;
				}
				else if(adminchoise==2){
					goto adminchoice;
				}

				else if(adminchoise==3){
					goto adminchoice;

				}
				else if(adminchoise==4){
					goto adminchoice;
				}

				else if(adminchoise==5){

					goto adminchoice;

				}

				 else if(adminchoise==6){
					goto adminchoice;

				 }
                     
				else if(adminchoise==7){

					goto adminchoice;
				}
				else if(adminchoise==8){
					goto adminchoice;
				}
				else if(adminchoise==0){
					goto mainmenu;
				}

				else{
					br(2); pre(4); printf("Please Select From List :  "); Sleep(500);
					goto adminchoice;
				}



			}

			else if(admin_panel_choice==1){
				goto mainmenu;
			}
			else{
				br(2); pre(4);  printf("Please Enter Correct Choice");
				goto adminpanelchoice;
			}

		}

		else if(main_menu_choice==3){
			
            goto mainmenu;

		}

	}
	else{
		br(2); pre(4); printf("Please Enter Correct Choice"); Sleep(300);
		goto mainmenu;
	}
    goto mainmenu;
}
