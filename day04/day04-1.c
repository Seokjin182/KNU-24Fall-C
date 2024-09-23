#include <stdio.h>
#include <stdlib.h>


int main() {
	int num1=100,num2=100;
	
	int *pnum;
	
	pnum=&num1;
	(*pnum)+=30;
	
	pnum=&num2;
	(*pnum)-=30;
	
	printf("%d\n",num1);
	printf("%d\n",num2);
	return 0;
}
