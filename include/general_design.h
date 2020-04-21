/**
 * @file general_design.h
 *
 * @brief This is the main file of design module in system from which all the funtions related to design will be handled.
 *
 * @author Vamsi Boyella - vboye103@uottawa.ca
 * @author Baji Baba Shaik - bshai015@uottawa.ca
 * @author Matheen Mohammed- MatheenMohammed@cmail.carleton.ca
 * @author Sangamesh Patlolla-SangameshwarPatlolla@cmail.carleton.ca
 */
#ifndef GENERAL_DESIGN_H
#define GENERAL_DESIGN_H

/**
 * @brief This function is used to clear the screen.
 * 
 * @details This is a predefined function which is used to clear the screen.
 * This function is mainly used in the design part of the system.
 * 
 * @return There is no return value for this function.
 *
 */ 
void cls();

/**
 * @brief This function is used to print a string.
 * 
 * @param[in] print[]--- we will provide a string which we want to print.
 *  
 * @details With the help of the above input parameter it will display the output accordingly
 * This function is used in place of Printf fucntion in our system.
 *
 * @return There is no return value for this function.
 *
 */ 
void echo(char print[]);

/**
 * @brief A Function which is used to give the line spacing.
 * 
 * @param[in] line--- user will be giving number of lines here.
 *  
 * @details With the help of this input this function will be providing the number of line spaces accordingly.
 * 
 * @return There is no return value for this function.
 *
 */ 

void main_menu();
void br(int line);

/**
 * @brief This function is used to provide spacing between the characters.
 * 
 * @param[in] tab--- An input in form of number will be provided.
 *  
 * @details Based on the input provided the number of tab spaces will be provied.
 * 
 * @return There is no return value for the function.
 *
 */ 
void pre(int tab);

/**
 * @brief This function is used to handle the spacing conventions in our system.
 * 
 * @param[in] space--- An number will be givien as input.
 * 
 * @details Based on the input provided the number of empty spaces will be provided in our code.
 * 
 * @return There is no return value for this function.
 *
 */ 
void span(int space);

/**
 * @brief This function is used to handle the color for the welcome message in our system.
 * 
 * @param[in] clr--- we will be giving the color number to the system as input.
 * 
 * @details Based on the input provided that particular color will be assigned to the message.
 * 
 * @return Return value is void.
 *
 */ 
void ccolor(int clr);

/**
 * @brief This function is used to handle the welcome message of our kiosk machine. 
 * 
 * @details Once our kiosk machine is opened user will be given an good and handy design.
 *  The complete welcome message given to the user will be handled in this function.
 * 
 * @return Return value is void.
 *
 */ 
void pwellcome();

/**
 * @brief This function is used to handle the loading bar in our system. 
 * 
 * @details There are no inputs for this function.
 * The loading bar of our system will be managed with the help of other functions like ccolor etc.
 * 
 * @return Return value is void.
 *
 */ 
void loadingbar();

/**
 * @brief This function is used to handle the line spacing.
 * 
 * @details There are no input parameters for this function it directly provides 7 line spaces.
 * 
 * @return Return value is void.
 *
 */ 
void middle1(void);

/**
 * @brief This function is used to handle the character spaces.
 * 
 * @details There are no input parameters for this function, it directly provides 6 character spaces.
 * 
 * @return There is no return value for this function.
 *
 */ 
void middtab1(void);

/**
 * @brief In this function the design of backup loader will be handled.
 * 
 * @details There are no input values for this function it handles the backup loading part of the system which helps the admin to have the backup of data.
 * 
 * @return No return value for this function.
 *
 */ 
void backuploader(void);

#endif