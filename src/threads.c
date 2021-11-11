#include "../hdr/threads.h"

#include "../hdr/main.h"

int InitializeMutex(){
	int ret = ERR_OK;
	for(int a = 0; a < _mutex; a++){
		if(pthread_mutex_init(&mutex_[a], NULL) != ERR_OK){
			ret = ERR_INIT_MUTEX;
			break;
		}
	}
	return ret;
}

int InitializeConvar(){
	int ret = ERR_OK;
	for(int a = 0; a < _convar; a++){
		if(pthread_cond_init(&convar_[a], NULL) != 0){
			ret = ERR_INIT_CONVAR;
			break;
		}
	}
	return ret;
}

