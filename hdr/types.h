// TYPES_H

#include "constants.h"
#include <pthread.h>

#ifndef type
#define type

typedef struct customer_t{	//customer node
	int cid;				//customer id
	int qid;				//queue id (0 = economy class, 1 = business class)
	int atime;				//arrival time				
	int stime;				//service time
	int index;				//where customer is stored in customers
	int clerk;				//clerk who serves customer
	float wait_start;		//start time of service
	float wait_end;			//end time of service
}customer_t;

typedef struct clerk_t{		//clerk node
	int id;					//clerk id
	int busy;				//availability of clerk (0 = free, 1 = busy)
}clerk_t;

extern customer_t* customers_;	//list of all customers
extern customer_t* queue_[];	//queues (0 = economy class, 1 = business class)
extern clerk_t clerks_[];		//list of all clerks
extern int qlength_[];			//queue lengths (0 = economy class, 1 = business class)
extern float waitTime_[];		//wait times (0 = economy class, 1 = business class)
extern int lineLength_[];		//total line lengths (0 = economy class, 1 = business class, 2 = total customers)
extern struct timeval program_start_;	//start time of program

extern pthread_mutex_t mutex_[];
extern pthread_cond_t convar_[];

#endif
