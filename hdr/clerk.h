//CLERK_H

int InitializeClerks();
int CreateClerkThread();
void* clerk_runner(void* info);
