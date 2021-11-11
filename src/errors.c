#include "../hdr/errors.h"

#include "../hdr/main.h"

void LOGGER(int err){
	char* msg = ErrorMsg(err);
	printf("%s (err: %d)\n", msg, err);
}

char* ErrorMsg(int err){
	switch(err){
		case(ERR_OK):
			return "No Error";
		case(ERR_FAIL):
			return "Failure";
		case(ERR_ARGS):
			return "Too few arguments";
		case(ERR_NULLPTR):
			return "Problem finding file";
		case(ERR_PARSE_FILE):
			return "Problem parsing file";
		case(ERR_N_CUSTOMERS):
			return "Invalid number of customers";
		case(ERR_INV_CUSTOMER):
			return "Invalid customer; skipping";
		case(ERR_INIT_MUTEX):
			return "Failure initializing mutex";
		case(ERR_INIT_CONVAR):
			return "Failure initializing convar";
		case(ERR_INIT_CLERK):
			return "Failure initializing clerk thread";
		case(ERR_INV_QUEUE):
			return "Failure invalid queue";
		default:
			return "Unknown Error";
	}
}
