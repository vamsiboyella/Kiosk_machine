#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <assert.h>
#include "general_design.h"
#include "validations.h"


/* minimum and maximum credit card number lengths */
#define MIN_LENGTH 13
#define MAX_LENGTH 16
#define ENTER 13
#define TAB 9
#define BKSP 8

/* 
 * Returns the sum of the digits of n. 
 */
int addDigits(int n) {
    return (n / 10) + (n % 10);
}

/* 
 * checks the number enterd is a digit or not. 
 */
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