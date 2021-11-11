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

void* clerk_runner(void* info){
	return NULL;
}