
# Generic Makefile
 
 # @author Vamsi Boyella - vboye103@uottawa.ca
 # @author Baji Baba Shaik - bshai015@uottawa.ca
 # @author Matheen Mohammed- MatheenMohammed@cmail.carleton.ca
 # @author Sangamesh Patlolla-SangameshwarPatlolla@cmail.carleton.ca
 
# Date  : 2020-04-15


# project name (generate executable with this name)
TARGET   = kiosk_machine

# change these to proper directories where each file should be
SRCDIR     	 = src
SRCTESTDIR	 = test
OBJDIR    	 = obj
BINDIR    	 = bin
INCDIR	  	 = include
INCTESTDIR	 = test/include


CC       = gcc
# compiling flags here
CFLAGS   = -Wall


INC      := -I$(INCDIR)  -I$(INCTESTDIR)
SOURCES  := $(wildcard $(SRCDIR)/*.c)
TSOURCES := $(wildcard $(SRCTESTDIR)/*.c)
OBJECTS1 := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJECTS2 := $(TSOURCES:$(SRCTESTDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS1) $(OBJECTS2)
	@mkdir -p $(BINDIR)
	@$(CC) $(OBJECTS1) $(OBJECTS2)  -o $@
	@echo "Linking complete!"

$(OBJECTS1): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "Compiled "$<" successfully!"

$(OBJECTS2): $(OBJDIR)/%.o : $(SRCTESTDIR)/%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "Compiled "$<" successfully!"
.PHONY: clean
clean:
	@$(rm) $(OBJECTS1) $(OBJECTS2) $(BINDIR)/$(TARGET)	
	@echo "Cleanup complete!"








