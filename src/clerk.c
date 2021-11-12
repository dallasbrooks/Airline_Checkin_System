#include "../hdr/clerk.h"

#include "../hdr/main.h"

int InitializeClerks(){
	int ret = ERR_OK;
	for(int a = 0; a < _clerks; a++){
		clerks_[a].id = a+1;
		clerks_[a].busy = _free;
	}
	ret = CreateClerkThread();
	if(ret != ERR_OK){
		ret = ERR_INIT_CLERK;
		return ret;
	}
	return ret;
}

int CreateClerkThread(){
	int ret = ERR_OK;
	for(int a = 0; a < _clerks; a++){
		pthread_t clerkThread;
		ret = pthread_create(&clerkThread, NULL, clerk_runner, (void*)&clerks_[a]);
		if(ret != ERR_OK){
			ret = ERR_CREATE_THREAD;
			return ret;
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
			HandleExit(ERR_LOCK_MUTEX);
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
				HandleExit(ERR_BROADCAST_CONVAR);
			}
			ret = pthread_mutex_unlock(&mutex_[_first]);
			if(ret != ERR_OK){
				HandleExit(ERR_UNLOCK_MUTEX);
			}
		}else{
			ret = pthread_mutex_unlock(&mutex_[_first]);
			if(ret != ERR_OK){
				HandleExit(ERR_UNLOCK_MUTEX);
			}
			usleep(_sleepSecs);
		}
		ret = pthread_mutex_lock(&mutex_[p->id]);
		if(ret != ERR_OK){
			HandleExit(ERR_LOCK_MUTEX);
		}
		if(clerks_[p->id-1].busy){
			ret = pthread_cond_wait(&convar_[p->id+1], &mutex_[p->id]);
			if(ret != ERR_OK){
				HandleExit(ERR_WAIT_CONVAR);
			}
		}
		ret = pthread_mutex_unlock(&mutex_[p->id]);
		if(ret != ERR_OK){
			HandleExit(ERR_UNLOCK_MUTEX);
		}
	}
	return NULL;
}