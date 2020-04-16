/**
 * @file test.c
 *
 * @brief Collections of declaration function of automated unit tests..
 *
 * @author Vamsi Boyella - 
 * @author Baji Baba Shaik - 
 * @author Matheen Mohammed- 
 * @author Sangamesh Patlolla-
 */
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include <errno.h>
#include "../include/general_design.h"
#include "../include/admin.h"
#include "../include/ingredients.h"
#include "../include/test.h"

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
	int fposi;

    head = NULL;
    middle1(); pre(4);printf("-------------------\n");
    middle1(); pre(4);printf("LINKED LIST TESTING\n");
    middle1(); pre(4);printf("-------------------\n");
    //Testing insert first function
    middle1(); pre(4);printf("Addding items to the menu,and testing insert functions");
    br(3);pre(4);      printf(" Enter Food Name :  ");
    fflush(stdin);     scanf("%[^\n]s",ffoodname);
    br(2);pre(4);  printf(" Enter Food Quantity :  ");
	scanf("%d",&fquantity); fflush(stdin);
    br(2);pre(4);  printf(" Enter Food Price :  ");fflush(stdin);
	scanf("%f",&fprice);    
	br(2);pre(4);  printf(" Enter Food Serial :  ");
    scanf("%d",&fdata);
    insertfirst(fdata,ffoodname,fquantity,fprice);
    foodlist();

     //Testing insertend function
    middle1(); pre(4);printf("Addding more items to the menu,and testing insert functions");
    br(3);pre(4);      printf(" Enter Food Name :  ");
    fflush(stdin);     scanf("%[^\n]s",ffoodname);
    br(2);pre(4);  printf(" Enter Food Quantity :  ");
	scanf("%d",&fquantity); fflush(stdin);
    br(2);pre(4);  printf(" Enter Food Price :  ");fflush(stdin);
	scanf("%f",&fprice);    
	br(2);pre(4);  printf(" Enter Food Serial :  ");
    scanf("%d",&fdata);
    insertend(fdata,ffoodname,fquantity,fprice);
    foodlist();

    middle1(); pre(4);printf("Addding more items to the menu,and testing insert functions");
    br(3);pre(4);      printf(" Enter Food Name :  ");
    fflush(stdin);     scanf("%[^\n]s",ffoodname);
    br(2);pre(4);  printf(" Enter Food Quantity :  ");
	scanf("%d",&fquantity); fflush(stdin);
    br(2);pre(4);  printf(" Enter Food Price :  ");fflush(stdin);
	scanf("%f",&fprice);    
	br(2);pre(4);  printf(" Enter Food Serial :  ");
    scanf("%d",&fdata);
    insertend(fdata,ffoodname,fquantity,fprice);
    foodlist();

    //Testing update item function
    middle1(); pre(4);printf("Now testing update function of linked list");
    br(2);pre(4);  printf(" Enter Food Serial id you want to update :  ");
    scanf("%d",&fdata);
    br(3);pre(4);      printf(" Enter Food Name:  ");
    fflush(stdin);     scanf("%[^\n]s",ffoodname);
    br(2);pre(4);  printf(" Enter Food Quantity:  ");
	scanf("%d",&fquantity); fflush(stdin);
    br(2);pre(4);  printf(" Enter Food Price  :  ");fflush(stdin);
	scanf("%f",&fprice);    	
    updateitem(fdata,ffoodname,fquantity,fprice);
    foodlist();

    //Testing delete food function
    middle1();pre(2);
	printf("Enter Serial No of the Food To Delete : ");
	fdelete: ;
	int fdelete;
	fflush(stdin); scanf("%d",&fdelete);
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
    cls();
    insertend(5,"Burger   ",23,120.00);	
	insertend(6,"Pizza    ",13,100.00);
    foodlist();
    int get_food_choice;
	br(2); pre(3);fflush(stdin); printf("Place Your Order: ") ; scanf("%d",&get_food_choice);


}
void automated_menu_ingredients_testing(){
    int x = read_Ingredients();
    ASSERT_TEST(x);

    int y= scan_new_ingredients();
    ASSERT_TEST(y);
}

void start_automated_testing(void){
    automated_general_design_functions();
    automated_testing_linked_list();
    //automated_order_pay_cancel_food();
    automated_menu_ingredients_testing();
    

}