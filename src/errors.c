#include "../hdr/errors.h"

#include "../hdr/main.h"

void LOGGER(int err, char* msg){
	printf("%s (err: %d)\n", msg, err);
}
