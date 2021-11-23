#include "../hdr/Errors.h"

#include "../hdr/Main.h"

void HandleExit(int err){
	if(err != ERR_OK){
		LOGGER(err);
		exit(ERR_FAIL);
	}
}

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
		case(ERR_LOCK_MUTEX):
			return "Failure locking mutex";
		case(ERR_UNLOCK_MUTEX):
			return "Failure unlocking mutex";
		case(ERR_BROADCAST_CONVAR):
			return "Failure broadcasting convar";
		case(ERR_SIGNAL_CONVAR):
			return "Failure signalling convar";
		case(ERR_WAIT_CONVAR):
			return "Failure waiting for convar";
		case(ERR_CREATE_THREAD):
			return "Failure creating thread";
		case(ERR_TIME):
			return "Failure getting time";
		case(ERR_DESTROY_MUTEX):
			return "Failure destroying mutex";
		case(ERR_DESTROY_CONVAR):
			return "Failure destroying convar";
		default:
			return "Unknown Error";
	}
}
