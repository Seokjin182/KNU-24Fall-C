#include <stdio.h>
#include <stdlib.h>

int cul(int result);

int main() {
	int a;
	printf("소수인지 확인 할 수 : ");
	scanf_s("%d",&a);
	int result = cul(a);
	if(result==1)printf("소수입니다");
	else printf("소수가 아닙니다"); 
	printf("%d",cul(a));
}

int cul(int a){
	int i,c;
	for(i=1;i<=a;i++){
		if(a%i==0)c=c+1;
	}
	if(c==2){
		printf("%d",c);
		return 1;
	}
	else return 0;
}
