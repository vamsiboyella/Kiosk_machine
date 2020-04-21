/**
 * @file main.c
 *
 * @brief Implementation of the main portion of the kioskmachine.
 * 
 * @author Vamsi Boyella - vboye103@uottawa.ca
 * @author Baji Baba Shaik - bshai015@uottawa.ca
 * @author Matheen Mohammed- MatheenMohammed@cmail.carleton.ca
 * @author Sangamesh Patlolla-SangameshwarPatlolla@cmail.carleton.ca
 */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "../include/general_design.h"
#include "../include/admin.h"
#include "../include/ingredients.h"
#include "../test/include/test.h"
#include "../include/validations.h"

#define MAX_LENGTH 16
void start_automated_testing();


struct Node{

	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;

};
 ///Global Type
 
typedef struct Node node ;

node *head, *list ;

int main(int argc, char *argv[]){
	int opt;
	while ((opt = getopt(argc, argv, "t")) != -1) {
        switch (opt) {
        case 't':
            /* Run automated unit testing */
            printf("Running automated unit testing\n");
            start_automated_testing();
            printf("Automated testing has completed\n");
            return 1;
            break;
		default:
            printf("Executable file of appplication will be placed here ");
            break;
		}
	}

	system("title ..................GroupE_Food Ordering kiosk Machine.......................");
	system("mode con: cols=80 lines=30");


	loadingbar(); cls();
	pwellcome();
	Sleep(300);
	cls();

	int c=0; int any;
	char *cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	//int citem;
	float totalprice=0.0;
	int food_choice[100];
	int food_quantity[100];
 	//int items[100];
	int  individual_quantity[100];
	int counter;

	head = NULL;	

	insertfirst(1,"Hot Cake ",8,10.83);
	insertend(2,"Coffee   ",46,3.23);
	insertend(3,"Ice-Cream",46,6.23);
	insertend(4,"Bagel ",34,12.23);
	insertend(5,"Burger   ",23,11.00);	
	insertend(6,"Pizza    ",13,16.00);
	insertend(7,"Chicken Muffin",7,17.29);
	insertend(8,"Angus",121,6.13);
	insertend(9,"Cold Drinks",73,8.00);
	insertend(10,"Biryani  ",83,13.00);


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

				// node *temp;

				// temp = list;

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
				printf(" 9. Upgrade the ingredients information\n\n");Sleep(250);pre(4);
				printf(" 0. Main Menu ");Sleep(250);

				int adminchoise;



				fflush(stdin);   scanf("%d",&adminchoise);


				if(adminchoise==1){

					cls();  middle1(); pre(4);   printf("Todays Total Cash : %0.2f  \n",totalmoney);

					Sleep(2000);

					Sleep(2000);
					goto adminchoice;
				}

				else if(adminchoise==2){


					if(c!=0){


						cls();  br(3); pre(4);

						printf(" ____________________________\n");pre(4);
						printf("|   Card NO.   |   Money $   |\n");pre(4);
						printf("------------------------------\n");pre(4);

						for(int z=1; z<=c;z++){


							printf("|  %s  | %0.2f |\n",cardno[z],cardmoney[z]);pre(4);

							printf("------------------------------\n");pre(4);
							Sleep(150);

						}
						Sleep(1500);
					}

					if(c==0){

						cls();  middle1(); pre(4);
					printf("No Card History\n");}
					Sleep(1500);
					goto adminchoice;
				}

				else if(adminchoise==3){



					//foodadd:
					cls();

					char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;

          
					int fqresult;


					br(3);pre(4);      printf(" Enter Food Name :  ");

					fflush(stdin);     scanf("%[^\n]s",ffoodname);      
					
					fquantity:
					fflush(stdin);
					br(2);pre(4);  printf(" Enter Food Quantity :  ");

					fqresult=scanf("%d",&fquantity);
					if(!fqresult){
					br(2);pre(4);
					printf("Enter valid value");
					goto fquantity;
					}

					 

                    foodserial:
					fflush(stdin);
					br(2);pre(4);  printf(" Enter Food Item Id :  ");
                    fqresult = scanf("%d",&fdata);
					if(!fqresult){
					br(2);pre(4);
					printf("Enter valid value");
					goto foodserial;
					}



                            node *exist;
                            exist = list;
                      while(exist->data!=fdata){
                            if(exist->next==NULL){
                                break;
                            }
                        exist=exist->next;
                      }
                      if(exist->data==fdata){

                       cls(); br(5);pre(3);  printf(" Food Item Id Already Exist, Please Re-Enter  "); Sleep(2000);

                       goto foodserial;
                      }

                    fprice:

                    fflush(stdin);

					br(2);pre(4);  printf(" Enter Food Price :  ");fflush(stdin);

					fqresult=scanf("%f",&fprice);
					if(!fqresult){
					br(2);pre(4);
					printf("Enter valid value");
					goto fprice;
					}


					br(2);pre(4);  printf("Submiting your data");for(int cs=0;cs<4;cs++){printf(" .");Sleep(500);}


					insertend(fdata,ffoodname,fquantity,fprice);

					br(2);pre(4);      printf("Adding Food  Successfull....\n");

					Sleep(2000);



					goto adminchoice;

				}

				else if(adminchoise==4){


					cls();
					middle1();pre(2);
					printf("Enter Item Id of the Food To Delete : ");
					fdelete: ;
					int fdelete;
					fflush(stdin);scanf("%d",&fdelete);
					

					node *temp;
					temp=list;
					while(temp->data != fdelete){
						temp = temp->next;
					}
					if(temp->data==fdelete){
						deletefood(fdelete);
					}
					else{
						br(2); pre(2); printf("Please Enter Correct Number :  "); Sleep(500);
						goto fdelete;
					}



					goto adminchoice;
				}

				else if(adminchoise==5){
					cls();    foodlist(); Sleep(1000);		

					br(2);pre(4);  printf("1. <-- back  \n\n");pre(5);

					fflush(stdin);   scanf("%d",&any);

					cls();    foodlist(); Sleep(1000);

					br(2);pre(4);  printf("1. <-- back  \n\n");pre(5);

					fflush(stdin);   scanf("%d",&any);

					goto adminchoice;
					

				}

				else if(adminchoise==6){

					cls();
					char ffoodname[25];
					int fquantity;
					int data;
					float fprice;					

					foodchoice_id: ;

					br(2);pre(2);printf(" Please enter the food Item Id you want to update :  ");

					fflush(stdin);scanf("%d",&data);				
					
                    node *exist;
                    exist = list;
                    while(exist->data !=data){
                            if(exist->next==NULL){
								cls(); br(5);pre(3);  printf(" Food Id doesn't exist, Please Re-Enter  "); Sleep(2000);
                       			goto foodchoice_id;                             
                            }
                        exist=exist->next;
                      } 
									 

					br(2);pre(4);  printf("  Enter the Food Name  :  ");
					fflush(stdin);	scanf("%[^\n]s",ffoodname);	

                    stock: ;
					br(2);pre(4);  printf(" Enter the qunatity of stock :  ");
					fflush(stdin); 
					int fqresult=scanf("%d",&fquantity);
					if(!fqresult){
					br(2);pre(4);
					printf("Enter valid value");
					goto stock;
					}			
                   
                    fflush(stdin);
					fp:
					br(2);pre(4);  printf(" Enter Food Price :  ");fflush(stdin);

					fqresult=scanf("%f",&fprice);
					if(!fqresult){
					br(2);pre(4);
					printf("Enter valid value");
					goto fp;
					}

					br(2);pre(4);  printf("Updating Food item");for(int cs=0;cs<4;cs++){printf(" .");Sleep(500);}
					updateitem(data,ffoodname,fquantity,fprice);

					br(2);pre(4);      printf("Updating Food  Successfull....\n");

					Sleep(2000);

					goto adminchoice;
					
				}    
				  ///Backup System				
				
				else if(adminchoise==7){
					char date[35]=__DATE__;

					strcat(date,".txt");
					FILE *fptr;
					fptr=fopen(date,"w");
					backuploader();
					if(fptr==NULL){
						br(3); pre(3); printf("Error!"); Sleep(500);
						goto adminchoice;
					}
					fprintf(fptr,"Total Cash Today : %0.2f\n\n\n",totalmoney);
					fprintf(fptr,"Card No ------- Money \n\n");
					for(int l=1; l<=c;l++){
						fprintf(fptr,"%s ------- %0.2f \n",cardno[l],cardmoney[l]);
					}
					br(2);pre(4); printf("Backup Successfull..."); Sleep(1500);
					fclose(fptr);


	
					goto adminchoice;
				}

				else if(adminchoise==8){

					int i=view_orders( order, total_order,order_quantity);
					if(i){

					goto adminchoice;
					}	
					else{
					goto adminchoice;	
					}

				}

				else if(adminchoise==9){
					cls();
					int i= scan_new_ingredients();
					if(i){						
						br(2);pre(4); printf("Update of food infromation successfull..."); Sleep(1500);
						goto adminchoice;
					}
					else{
						goto adminchoice;
					}

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
			cls();
			int i=read_Ingredients();
			if(i){
			Sleep(4000);
			goto mainmenu;
			}
			else{
			Sleep(4000);
			goto mainmenu;
			}

		}

	}
	else{
		br(2); pre(4); printf("Please Enter Correct Choice"); Sleep(300);
		goto mainmenu;
	}
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
		
		//fcquantity:
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
				

				//int card_number[100];

				c++;
				cardv:;
				char *input = malloc((MAX_LENGTH + 1) * sizeof(*input));
				assert(input != NULL);
				do {
					cls();
					br(2);pre(4);
					printf("Enter credit card number: ");
					getInput(input);
					} while (isNumeric(input) == false);
				
				if (luhn(input) == false)
				{	cls();
					middle1();pre(4);
					printf("invalid!! try a valid card!!");
					//Sleep(2000);
					free(input);
					goto cardv;
				}
				else {
					//cls();
					middle1();pre(4);					
					cardno[c]= input;
					printf("valid card");
					checkPrefix(input); 				
					
				}			
				

				int pin;
				pin_valid:;				
				br(2);pre(2);  printf("Enter Your Card Pin [we never save your pin]  : ");
				fflush(stdin);
				int fqresult= scanf("%d",&pin);
				if(!fqresult){
					br(2);pre(4);
					printf("Enter valid value");
					goto pin_valid;
				}
				if(!(pin<=999999 && pin >= 1000)){
					printf("Enter valid value which is either 4 digit or 6 digit");
					goto pin_valid;
				}
				cardmoney[c] = totalprice;			
				
				br(2);pre(4);  printf("Payment Success...");				
				br(2);pre(4);    printf("1. Main Menu ");
				psmenu2: ;
				int ps_menu2;

				scanf("%d",&ps_menu2);
				
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




