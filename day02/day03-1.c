#include <stdio.h>
#include <stdlib.h>

int cul(int result);

int main() {
	int a;
	printf("�Ҽ����� Ȯ�� �� �� : ");
	scanf_s("%d",&a);
	int result = cul(a);
	if(result==1)printf("�Ҽ��Դϴ�");
	else printf("�Ҽ��� �ƴմϴ�."); 
}

int cul(int a){
	int i,c;
	for(i=2;i<a;i++){
		if(a%i==0) return 0;
		else return 1;
	}
}
