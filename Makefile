CC = gcc
CFLAGS = -Wall
LIBS = -pthread

SOURCES := $(shell find . -name '*.c')
HEADERS := $(shell find . -name '*.h')

OUTPUT = ACS
PLAY = ./$(OUTPUT)
CUSTOMERS = ./files/customers.txt

all: $(OUTPUT)

$(OUTPUT): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(LIBS) -o $(OUTPUT) $(SOURCES)

run:
	$(PLAY) $(CUSTOMERS)

clean:
	-$(RM) $(OUTPUT)
