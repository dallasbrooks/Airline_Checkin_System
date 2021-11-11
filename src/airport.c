#include "../hdr/airport.h"

#include "../hdr/main.h"

int YYJ(int argc, char* argv[]){
	int ret = ERR_OK;
	if(argc < 2){
		ret = ERR_ARGS;
		LOGGER(ret);
		return ret;
	}
	ret = GetCustomers(argv[1]);
	if(ret != ERR_OK){
		LOGGER(ret);
		exit(ERR_FAIL);
	}
	gettimeofday(&program_start_, NULL);
	ret = InitializeMutex();
	if(ret != ERR_OK){
		LOGGER(ret);
		exit(ERR_FAIL);
	}
	ret = InitializeConvar();
	if(ret != ERR_OK){
		LOGGER(ret);
		exit(ERR_FAIL);
	}
	ret = InitializeClerks();
	if(ret != ERR_OK){
		LOGGER(ret);
		exit(ERR_FAIL);
	}
	ret = InitializeCustomers();
	if(ret != ERR_OK){
		LOGGER(ret);
		exit(ERR_FAIL);
	}
	return ret;
}
