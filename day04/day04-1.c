#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char a='A';
	int num=356;
	
	char *ptr1=&a;
	int *ptr2=&num;
	
	printf("%x\n",ptr1);
	printf("%x\n",ptr2); 
	
	printf("%c\n",*ptr1);
	printf("%d\n",*ptr2);
	
	return 0;
}
