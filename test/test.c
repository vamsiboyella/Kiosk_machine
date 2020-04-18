/**
 * @file test.c
 *
 * @brief Collections of declaration function of automated unit tests..
 *
 * @author Vamsi Boyella - vboye103@uottawa.ca
 * @author Baji Baba Shaik - bshai015@uottawa.ca
 * @author Matheen Mohammed- MatheenMohammed@cmail.carleton.ca
 * @author Sangamesh Patlolla-SangameshwarPatlolla@cmail.carleton.ca
 */
#include <assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include <errno.h>
#include <stdbool.h>
#include "../include/general_design.h"
#include "../include/admin.h"
#include "../include/ingredients.h"
#include "../test/include/test.h"
#include "../include/validations.h"
// #include "general_design.h"
// #include "admin.h"
// #include "ingredients.h"
// #include "test.h"
// #include "validations.h"

/* minimum and maximum credit card number lengths */
#define MIN_LENGTH 13
#define MAX_LENGTH 16
#define ENTER 13
#define TAB 9
#define BKSP 8

/**
 * Macro to print out 'passed'/'failed' based on the boolean value of what was
 * provided to it.
 */
#define ASSERT_TEST(x)                        \
    {                                         \
        if (x)                                \
        {                                     \
            printf("PASSED\n");               \
        }                                     \
        else                                  \
        {                                     \
            printf("%s: FAILED\n", __func__); \
        }                                     \
    }
struct Node{

	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;

};
typedef struct Node node ;

node *head, *list;

