CC = gcc
CFLAGS = -Wall
CFLAGS += -g
LIBS = -pthread

SOURCES := $(wildcard ./src/*.c)
HEADERS := $(wildcard ./hdr/*.h)

OUTPUT = ACS
PLAY = ./$(OUTPUT)
CUSTOMERS = ./files/customers.txt
#Uncomment line to run NCustomers file
#CUSTOMERS = ./files/Ncustomers.txt

all: $(OUTPUT)

$(OUTPUT): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(LIBS) -o $(OUTPUT) $(SOURCES)

run:
	$(PLAY) $(CUSTOMERS)

custs:
	$(PLAY)

clean:
	-$(RM) $(OUTPUT)
