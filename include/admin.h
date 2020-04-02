/**
 * @file admin.h
 *
 * @brief This is the main file from where all the funtions will be handled by the system.
 * 
 * @author Vamsi Boyella - 
 * @author Baji Baba Shaik - 
 * @author Matheen Mohammed- 
 * @author Sangamesh Patlolla-
 */
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
 * @brief This function is used to add more items at their respective places in the menu.
 *
 * @param[in] pos--- This parameter is used to navigate the position in the linked list.
 * @param[in] data--- This parameter is used to give the item ID.
 * @param[in] foodname--- This parameter is used to give a name for an particular food item.
 * @param[in] quantity--- This parameter is used to give the total number of items present in out stock. 
 * @param[in] price--- This parameter is used to assign the price of that item.
 *
 * @details Function "insertmid" takes input from the user and adds the items of the menu at their respective places. It can also be used to ovverride the menu.
 * 
 * @return There is no return value for this function.
 *
 */ 
void insertmid(int pos, int data, char foodname[25], int quantity, float price);

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
 * @return Thers is no return value for this function but this helps to remove an item from the list.
 *
 */ 
void deletefood(int serial);