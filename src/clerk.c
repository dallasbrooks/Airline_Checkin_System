#include "../hdr/clerk.h"

#include "../hdr/main.h"

int InitializeClerks(){
	int ret = ERR_OK;
	for(int a = 0; a < _clerks; a++){
		clerks_[a].id = a+1;
		clerks_[a].busy = _defaultBusy;
	}
	return ret;
}

int CreateClerkThread(){
	int ret = ERR_OK;
	for(int a = 0; a < _clerks; a++){
		pthread_t clerkThread;
		if(pthread_create(&clerkThread, NULL, clerk_runner, (void*)&clerks_[a]) != ERR_OK){
			ret = ERR_INIT_CLERK;
			LOGGER(ret);
			exit(ERR_FAIL);
		}
	}
	return ret;
}

void* clerk_runner(void* info){
	clerk_t* p = (clerk_t*) info;
	while(1){
		if(pthread_mutex_lock(&mutex_[_first]) != 0){
			printf("Error: failed to lock mutex.\n");
			exit(1);
		}
		int qindex = 1;
		if(qlength_[qindex] <= _first){
			qindex = 0;
		}
		if(qlength_[qindex] > 0){
			int cindex = popQueue(qindex);
			customers_[cindex].clerk = p->id;
			clerks_[p->id-1].busy = _busy;
			if(pthread_cond_broadcast(&convar_[qindex]) != 0){
				printf("Error: failed to broadcast convar.\n");
				exit(1);
			}
			if(pthread_mutex_unlock(&mutex_[0]) != 0){
				printf("Error: failed to unlock mutex.\n");
				exit(1);
			}
		}
		else{
			if(pthread_mutex_unlock(&mutex_[0]) != 0){
				printf("Error: failed to unlock mutex.\n");
				exit(1);
			}
			usleep(250);
		}
		if(pthread_mutex_lock(&mutex_[p->id]) != 0){
			printf("Error: failed to lock mutex.\n");
			exit(1);
		}
		if(clerks_[p->id-1].busy){
			if(pthread_cond_wait(&convar_[p->id+1], &mutex_[p->id]) != 0){
				printf("Error: failed to wait.\n");
				exit(1);
			}
		}
		if(pthread_mutex_unlock(&mutex_[p->id]) != 0){
			printf("Error: failed to unlock mutex.\n");
			exit(1);
		}
	}
	return NULL;
}