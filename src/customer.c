#include "../hdr/customer.h"

#include "../hdr/main.h"

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
	int a;
	for(int a = 0; a < _allQueues; a++){
		queue_[a] = (customer_t*) malloc(lineLength_[_allQueues-1] * sizeof(customer_t));
	}
	customers_ = (customer_t*) malloc(lineLength_[_allQueues-1] * sizeof(customer_t));
	int allCustomers = 0;
	customer_t p;
	for(a = 0; a < lineLength_[_allQueues-1]; a++){
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
