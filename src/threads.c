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

int DestroyThreads(){
	int ret = ERR_OK;
	for(int a = 0; a < _mutex; a++){
		ret = pthread_mutex_destroy(&mutex_[a]);
		if(ret != ERR_OK){
			ret = ERR_DESTROY_MUTEX;
			LOGGER(ret);
			exit(ERR_FAIL);
		}
	}
	for(int a = 0; a < _convar; a++){
		ret = pthread_cond_destroy(&convar_[a]);
		if(ret != ERR_OK){
			ret = ERR_DESTROY_CONVAR;
			LOGGER(ret);
			exit(ERR_FAIL);
		}
	}
	return ret;
}
