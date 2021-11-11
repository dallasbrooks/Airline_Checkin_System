#include "../hdr/airport.h"

#include "../hdr/main.h"

int YYJ(int argc, char* arv[]){
	int ret = ERR_OK;
	if(argc < 2){
		ret = ERR_ARGS;
		LOGGER(ret, "Too few arguments.");
		return ret;
	}
	printf("test\n");
	return ret;
}
