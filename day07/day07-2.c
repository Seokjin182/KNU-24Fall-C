#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
	double x = 0;
	double y = 0;
	int count=0;
	double cir=0;
	srand(time(NULL));
	
	while(count<100000000){
		x=(double)rand()/(double)RAND_MAX;
		y=(double)rand()/(double)RAND_MAX;
		count++;
		if((x*x)+(y*y)<=1){
			cir++;
		}
		if(count%5000000==0)printf("현재 진행 상황%d%% pi=%f\n",(count/5000000)*5,(cir/count)*4);
	}
	
	return 0;
}
