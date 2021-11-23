CC = gcc
CFLAGS = -Wall -g
#Uncomment line to run NCustomers file
#CFLAGS += -DMAKE_CUSTS
LIBS = -pthread

SOURCES := $(wildcard ./src/*.c)
HEADERS := $(wildcard ./hdr/*.h)

OUTPUT = ACS
PLAY = ./$(OUTPUT)
CUSTOMERS = ./files/customers.txt
#CUSTOMERS = ./files/NCustomers.txt

all: $(OUTPUT)

$(OUTPUT): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(LIBS) -o $(OUTPUT) $(SOURCES)

run:
	$(PLAY) $(CUSTOMERS)

clean:
	-$(RM) $(OUTPUT)
