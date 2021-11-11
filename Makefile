apple = https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
CC = gcc
CFLAGS = -Wall -I$(IDIR)
LIBS  = -pthread
IDIR = ../hdr

SRC = main.c \
	airport.c \
	clerk.c \
	customer.c \
	errors.c

OBJ = $(SRC:.c=.o)

MAIN = mycc

all: $(MAIN)

$(MAIN): $(OBJ)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)
