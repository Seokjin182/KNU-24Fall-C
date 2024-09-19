#include <stdio.h>
#include <stdlib.h>

int fac(int n);

int main() {
	int num;
	re:
	printf("계산할 팩토리얼 값 입력:");
	scanf_s("%d",&num);
	if(num<0){
		printf("다시 입력하시오");
		goto re;
	} 
	else {
		printf("\n%d 팩토리얼\n",num);
		printf(" = %d",fac(num));
	}
	return 0;
}
int fac(int n){
	if(n==1||n==0){
		printf("%d",n);
		return 1;
	}
	else{
		printf("%d*",n);
		return n*fac(n-1);
	}
}
