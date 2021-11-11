#include "../hdr/makecustomers.h"

#include "../hdr/main.h"

void MakeNCustomers(){
	srand(time(NULL));
	int max = _makeNCustomers;
	FILE* fp = fopen(_outputFile, "w");
	fprintf(fp, "%d\n", max);
	for(int a = 0; a < max; a++){
		int cid = a+1;
		int q = rand()%_queues;
		int atime = rand()%_maxArrivaltime;
		int stime = rand()%_maxServiceTime;
		fprintf(fp, "%d:%d,%d,%d\n", cid, q, atime, stime);
	}
	fclose(fp);
}
