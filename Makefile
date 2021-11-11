CC = gcc
CFLAGS = -Wall
LIBS = -pthread

SOURCES := $(wildcard ./src/*.c)
HEADERS := $(wildcard ./hdr/*.h)

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
