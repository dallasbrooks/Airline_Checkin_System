//THREAD_H

#include <pthread.h>

int CreateMutexConvar();
int InitializeMutex();
int InitializeConvar();
int DestroyMutexConvar();
int DestroyMutex();
int DestroyConvar();
