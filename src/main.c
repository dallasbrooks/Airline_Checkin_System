#include "../hdr/main.h"

int main(int argc, char* argv[]){
	int ret = ERR_OK;
	if(argc == ERR_FAIL){
		MakeNCustomers();
		return ret;
	}
	ret = YYJ(argc, argv);
	return ret;
}
