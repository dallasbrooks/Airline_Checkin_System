#include "../hdr/main.h"

int main(int argc, char* argv[]){
	int ret = ERR_OK;
	#ifdef MAKE_CUSTS
		MakeNCustomers();
		return ret;
	#endif
	ret = YYJ(argc, argv);
	return ret;
}
