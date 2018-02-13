#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(int argc, char **argv, char **arge) {
	static long sec_to_nsec = 1000000000;
	struct timespec tps, tpe,start, end;
	struct timeval t1, t2;
	double elapsedTime;
	int w=1;
	
	while(w--)
	{
	clock_gettime(CLOCK_REALTIME, &tps);
	printf("clock_gettime ____CLOCK_REALTIME\n");
	sleep(1); 
	clock_gettime(CLOCK_REALTIME, &tpe);
	printf("%lu s, %lu ns\n\n\n\n", tpe.tv_sec-tps.tv_sec,tpe.tv_nsec-tps.tv_nsec);
	

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start); // get initial time-stamp
	printf("clock_gettime____CLOCL_PROCESS_CPUTIME_ID\n");
	sleep(3); 
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   // get final time-stamp
	double t_ns = (double)(end.tv_sec - start.tv_sec) * 1.0e9 + (double)(end.tv_nsec - start.tv_nsec);
	printf("%lu s, %lu ns\n", end.tv_sec-start.tv_sec,end.tv_nsec-start.tv_nsec);
	printf("time elapsed %lf \n\n\n\n",t_ns);
	




	gettimeofday(&t1, NULL);	
	printf("gettimeofday\n");
	gettimeofday(&t2, NULL);
	printf("%lu s, %lu us\n", t2.tv_sec-t1.tv_sec,t2.tv_usec-t1.tv_usec);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000;
	elapsedTime += (t2.tv_usec - t1.tv_usec);
	//elapsedTime = (t2.tv_usec - t1.tv_usec);
	elapsedTime/=1000;
	elapsedTime/=1000;
	printf("%lf s\n", elapsedTime);
	
	}
	return 0;
}
