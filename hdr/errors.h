//ERRORS_H

void LOGGER(int err);
char* ErrorMsg(int ret);

//generic
#define ERR_OK 0
#define ERR_FAIL 1

//customer
#define ERR_ARGS 2
#define ERR_NULLPTR 3
#define ERR_PARSE_FILE 4
#define ERR_N_CUSTOMERS 5
#define ERR_INV_CUSTOMER 6

//threads
#define ERR_INIT_MUTEX 7
#define ERR_INIT_CONVAR 8
#define ERR_LOCK_MUTEX 9
#define ERR_UNLOCK_MUTEX 10
#define ERR_BROADCAST_CONVAR 11
#define ERR_SIGNAL_CONVAR 12
#define ERR_WAIT_CONVAR 13
#define ERR_CREATE_THREAD 14
#define ERR_JOIN_THREAD 15
#define ERR_DESTROY_MUTEX 16
#define ERR_DESTROY_CONVAR 17

//clerks
#define ERR_INIT_CLERK 18

//queues
#define ERR_INV_QUEUE 19

//time
#define ERR_TIME 20
