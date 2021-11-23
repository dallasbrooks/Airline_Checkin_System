#include "../hdr/Airport.h"

#include "../hdr/Main.h"

int YYJ(int argc, char* argv[]){
	int ret = ERR_OK;
	if(argc < 2){
		ret = ERR_ARGS;
		LOGGER(ret);
		return ret;
	}
	HandleExit(GetCustomers(argv[1]));
	gettimeofday(&program_start_, NULL);
	HandleExit(CreateMutexConvar());
	HandleExit(InitializeClerks());
	HandleExit(InitializeCustomers());
	HandleExit(DestroyMutexConvar());
	HandleExit(PrintStats());
	HandleExit(DestroyGlobals());
	return ret;
}
