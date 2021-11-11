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
	int ret = ERR_OK;
	clerk_t* p = (clerk_t*) info;
	while(TRUE){
		ret = pthread_mutex_lock(&mutex_[_first]);
		if(ret != ERR_OK){
			ret = ERR_LOCK_MUTEX;
			LOGGER(ret);
			exit(ERR_FAIL);
		}
		int qindex = 1;
		if(qlength_[qindex] <= _first){
			qindex = _first;
		}
		if(qlength_[qindex] > _first){
			int cindex = popQueue(qindex);
			customers_[cindex].clerk = p->id;
			clerks_[p->id-1].busy = _busy;
			ret = pthread_cond_broadcast(&convar_[qindex]);
			if(ret != ERR_OK){
				ret = ERR_BROADCAST_CONVAR;
				LOGGER(ret);
				exit(ERR_FAIL);
			}
			ret = pthread_mutex_unlock(&mutex_[_first]);
			if(ret != ERR_OK){
				ret = ERR_UNLOCK_MUTEX;
				LOGGER(ret);
				exit(ERR_FAIL);
			}
		}
		else{
			ret = pthread_mutex_unlock(&mutex_[_first]);
			if(ret != ERR_OK){
				ret = ERR_UNLOCK_MUTEX;
				LOGGER(ret);
				exit(ERR_FAIL);
			}
			usleep(_sleepSecs);
		}
		ret = pthread_mutex_lock(&mutex_[p->id]);
		if(ret != ERR_OK){
			ret = ERR_LOCK_MUTEX;
			LOGGER(ret);
			exit(ERR_FAIL);
		}
		if(clerks_[p->id-1].busy){
			ret = pthread_cond_wait(&convar_[p->id+1], &mutex_[p->id]);
			if(ret != ERR_OK){
				ret = ERR_WAIT_CONVAR;
				LOGGER(ret);
				exit(ERR_FAIL);
			}
		}
		ret = pthread_mutex_unlock(&mutex_[p->id]);
		if(ret != ERR_OK){
			ret = ERR_UNLOCK_MUTEX;
			LOGGER(ret);
			exit(ERR_FAIL);
		}
	}
	return NULL;
}