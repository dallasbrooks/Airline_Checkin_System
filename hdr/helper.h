//HELPER_H

#include "types.h"

int GetTimeNow(float* time);

int insertQueue(customer_t* p, int k);
int popQueue(int k);

int PrintStats();

int DestroyGlobals();
