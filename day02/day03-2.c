#include <stdio.h>
#include <stdlib.h>

int fac(int n);

int main() {
	int num;
	re:
	printf("����� ���丮�� �� �Է�:");
	scanf_s("%d",&num);
	if(num<0){
		printf("�ٽ� �Է��Ͻÿ�");
		goto re;
	} 
	else {
		printf("\n%d ���丮��\n",num);
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
