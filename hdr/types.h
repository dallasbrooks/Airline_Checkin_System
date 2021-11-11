// TYPES_H

typedef struct customer{	//customer node
	int cid;				//customer id
	int qid;				//queue id (0 = economy class, 1 = business class)
	int atime;				//arrival time				
	int stime;				//service time
	int index;				//where customer is stored in customers
	int clerk;				//clerk who serves customer
	float wait_start;		//start time of service
	float wait_end;			//end time of service
}customer;

typedef struct clerk{		//clerk node
	int id;					//clerk id
	int busy;				//availability of clerk (0 = free, 1 = busy)
}clerk;

customer* customers;		//list of all customers
customer* queue[_queues];	//queues (0 = economy class, 1 = business class)
clerk clerks[_clerks];		//list of all clerks
int qlength[_queues] = {0};	//queue lengths (0 = economy class, 1 = business class)
float waitTime[_queues] = {0};	//wait times (0 = economy class, 1 = business class)
int lineLength[_allQueues] = {0};	//total line lengths (0 = economy class, 1 = business class, 2 = total customers)
struct timeval program_start;//start time of program

pthread_mutex_t mutex[_mutex];
pthread_cond_t convar[_convar];
