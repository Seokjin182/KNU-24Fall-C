#include <stdio.h>
#include <stdlib.h>

void cul(int a);

int main() {
	int a;
	printf("�Ҽ����� Ȯ�� �� �� : ");
	scanf_s("%d",&a);
	cul(a);
	
}

void cul(int a){
	int i,c=0;
	for(i=1;i<=a;i++){
		if(a%i==0)c=c+1;
	}
	if(c==2){
		
		return printf("�Ҽ� �Դϴ�");;
	}
	else return printf("�Ҽ��� �ƴմϴ�");
}
