# Kiosk Machine

Kiosk Machine refers to unattended self-service machines with computers that dispense information or make sales via a touch screen.


# Authors

- Vamsikrishna Boyella - vboye103@uottawa.ca - University fo Ottawa
- Baji Baba Shaik - bshai015@uottawa.ca - Carleton University
- Matheen Mohammed - MatheenMohammed@cmail.carleton.ca - Carleton University
- Sangameshwar Patlolla - SangameshwarPatlolla@cmail.carleton.ca - Carleton University

# Installation

Installation steps are mentioned in [INSTALL.md](https://github.com/vamsiboyella/Kiosk_machine/blob/master/install.md)

# Usage

To run, you must first install it. Then you can follow instructions mentioned in
[User_Manual.md](https://github.com/vamsiboyella/Kiosk_machine/blob/master/doc/user_manual.md).

# File Structure

The correct file structure (after installing GSL library should be follow and run the binary)

```
├── DOCS.md 	-> Usage file
           └──  Developer_Manual.md
		   └──  Developer_Manual.md
├── INSTALL.md 	-> Installation Guide
├── LICENSE 	-> License file
├── Makefile 	-> Makefile
├── README.md 	-> Readme file
├── bin 	-> Binary directory
├── include 	-> Header files
          ├── admin.h
          ├── general_design.h
          ├── ingredients.h
├── install.sh 	-> Installation script
├── obj 	-> Object files
          ├── admin.o
		  ├── general_design.o
		  ├── ingredients.o
		  ├── main.o
		  ├── test.o
├── kiosk_machine_config 	-> Doxygen Configuration files
├── src 	-> Source files for sensorfusion
│       ├── admin.c
│       ├── general_design.c
│       ├── ingredients.c
│       ├── main.c
│       ├── menu.txt
└── test
          ├── include		-> Header file for unittest
                     └──test.h
          ├──menu.text 	-> Test data
                       └── test.c
```

# For Developers

The developer manual is available [here](https://github.com/vamsiboyella/Kiosk_machine/blob/master/doc/developer_manual.md).

# License

This project is licensed under the GPL 3.0 License - see the [LICENSE.md](https://github.com/vamsiboyella/Kiosk_machine/blob/master/LICENSE) file for details

# Acknowledgements

Thank to Dr. Cristina Ruiz Martin for providing guidance on how to develop the software.
