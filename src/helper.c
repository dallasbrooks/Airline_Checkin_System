#include "../hdr/helper.h"

#include "../hdr/main.h"

int GetTimeNow(float* time){
	int ret = ERR_OK;
	struct timeval program_now;
	gettimeofday(&program_now, NULL);
	*time = (program_now.tv_sec - program_start_.tv_sec) + (program_now.tv_usec - program_start_.tv_usec)/1000000.0f;
	return ret;
}