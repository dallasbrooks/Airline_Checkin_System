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
