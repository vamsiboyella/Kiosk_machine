/**
 * @file admin.h
 *
 * @brief This is the main file from where all the funtions will be handled by the system.
 * 
 * @author Vamsi Boyella - vboye103@uottawa.ca
 * @author Baji Baba Shaik - bshai015@uottawa.ca
 * @author Matheen Mohammed- MatheenMohammed@cmail.carleton.ca
 * @author Sangamesh Patlolla-SangameshwarPatlolla@cmail.carleton.ca
 */
 
#ifndef TEST_H
#define TEST_H

/**
 * @brief This function is used to create a list of menu items.
 * 
 * @param[in] data--- This parameter is used to give the item ID.
 * @param[in] foodname--- This parameter is used to give a name for an particular food item.
 * @param[in] quantity--- This parameter is used to give the total number of items present in out stock. 
 * @param[in] price--- This parameter is used to assign the price of that item.
 *
 * @details With the help of the above mentioned parameters the initial items of the list are added in this function.
 * 
 * @return There is no return value for this function.
 *
 */ 
void insertfirst(int data, char foodname[25], int quantity, float price);

/**
 * @brief This function is used to update menu items information.
 *
 * @param[in] data--- This parameter is used to give the item ID.
 * @param[in] foodname--- This parameter is used to give a name for an particular food item.
 * @param[in] quantity--- This parameter is used to give the total number of items present in out stock. 
 * @param[in] price--- This parameter is used to assign the price of that item.
 *
 * @details Function "updateitem" takes input from the user and adds the items of the menu at their respective places. It can also be used to ovverride the menu.
 * 
 * @return There is no return value for this function.
 *
 */ 
void updateitem(int data, char foodname[25], int quantity, float price);

/**
 * @brief This function is used to add the last item in the menu.
 * 
 * @param[in] data--- This parameter is used to give the item ID.
 * @param[in] foodname--- This parameter is used to give a name for an particular food item.
 * @param[in] quantity--- This parameter is used to give the total number of items present in out stock. 
 * @param[in] price--- This parameter is used to assign the price of that item.
 * 
 * @details Function "insertend" takes input from the user and add the final item in the menu list.
 * 
 * @return Return value is void for this function.
 *
 */ 
void insertend(int data, char foodname[25], int quantity, float price);

/**
 * @brief This Function is used to update the food menu in our system.
 * 
 * @param[in] udata---this the type of item present in our menu
 * @param[in] uquantity--- This the total quantity of the food that is left in stock once an order is placed.
 * @details with the help of the input parameters given by the owner the food details will be updated accordingly. 
 * 
 * @return Return value is void but it updates the items present in stock.
 *
 */ 
void updatefood(int udata, int uquantity);

/**
 * @brief This Function is used to display the complete food items present in our system.
 * 
 * @details In this function we will be giving different values for different food items. 
 * 
 * @return Return value is void at the end of this function we will be getting the complete list of items.
 *
 */ 
void foodlist();

/**
 * @brief A Function is used to delete the items from the list.
 * 
 * @param[in] serial we will be giving the value for a particular value of an item to be removed from the list.
 * @details with the help of the value giving as an input we will be deleting that particular item from list when its out of stock or sold out.
 * 
 * @return There is no return value for this function but this helps to remove an item from the list.
 *
 */ 
void deletefood(int serial);

/**
 * @brief A Function is used to Display the menu items.
 * 
 * @param[in] order-- this is used to give the order number.
 * @param[in] quantity-- This value is used to give the number of items in an order.
 * @param[in] or_no-- This value gives the particular number of a particular order.
 * @details With the help of these values we will be displaying all the items in the menu.
 * 
 * @return There is no return value for this function.
 *
 */ 
void display_menu(int order, int quantity, int or_no);

/**
 * @brief This function is used to view all the orders placed.
 * 
 * @param[in] order-- this is used to give the order number.
 * @param[in] total_order-- This value gives the total number of orders.
 * @param[in] order_quantity-- This value is used to give quantity of an item in an order.
 * @details this function is used to see the number of orders placed by customer.
 *
 * @return It returns the status code of a function.
 *
 */ 
int view_orders(int order,int total_order[100],	int order_quantity[100]);


#endif