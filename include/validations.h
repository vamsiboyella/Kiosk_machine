/**
 * @file validations.h
 *
 * @brief This is the main file from where all the funtions will be handled by the system.
 * 
 * @author Vamsi Boyella - vboye103@uottawa.ca
 * @author Baji Baba Shaik - bshai015@uottawa.ca
 * @author Matheen Mohammed- MatheenMohammed@cmail.carleton.ca
 * @author Sangamesh Patlolla-SangameshwarPatlolla@cmail.carleton.ca
 */
 
#ifndef VALIDATIONS_H
#define VALIDATIONS_H
/**
 * @brief This function is used to check for numeric values.
 * 
 * @details This Function takes a numeric string s and returns true if every character of s. 
 * 
 * @return Return value is an boolean value.
 *
 */ 
bool isNumeric(char *);
/**
 * @brief This function works on an alogirthm(luhn's).
 * 
 * @details This function implements Luhn's algorithm: takes a numeric string s and returns
 * 			true if s represents a syntactically valid credit card number,else returns false.
 *
 * @return Return value is an boolean value.
 *
 */ 

bool luhn(char *);

/**
 * @brief This function is used to add digits.
 * 
 * @details this function adds the digits in the form of strings.
 *
 * @return Returns the sum of the digits of n.
 *
 */ 

int  addDigits(int);

/**
 * @brief This function is used to read input from user.
 * 
 * @details this function reads a string from stdin into buffer until newline or EOF is reached
 *			(including leading and trailing whitespace), then null-terminates buffer.
 *
 * @return Returns the sum of the digits of n.
 *
 */ 

void getInput(char *);
/**
 * @brief This function is used to Check the prefix of credit card.
 * 
 * @details This function Checks length of the card number and its first few digits (prefix)
 *			to determine the card type. Prints the card type to stdout.
 *
 * @return Returns the sum of the digits of n.
 *
 */ 

void checkPrefix(char *);

#endif