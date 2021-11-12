#include "../hdr/helper.h"

#include "../hdr/main.h"

int GetTimeNow(float* time){
	int ret = ERR_OK;
	struct timeval program_now;
	gettimeofday(&program_now, NULL);
	*time = (program_now.tv_sec - program_start_.tv_sec) + (program_now.tv_usec - program_start_.tv_usec)/1000000.0f;
	return ret;
}

int insertQueue(customer_t* p, int k){
	int ret = ERR_OK;
	if(k < _first || k > _queues){
		ret = ERR_INV_QUEUE;
		LOGGER(ret);
		return ret;
	}
	queue_[k][qlength_[k]] = *p;
	qlength_[k]++;
	return ret;
}

int popQueue(int k){
	int cindex = queue_[k][_first].index;
	for(int a = 0; a < qlength_[k]-1; a++){
		queue_[k][a] = queue_[k][a+1];
	}
	qlength_[k]--;
	return cindex;
}

int PrintStats(){
	int ret = ERR_OK;
	float totalWaitTime = 0;
	for(int a = 0; a < _queues; a++){
		totalWaitTime += waitTime_[a];
		printf("The average waiting time for Queue %d is: %.2f seconds.\n", a, waitTime_[a]/lineLength_[a]);
	}
	printf("The average waiting time for all Queues is: %.2f seconds.\n", totalWaitTime/lineLength_[_queues]);
	return ret;
}

int DestroyGlobals(){
	int ret = ERR_OK;
	free(customers_);
	for(int a = 0; a < _queues; a++){
		free(queue_[a]);
	}
	return ret;
}
