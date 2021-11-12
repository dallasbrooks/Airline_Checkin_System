#include "../hdr/threads.h"

#include "../hdr/main.h"

int CreateMutexConvar(){
	int ret = ERR_OK;
	ret = InitializeMutex();
	if(ret != ERR_OK){
		return ret;
	}
	ret = InitializeConvar();
	if(ret != ERR_OK){
		return ret;
	}
	return ret;
}

int InitializeMutex(){
	int ret = ERR_OK;
	for(int a = 0; a < _mutex; a++){
		ret = pthread_mutex_init(&mutex_[a], NULL);
		if(ret != ERR_OK){
			ret = ERR_INIT_MUTEX;
			break;
		}
	}
	return ret;
}

int InitializeConvar(){
	int ret = ERR_OK;
	for(int a = 0; a < _convar; a++){
		ret = pthread_cond_init(&convar_[a], NULL);
		if(ret != ERR_OK){
			ret = ERR_INIT_CONVAR;
			break;
		}
	}
	return ret;
}

int DestroyMutexConvar(){
	int ret = ERR_OK;
	ret = DestroyMutex();
	if(ret != ERR_OK){
		return ret;
	}
	ret = DestroyConvar();
	if(ret != ERR_OK){
		return ret;
	}
	return ret;
}

#include <errno.h>

int DestroyMutex(){
	int ret = ERR_OK;
	for(int a = 0; a < _mutex; a++){
		ret = pthread_mutex_destroy(&mutex_[a]);
		if(ret != ERR_OK){
			ret = ERR_DESTROY_MUTEX;
			return ret;
		}
	}
	return ret;
}

int DestroyConvar(){
	int ret = ERR_OK;
	for(int a = 0; a < _convar; a++){
		ret = pthread_cond_destroy(&convar_[a]);
		if(ret != ERR_OK){
			ret = ERR_DESTROY_CONVAR;
			return ret;
		}
	}
	return ret;
}
