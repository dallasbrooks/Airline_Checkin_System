#include "../hdr/Types.h"

#include "../hdr/Main.h"

customer_t* customers_;
customer_t* queue_[_queues];
clerk_t clerks_[_clerks];
int qlength_[_queues] = {0};
float waitTime_[_queues] = {0};
int lineLength_[_allQueues] = {0};
struct timeval program_start_;

pthread_mutex_t mutex_[_mutex];
pthread_cond_t convar_[_convar];
