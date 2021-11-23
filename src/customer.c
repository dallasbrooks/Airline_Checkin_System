#include "../hdr/Customer.h"

#include "../hdr/Main.h"

int GetCustomers(char* file){
	int ret = ERR_OK;
	FILE* fp = fopen(file, "r");
	if(fp == NULL){
		ret = ERR_NULLPTR;
		LOGGER(ret);
		return ret;
	}
	if(fscanf(fp, "%d", &lineLength_[_allQueues-1]) < 1){
		ret = ERR_PARSE_FILE;
		LOGGER(ret);
		return ret;
	}
	if(lineLength_[_allQueues-1] < 1){
		ret = ERR_N_CUSTOMERS;
		LOGGER(ret);
		return ret;
	}
	for(int a = 0; a < _allQueues; a++){
		queue_[a] = (customer_t*) malloc(lineLength_[_allQueues-1] * sizeof(customer_t));
	}
	customers_ = (customer_t*) malloc(lineLength_[_allQueues-1] * sizeof(customer_t));
	int allCustomers = 0;
	customer_t p;
	for(int a = 0; a < lineLength_[_allQueues-1]; a++){
		if(fscanf(fp, "%d:%d,%d,%d", &p.cid, &p.qid, &p.atime, &p.stime) != 4){
			ret = ERR_INV_CUSTOMER;
			LOGGER(ret);
			continue;
		}
		if(p.cid < 0 || p.qid < 0 || p.qid >= _queues || p.atime < 0 || p.stime < 0){
			ret = ERR_INV_CUSTOMER;
			LOGGER(ret);
			continue;
		}
		p.index = allCustomers;
		p.clerk = _defaultClerk;
		customers_[allCustomers] = p;
		allCustomers++;
		lineLength_[p.qid]++;
	}
	lineLength_[_allQueues-1] = allCustomers;
	fclose(fp);
	return ret;
}

int InitializeCustomers(){
	int ret = ERR_OK;
	pthread_t customerThread[lineLength_[_allQueues-1]];
	for(int a = 0; a < lineLength_[_allQueues-1]; a++){
		ret = pthread_create(&customerThread[a], NULL, customer_runner, (void*)&customers_[a]);
		if(ret != ERR_OK){
			ret = ERR_CREATE_THREAD;
			return ret;
		}
	}
	for(int a = 0; a < lineLength_[_allQueues-1]; a++){
		ret = pthread_join(customerThread[a], NULL);
		if(ret != ERR_OK){
			ret = ERR_JOIN_THREAD;
			return ret;
		}
	}
	return ret;
}

void* customer_runner(void* info){
	int ret = ERR_OK;
	customer_t* p = (customer_t*) info;
	usleep(p->atime * _MicroStoS);
	printf("A customer arrives: customer ID %2d.\n", p->cid);
	ret = pthread_mutex_lock(&mutex_[_first]);
	if(ret != ERR_OK){
		HandleExit(ERR_LOCK_MUTEX);
	}
	insertQueue(p, p->qid);
	printf("A customer enters a queue: the queue ID %1d, and length of the queue %2d.\n", p->qid, qlength_[p->qid]);
	float time;
	ret = GetTimeNow(&time);
	if(ret != ERR_OK){
		HandleExit(ERR_TIME);
	}
	p->wait_start = time;
	while(p->clerk == _defaultClerk){
		ret = pthread_cond_wait(&convar_[p->qid], &mutex_[_first]); 
		if(ret != ERR_OK){
			HandleExit(ERR_WAIT_CONVAR);
		}
	}
	ret = GetTimeNow(&time);
	if(ret != ERR_OK){
		HandleExit(ERR_TIME);
	}
	p->wait_end = time;
	waitTime_[p->qid] += p->wait_end - p->wait_start;
	printf("A clerk starts serving a customer: start time %.2f, the customer ID %2d, the clerk ID %1d.\n", p->wait_end, p->cid, p->clerk);
	ret = pthread_mutex_unlock(&mutex_[_first]);
	if(ret != ERR_OK){
		HandleExit(ERR_UNLOCK_MUTEX);
	}
	usleep(p->stime * _MicroStoS);
	ret = GetTimeNow(&time);
	if(ret != ERR_OK){
		HandleExit(ERR_TIME);
	}
	printf("A clerk finishes serving a customer: end time %.2f, the customer ID %2d, the clerk ID %1d.\n", time, p->cid, p->clerk);
	int clerk = p->clerk;
	ret = pthread_mutex_lock(&mutex_[clerk]);
	if(ret != ERR_OK){
		HandleExit(ERR_LOCK_MUTEX);
	}
	clerks_[clerk-1].busy = _free;
	ret = pthread_cond_signal(&convar_[clerk+1]);
	if(ret != ERR_OK){
		HandleExit(ERR_BROADCAST_CONVAR);
	}
	ret = pthread_mutex_unlock(&mutex_[clerk]);
	if(ret != ERR_OK){
		HandleExit(ERR_UNLOCK_MUTEX);
	}
	return NULL;
}
