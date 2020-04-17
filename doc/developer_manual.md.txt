# Introduction

Kiosk Machine refers to unattended self-service machines with computers that dispense information or make sales via a touch screen.

In our Project we are developing Self Food Ordering Kiosk Machine which is typically to be a touchscreen computers that allow customers to enter an order into the computer on their own. Restaurants that are able leverage the latest technology trends can often have the largest technological advantage in the market.

# Requirement

The client runs a chain of restaurants and the menu keeps on changing regularly. Client has a need to have a kiosk machine at peak times. Following are his requirements.
1. The system should display menu contains (item id, item name, price, items left in the stock).
2. The customer can order the food from the kiosk machine by giving the item id and quantity required.
3. The system should allow the user to order multiple items.
4. The system should allow the user to cancel the order and system should cancel the order if the quantity orders is more than the items left in the stock.
5. The system should generate total price and ask the customer to pay through card or cash.
6. If customer opts to pay through card, the system should ask his card details (card number, pin) and generate token number locally.
7. If customer pays through cash, the system generates token number locally (prototype).
8. The system gives information about the ingredients of all the menu items through a file document.
9. The system should ask for pin if admin try to login.
10. Admin has the privilege to Add, Update, Remove, Read menu items locally.
11. Admin has the privileges to see the total cash obtained on that day and list of cash transactions happened on that day saving card number and amount without pin.
12. Admin has the privileges to back up the total cash and list of cash transactions to a file. 
13. Admin can view the list of orders placed.


# Program Flow

The program flow for the application is as follows:

![Diagram](https://github.com/vamsiboyella/Kiosk_machine/blob/admin_feaatures/assets/program_structure.jpeg)

- The main.c file calls the functions in kioskmachine.c to run the alogorithm.
- The kioskmachine.c file calls:
  - The functions in admin.c contains all the admin feautres of the project.
  - The functions in ingredients.c to store all the ingredient list.
  - The functions in general_design.c are mostly design functions of the project.