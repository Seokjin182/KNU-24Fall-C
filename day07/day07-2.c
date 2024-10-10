#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
	double x = 0;
	double y = 0;
	int count=0,a=0,i;
	double cir=0;
	srand(time(NULL));
	
	while(count<100000000){
		x=(double)rand()/(double)RAND_MAX;
		y=(double)rand()/(double)RAND_MAX;
		count++;
		if((x*x)+(y*y)<=1){
			cir++;
		}
		if(count%1000000==0){
			printf("현재 진행 상황%d%% pi=%f",(count/1000000),(cir/count)*4);
			if(count%5000000==0){
				a++;
			}
			for(i=0;i<=a;i++){
					printf("*");	
			}
			printf("\n");
		}
		
	}
	
	return 0;
}
