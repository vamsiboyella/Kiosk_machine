/**
 * @file main.c
 *
 * @brief Implementation of the main portion of the kioskmachine.
 *
 * @author Vamsi Boyella - 
 * @author Baji Baba Shaik - 
 * @author Matheen Mohammed- 
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

	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	int citem;
	float totalprice=0.0;
	int food_choice[100];
	int food_quantity[100];
 	int items[100];
	int  individual_quantity[100];
	int counter;


	
	head = NULL;
	insertfirst(1,"Hot Cake ",8,720.83);
	insertend(2,"Coffee   ",46,70.23);
	insertend(3,"Ice-Cream",46,70.23);
	insertend(4,"Sandwich ",34,60.23);
	insertend(5,"Burger   ",23,120.00);	
	insertend(6,"Pizza    ",13,100.00);
	insertend(7,"Chicken  ",7,520.29);
	insertend(8,"Nun-Bread",121,35.13);
	insertend(9,"Cold Drinks",73,20.00);
	insertend(10,"Muffin  ",83,50.00);




	mainmenu:
	br(1);
	totalprice=0.0;
	counter=0;
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
		else{
		br(2); pre(4); printf("Please Enter Correct Choice"); Sleep(300);
		goto mainmenu;
		}
	}
	//orderfoood();
	int get_food_choice;


	br(2); pre(3);fflush(stdin); printf("Place Your Order: ") ; scanf("%d",&get_food_choice);

	if(get_food_choice==0){
		goto mainmenu;
	}

	node *temp ;

	temp = list ;

	while(temp->data != get_food_choice){

		temp = temp->next;
		if(temp==NULL){
			br(2); pre(4);  echo("Please make a Choice From List "); br(2); Sleep(1000);
			goto foodlist;
		}

	}

	if(get_food_choice == temp->data){
		
		fcquantity:
		br(2); pre(4); printf("Enter Food Quantity : ");

		int fcquantity;
		
		fflush(stdin); scanf("%d",&fcquantity); cls();

		if(fcquantity==0){
			cls(); middle1();pre(3); printf("Quantity Can not be Zero "); Sleep(2000);
			cls();
			goto mainmenu;
		}
		else if(fcquantity>temp->quantity){
			cls(); middle1();pre(3); printf("Out of Stock ! "); Sleep(2000);
			goto mainmenu;
		}		
		food_choice[counter]=get_food_choice;
		food_quantity[counter]=fcquantity;
		individual_quantity[counter]=temp->quantity;
		totalprice+=temp->price*fcquantity;
		int no_ofchoices=counter;		
		middle1();pre(4);  printf(" Total price is %0.2f \n\n",totalprice);pre(4);
		printf("1. Confirm to buy this \n\n");pre(4);
		
		printf("2. Want to place another order\n\n");pre(4);
		
		printf("3. Cancel Order\n\n");pre(4);

		confirm: ;
		int confirm;

		fflush(stdin); scanf("%d",&confirm);

		if(confirm == 1 ){

			br(2);pre(4);    printf(" 1. Cash ");
			br(2);pre(4);    printf(" 2. Credit ");
			payment: ;
			int payment;
			fflush(stdin);  scanf("%d",&payment);
			//cash transaction
			if(payment==1){
				totalmoney += totalprice;	
				for (int i=0;no_ofchoices>0;i++){
					for (int j=i+1; no_ofchoices>0;j++){
						if (food_choice[i]==food_choice[j]){
						individual_quantity[j]=individual_quantity[i]- food_quantity[i];
						no_ofchoices--;
						break;
						}

					}
					no_ofchoices--;
				}				
				//counter++;				
				for (int i=0;counter>=0;i++){			
				uquantity = individual_quantity[i]- food_quantity[i];
				if(uquantity<0){
					cls(); middle1();pre(3); printf("Out of Stock !");
					middle1();pre(3); printf("Please make another  fresh order"); Sleep(2000);
					goto mainmenu;
				}
				else{
					updatefood(food_choice[i],uquantity);
				}	
				order++;
				total_order[order]=food_choice[i];
				order_quantity[order]=food_quantity[i];	
				counter--;		
				}				
				cls();middle1();pre(4);  printf("===>THANK YOU<===");
				br(2);pre(4);  printf("Food Ordered Successfully ...");
				
				br(2);pre(4);  printf("1. Main Menu ");
				psmenu: ;
				int ps_menu;

				fflush(stdin);  scanf("%d",&ps_menu);

				
				if(ps_menu==1){goto mainmenu;}
				else{br(2);pre(4);printf("Please make a Choice from list : "); goto psmenu;}

			}

			///Credit Card Option

			else if(payment==2){
				for (int i=0;no_ofchoices>0;i++){
					for (int j=i+1; no_ofchoices>0;j++){
						if (food_choice[i]==food_choice[j]){
						individual_quantity[j]=individual_quantity[i]- food_quantity[i];
						no_ofchoices--;
						break;
						}

					}
					no_ofchoices--;
				}				
				
				for (int i=0;counter>=0;i++){
				uquantity = individual_quantity[i]- food_quantity[i];				
				if(uquantity<0){
					cls(); middle1();pre(3); printf("Out of Stock !");
					middle1();pre(3); printf("Please make another order"); Sleep(2000);
					goto mainmenu;
				}
				else{
					updatefood(food_choice[i],uquantity);
				}	
				order++;
				total_order[order]=food_choice[i];
				order_quantity[order]=food_quantity[i];
				counter--;
				}			
				

				int card_number[100];

				c++;

				cls();middle1();pre(4); printf("Enter Your Card No : ");

				fflush(stdin);   scanf("%d",&card_number[c]);
				cardno[c] = card_number[c];
				int pin;
				br(2);pre(2);  printf("Enter Your Card Pin [we never save your pin]  : ");
				fflush(stdin);     scanf("%d",&pin);
				cardmoney[c] = totalprice;
				//totalmoney += totalprice;
					//order++;
				
				br(2);pre(4);  printf("Payment Success...");				
				br(2);pre(4);    printf("1. Main Menu ");
				psmenu2: ;
				int ps_menu2;

				scanf("%d",&ps_menu2);

				//if(ps_menu2==1){goto foodlist;}
				 if(ps_menu2==1){goto mainmenu;}
				else{br(2);pre(4);printf("Please Choice from list : "); goto psmenu2;}

			}

			else{

				br(2);pre(4);   printf("Enter Choice from List : ");

				goto payment;


			}


		}  

		//multiple orders

		else if(confirm == 2){
				counter++;		
			goto foodlist;
		}
		//cancel order
		else if(confirm == 3){			
			goto mainmenu;

		}
		else{
			br(2);pre(4);    printf("Please Select from List : ");

			goto confirm;


		}  ///end confirm;



	}
	else{
		br(2); pre(4); echo("Please Choice From List"); br(2);Sleep(300);
		goto mainmenu;
	}

}
