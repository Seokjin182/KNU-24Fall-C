#include <stdio.h>
#include <stdlib.h>

int cul(int result);

int main() {
	int a;
	printf("�Ҽ����� Ȯ�� �� �� : ");
	scanf_s("%d",&a);
	int result = cul(a);
	if(result==1)printf("�Ҽ��Դϴ�");
	else printf("�Ҽ��� �ƴմϴ�"); 
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
