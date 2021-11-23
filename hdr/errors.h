//ERRORS_H

void HandleExit(int err);
void LOGGER(int err);
char* ErrorMsg(int ret);

#ifndef ERRORS_H
#define ERRORS_H

typedef enum errs_t{
	
	//generic
	ERR_OK,
	ERR_FAIL,

	//customer
	ERR_ARGS,
	ERR_NULLPTR,
	ERR_PARSE_FILE,
	ERR_N_CUSTOMERS,
	ERR_INV_CUSTOMER,

	//threads
	ERR_INIT_MUTEX,
	ERR_INIT_CONVAR,
	ERR_LOCK_MUTEX,
	ERR_UNLOCK_MUTEX,
	ERR_BROADCAST_CONVAR,
	ERR_SIGNAL_CONVAR,
	ERR_WAIT_CONVAR,
	ERR_CREATE_THREAD,
	ERR_JOIN_THREAD,
	ERR_DESTROY_MUTEX,
	ERR_DESTROY_CONVAR,

	//clerks
	ERR_INIT_CLERK,

	//queues
	ERR_INV_QUEUE,

	//time
	ERR_TIME
}errs_t;

#endif
