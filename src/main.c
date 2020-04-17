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
#include "ingredients.h"

/* minimum and maximum credit card number lengths */
#define MIN_LENGTH 13
#define MAX_LENGTH 16
#define ENTER 13
#define TAB 9
#define BKSP 8

/* function prototypes */
bool isNumeric(char *);
bool luhn(char *);
int  addDigits(int);
void getInput(char *);
void checkPrefix(char *);


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

					cls();  middle1(); pre(4);   printf("Todays Total Cash : %0.2f  \n",totalmoney);

					Sleep(2000);

					goto adminchoise;
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
					goto adminchoise;
				}

				else if(adminchoise==3){

					foodadd:
					cls();
//step 3
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
					fqresult = scanf("%d",&fquantity); 
					if(!fqresult){
					br(2);pre(4);
					printf("Enter valid value");
					goto fquantity;
					}
					fflush(stdin);
					
					
					foodserial:
					br(2);pre(4);  printf(" Enter Food Serial :  ");
                    fqresult=scanf("%f",&fdata);
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
                       cls(); br(5);pre(3);  printf(" Food Serial Already Exist, Please Re-Enter  "); Sleep(2000);
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

					goto adminchoise;

				}

				else if(adminchoise==4){

					cls();
					middle1();pre(2);
					printf("Enter Serial No of the Food To Delete : ");
					fdelete: ;
					int fdelete;
					fflush(stdin);
					int fqresult=scanf("%f",&fdelete);
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


					goto adminchoise;
				}

				else if(adminchoise==5){

					cls();    foodlist(); Sleep(1000);

					br(2);pre(4);  printf("1. <-- back  \n\n");pre(5);

					fflush(stdin);   scanf("%d",&any);

					goto adminchoise;

				}

				else if(adminchoise==6){
					cls();
					char ffoodname[25];
					int fquantity;
					int data;
					float fprice;
					int fposi;

					foodchoice_id:

					br(3);pre(3);      printf(" Please enter the food choice Id you want to update :  ");

					fflush(stdin);  
					fqresult=scanf("%f",&data);
					if(!fqresult){
					br(2);pre(4);
					printf("Enter valid value");
					goto foodchoice_id;
					}
					        node *exist;
                            exist = list;
                      while(exist->data!=data){
                            if(exist->next==NULL){
								cls(); br(5);pre(3);  printf(" Food Id doesn't exist, Please Re-Enter  "); Sleep(2000);
                       			goto foodchoice_id;
                                //break;
                            }
                        exist=exist->next;
                      } 				
					br(2);pre(4);  printf("  Enter the Food Name  :  ");
					fflush(stdin);	
					scanf("%[^\n]s",ffoodname);			    
                    stock:
					br(2);pre(4);  printf(" Enter the qunatity of stock :  ");
					fflush(stdin);  
					fqresult=scanf("%f",&data);
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

					goto adminchoise;

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
						goto adminchoise;
					}
					fprintf(fptr,"Total Cash Today : %0.2f\n\n\n",totalmoney);
					fprintf(fptr,"Card No ------- Money \n\n");
					for(int l=1; l<=c;l++){
						fprintf(fptr,"%s ------- %0.2f \n",cardno[l],cardmoney[l]);
					}
					br(2);pre(4); printf("Backup Successfull..."); Sleep(1500);



					fclose(fptr);
					goto adminchoise;
				}

				else if(adminchoise==8){
					int i=view_orders( order, total_order,order_quantity);
					if(i){
					goto adminchoise;
					}	
					else{
					goto adminchoise;	
					}

				}

				else if(adminchoise==9){
					cls();
					int i= scan_new_ingredients();
					if(i){						
						br(2);pre(4); printf("Update of food infromation successfull..."); Sleep(1500);
						goto adminchoise;
					}
					else{
						goto adminchoise;
					}

				}

				else if(adminchoise==0){

					goto mainmenu;
				}

				else{
					br(2); pre(4); printf("Please Select From List :  "); Sleep(500);
					goto adminchoise;
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
//Step 3
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
				
				// Step 1
				// int card_number;
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
				
				do {
					cls();
					br(2);pre(2);
					printf("Enter Your Card Pin [we never save your pin]  : ");
					getInput(input);
					} while (isNumeric(input) == false);
				
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


bool isNumeric(char *s) {
	
    
	if (s == NULL){
		br(2);pre(4); printf("please enter a valid entry");
        return false;
    }
    while (*s != '\0') {
        if (! isdigit(*s)){
		br(2);pre(4); printf("please enter a valid entry");
            return false;
        }
		s++;
    }
    return true;
}


/* 
 * Implements Luhn's algorithm: takes a numeric string s and returns
 * true if s represents a syntactically valid credit card number,
 * else returns false.
 */
bool luhn(char *s) {
    int sum = 0;
    int digit, i;
    int length = strlen(s);
    
    if (! (length >= MIN_LENGTH && length <= MAX_LENGTH)) 
        return false;    
    
    // even length
    if (length % 2 == 0) {
        for (i = 0; i < length; i++) {
            digit = s[i] - '0';
            if (i % 2 == 0)
                sum += addDigits(2 * digit);
            else
                sum += digit;
        } 
    }
    // odd length
    else {
        for (i = 0; i < length; i++) {
            digit = s[i] - '0';
            if (i % 2 == 0)
                sum += digit;
            else
                sum += addDigits(2 * digit);
        } 
    }

    // sum is divisible by 10 for valid cards
    return (sum % 10 == 0);
}


/* 
 * Returns the sum of the digits of n. 
 */
int addDigits(int n) {
    return (n / 10) + (n % 10);
}


/* 
 * Reads a string from stdin into buffer until newline or EOF is reached
 * (including leading and trailing whitespace), then null-terminates buffer. 
 */ 
void getInput(char *buffer) {
   
    int length = 0;                 // number of characters in buffer 
    int capacity = MAX_LENGTH + 1;  // capacity of buffer 
    int c;                          // character read
    
    while ( (c = fgetc(stdin)) != '\n' && c != EOF) {

        // if input is too long, try to double the buffer capacity 
        if (length + 1 > capacity) {
            capacity *= 2;
            buffer = realloc(buffer, capacity * sizeof(*buffer));
            assert(buffer != NULL);
        }    

        // put current character in the buffer
        buffer[length++] = c;
    }
    
    // null-terminate buffer
    buffer[length] = '\0';
}


/* 
 * Checks length of the card number and its first few digits (prefix)
 * to determine the card type. Prints the card type to stdout.
 */
void checkPrefix(char *s) {
    
    int length = strlen(s);

    // Visa: 13 or 16 digits starting with 4
    if ((length == 13 || length == 16) && s[0] == '4'){
       br(2);pre(4); printf("Visa\n");
	}

    // Mastercard: 16 digits starting with 5
    else if (length == 16 && s[0] == '5'){
		br(2);pre(4);
        printf("Mastercard\n");
	}

    // Discover: 16 digits starting with 6011
    else if (length == 16 && s[0] == '6' && s[1] == '0' && s[2] == '1' && s[3] == '1'){
		br(2);pre(4);
        printf("Discover\n");
	}

    // American Express: 15 digits starting with 34 or 37
    else if (length == 15 && s[0] == '3' && (s[1] == '4' || s[1] == '7')){
		br(2);pre(4);
        printf("American Express\n");
	}
    else {
	br(2);pre(4);
        printf("\nThis number is syntactically valid, but it is not a Visa, Mastercard, Discover, or American Express.\n");
	}
}

