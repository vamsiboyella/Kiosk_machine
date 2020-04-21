# Introduction

Food Ordering Kiosk Machine is an self oder application where customers can directly order food without waiting for long time in long queues which is an regular phenomenon in restaurants. All the menu items list is available at touch screen computers at the specific locations in the restaurant. 

# Installation

Please refer to [INSTALL.md](https://github.com/vamsiboyella/Kiosk_machine/blob/dev/install.md) file for installation instructions.

# Usage

The welcome screen says Food Ordering Kiosk machine where we have three options. Among those three, you can choose any option which needed :

1. Food List 
2. Admin Panel
3. Ingredients Info

Following orderly, 

Selecting option 1 takes us to all the food list which are served at the specific resturant. where we have information such as food number, food name, price for the specific food and the availability of items by quantity. Over there we also have two other options which are namely 1) place your order and 2) Main menu by pressing 0.

Selecting option 2 takes us to admin panel where we have a password protected gateway to proceed to login.

selecting option 3 takes us to ingredient information of all the menu items and also all the food items are categorized into different types such as breakfast, lunch and dinner. 

For placing any oder just select option 1 which is basically food list where we have all the menu list from which the wanted items can be selected by entering the food number after then the quantity of the specific food need to be entered then we get the total price for the selected items and also three other options which are:  
1) confirm to buy the item 
2) Want to place another order and
3) Cancel order 

By selecting option 1 we have two options for payment which are:
1) cash and 
2) Credit 

cash can be payed at the counter and by selecting the credit payment option it takes to the protected gateway where Credit card number need to be entered, card validation is done and asks for the pin by entering the pin the payment gets processed. and we also have option to return back to main menu by selecting option provided there.
# Testing

Unit testing is done for each functions defined in the software. The test cases can be run using the command below:


./bin/kiosk machine -t