void automated_general_design_functions(){
    cls();
    middle1(); pre(4);echo("Testing echo function");
    // echo(" test 2 new lines");
    // br(2);
    // echo("3 tab spaces");
    // pre(3);
    middle1(); pre(4);echo("Testing welcome bar");
    pwellcome();
    middle1(); pre(4);echo("Testing loading bar");
    loadingbar();
    middle1(); pre(4);echo("Testing another loading bar");
    backuploader();
    // echo("7 new lines");
    // middle1();
    // echo("5 tab spaces");
    // middtab1();
    middle1(); pre(4);echo("Testing display main menu");
    main_menu();    
    cls();    

}
void automated_testing_linked_list(){
    
	char ffoodname[25];
	int fquantity;
	int fdata;
	float fprice;
	int fqresult;


    head = NULL;
    middle1(); pre(4);printf("-------------------\n");
    middle1(); pre(4);printf("LINKED LIST TESTING\n");
    middle1(); pre(4);printf("-------------------\n");
    //Testing insert first function
    br(2); pre(4);printf("Addding items to the menu,and testing insert functions");
    br(3);pre(4);      printf(" Enter Food Name :  ");
    fflush(stdin);     scanf("%[^\n]s",ffoodname);

    fquantity: ;
	fflush(stdin);
	br(2);pre(4);  printf(" Enter Food Quantity :  ");

	fqresult=scanf("%d",&fquantity);
	if(!fqresult){
	br(2);pre(4);
	printf("Enter valid value");
	goto fquantity;
	}
    fprice: ;
    fflush(stdin);

	br(2);pre(4);  printf(" Enter Food Price :  ");fflush(stdin);

	fqresult=scanf("%f",&fprice);
	if(!fqresult){
	br(2);pre(4);
	printf("Enter valid value");
	goto fprice;
	}

	foodserial: ;
	fflush(stdin);
	br(2);pre(4);  printf(" Enter Food Item Id :  ");
    fqresult = scanf("%d",&fdata);
	if(!fqresult){
	br(2);pre(4);
	printf("Enter valid value");
	goto foodserial;
	}
    insertfirst(fdata,ffoodname,fquantity,fprice);
    foodlist();

    moreitems: ;
     //Testing insertend function
    // Sleep(1000);
    // cls();
    br(2); pre(4);printf("Addding more items to the menu,and testing insert functions");
    br(3);pre(4);      printf(" Enter Food Name :  ");
    fflush(stdin);     scanf("%[^\n]s",ffoodname);

    vquantity:
	fflush(stdin);
	br(2);pre(4);  printf(" Enter Food Quantity :  ");

	fqresult=scanf("%d",&fquantity);
	if(!fqresult){
	br(2);pre(4);
	printf("Enter valid value");
	goto vquantity;
	}
    vprice:
    fflush(stdin);

	br(2);pre(4);  printf(" Enter Food Price :  ");fflush(stdin);

	fqresult=scanf("%f",&fprice);
	if(!fqresult){
	br(2);pre(4);
	printf("Enter valid value");
	goto vprice;
	}

	validid:
	fflush(stdin);
	br(2);pre(4);  printf(" Enter Food Item Id :  ");
    //fqresult = 
	scanf("%d",&fdata);
	// if(!fqresult){
	// br(2);pre(4);
	// printf("Enter valid value");
	// goto validid;
	// }
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
    goto validid;
    }
    insertend(fdata,ffoodname,fquantity,fprice);
    foodlist();

    ///Asking user to enter more values
    br(3);pre(4); printf(" Do you want to add more values to the menu list :");
   
    check: ;
    char ch;
    br(2);pre(4); printf(" Please enter 'Y' for YES and 'N' for NO  :");
     fflush(stdin);   scanf("%c",&ch);
     if(ch=='Y'||ch=='y'){
        goto moreitems;
     }
     else if (ch=='N'||ch=='n'){
        goto update;
     }
     else{
        goto check;
     }

    update: ;
    
    //Testing update item function
    // Sleep(3000);
    // cls();
    //middle1(); pre(4);printf("Now testing update function of linked list");
    
    foodchoice_id:

	br(3);pre(3);      printf(" Please enter the food Item Id you want to update :  ");

	fflush(stdin);
	//fqresult=
	scanf("%d",&fdata);
	// if(!fqresult){
	// br(2);pre(4);
	// printf("Enter valid value");
	// goto foodchoice_id;
	// } 

	// node *exist;
    // exist = list;
    while(exist->data!=fdata){
    if(exist->next==NULL){
		cls(); br(5);pre(3);  printf(" Food Id doesn't exist, Please Re-Enter  "); Sleep(2000);
        goto foodchoice_id;
    
     }
        exist=exist->next;
     } 			

    br(3);pre(4);      printf(" Enter Food Name:  ");
    fflush(stdin);     scanf("%[^\n]s",ffoodname);

    stock: ;
	br(2);pre(4);  printf(" Enter the qunatity of stock :  ");
	fflush(stdin); 
	fqresult=scanf("%d",&fquantity);
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
    updateitem(fdata,ffoodname,fquantity,fprice);
    foodlist();

    //Testing delete food function
    middle1();pre(2);
	printf("Enter Serial No of the Food To Delete : ");
	fdelete: ;
	int fdelete;
	fflush(stdin);
	fqresult=scanf("%d",&fdelete);
	if(!fqresult){
	br(2);pre(4);
	printf("Enter valid value");
	goto fdelete;
	}
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
    foodlist();

}
void automated_order_pay_cancel_food(){
    Sleep(1000);
    cls();
    br(2); pre(3);printf(" Added burger and pizzza to the menu, to facilitate testing") ;
    insertend(5,"Burger   ",23,120.00);	
	insertend(6,"Pizza    ",13,100.00);
    mainmenu: ;
    int c=0; int any;
	char *cardno[100];
	float cardmoney[100];
	float totalmoney = 0.0;
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
	int counter=0;
    
    foodlist:;

    foodlist();
    int get_food_choice;
	br(2); pre(3);fflush(stdin); printf("Place Your Order: ") ; scanf("%d",&get_food_choice);
    node *temp ;
	temp = list ;
    while(temp->data != get_food_choice){
		temp = temp->next;
		if(temp==NULL){
			br(2); pre(4);  echo("Please make a Choice From List "); br(2); Sleep(1000);
			goto mainmenu;
		}

	}
    if(get_food_choice == temp->data){		
	
		br(2); pre(4); printf("Enter Food Quantity : ");

		int fcquantity;
		
		fflush(stdin); scanf("%d",&fcquantity); cls();

		if(fcquantity==0){
			cls(); middle1();pre(3); printf("Quantity Can not be Zero "); Sleep(2000);
			cls();
            br(2); pre(4); printf("Please make the order once again: ");
			goto mainmenu;
		}
		else if(fcquantity>temp->quantity){
			cls(); middle1();pre(3); printf("Out of Stock ! "); Sleep(2000);
            br(2); pre(4); printf("Please make the order once again: ");
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

                /// Please check the order u have placed
               

                int i=view_orders( order, total_order,order_quantity);
				br(2);pre(4);  printf("This  is the order you have placed ...");
                 br(2);pre(4);  ASSERT_TEST(i);

                //////////
                check: ;
                char ch;
                br(2);pre(4); printf(" Do u want to test one more time? 'Y' for YES and 'N' for NO  :");
                fflush(stdin);   scanf("%c",&ch);
                if(ch=='Y'||ch=='y'){
                    goto mainmenu;
                }
                else if (ch=='N'||ch=='n'){
                    goto complete;
                }
                else{
                    goto check;
                }  			

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
					cls();
					middle1();pre(4);					
					cardno[c]= input;
					printf("valid ");
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
				if(pin>=1000000 && pin < 1000){
					printf("Enter valid value which is either 4 digit or 6 digit");
					goto pin_valid;
				}
				cardmoney[c] = totalprice;
				//totalmoney += totalprice;
					//order++;
				
				br(2);pre(4);  printf("Payment Success...");	

                  /// Please check the order u have placed
                //br(2);pre(4);  printf("check the order u have placed ...");

                int i=view_orders( order, total_order,order_quantity);	
				br(2);pre(4);  printf("This  is the order you have placed ...");

                br(2);pre(4); ASSERT_TEST(i); 

                check2: ;
                char ch;
                br(2);pre(4); printf(" Do u want to test one more time? 'Y' for YES and 'N' for NO  :");
                fflush(stdin);   scanf("%c",&ch);
                if(ch=='Y'||ch=='y'){
                    goto mainmenu;
                }
                else if (ch=='N'||ch=='n'){
                    goto complete;
                }
                else{
                    goto check2;
                }  				
				
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
    complete:
    cls();middle1();pre(4);  printf("===>Testing of ordering food and paying for food completed  <===");

}
void automated_menu_ingredients_testing(){
    Sleep(1000);
    cls();
    br(2);pre(4);printf("===>Testing of updating ingredients information <===");
    int y= scan_new_ingredients();
    br(2);pre(4);  ASSERT_TEST(y);
	br(2);pre(4);printf("===>Testing of reading ingredients information <===");
	int x = read_Ingredients();
    br(2);pre(4);   ASSERT_TEST(x);

}

void start_automated_testing(void){
    automated_general_design_functions();
    automated_testing_linked_list();
    automated_order_pay_cancel_food();
    automated_menu_ingredients_testing(); 

}