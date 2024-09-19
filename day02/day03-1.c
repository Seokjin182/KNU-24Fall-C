#include <stdio.h>
#include <stdlib.h>

void cul(int a);

int main() {
	int a;
	printf("소수인지 확인 할 수 : ");
	scanf_s("%d",&a);
	cul(a);
	
}

void cul(int a){
	int i,c=0;
	for(i=1;i<=a;i++){
		if(a%i==0)c=c+1;
	}
	if(c==2){
		
		return printf("소수 입니다");;
	}
	else return printf("소수가 아닙니다");
}
