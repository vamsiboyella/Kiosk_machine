/**
 * @file test.h
 *
 * @brief Collections of declaration function of automated unit tests..
 *
 * @author Vamsi Boyella - vboye103@uottawa.ca
 * @author Baji Baba Shaik - bshai015@uottawa.ca
 * @author Matheen Mohammed- MatheenMohammed@cmail.carleton.ca
 * @author Sangamesh Patlolla-SangameshwarPatlolla@cmail.carleton.ca
 */

#ifndef TEST_H
#define TEST_H

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include <errno.h>
#include "general_design.h"
#include "admin.h"
#include "ingredients.h"

/**
 * @brief Starts automated testing
 *
 * @details Entry point into the automated test script
 */
void start_automated_testing(void);

/**
 * @brief Automated unit testing of linked list subsystem
 *
 * @details Automatically tests the linked list functions by doing the
 * following:
 *  - Add a few nodes to a linked list
 *  - Update a few nodes in a linked list
 *  - Count how many nodes are in a linked list
 *  - Move from one linked list to another linked list
 *  - Delete from the middle of a linked list
 *  - Delete from the start of a linked list
 *  - Delete from the end of a linked list
 */
void automated_testing_linked_list(void);


/**
 * @brief Automated unit testing of general design functions
 *
 * @details Automatically tests the all the general design functions
 * 
 */
void automated_general_design_functions(void);
/**
 * @brief Automated unit testing of menu ingredients information file testing
 *
 * @details Automatically tests the opening file and reading from the file and upadating the file
 * 
 */
void automated_menu_ingredients_testing(void);
/**
 * @brief Automated unit testing of ordering food 
 *
 * @details Automatically tests the ordeing food from given menu multiple times and cancel food and  pay for food
 * 
 */
void automated_order_pay_cancel_food(void);



















#endif