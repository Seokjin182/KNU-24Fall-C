#include <stdio.h>


int main() {
	int a;
	double num1,num2;
	re:
	printf("���ϴ� ��� 1.���ϱ� 2.���� 3.������ 4.���ϱ� : ");
	scanf_s("%d",&a);
	printf("�����Է� 1 : ");
	scanf_s("%lf",&num1); 
	printf("�����Է� 2 : ");
	scanf_s("%lf",&num2);
	
	if(a==1)printf("%f + %f = %f",num1,num2,num1+num2);
	else if(a==2)printf("%f - %f = %f",num1,num2,num1-num2);
	else if(a==3)printf("%f / %f = %f",num1,num2,num1/num2);
	else if(a==4)printf("%f * %f = %f",num1,num2,num1*num2);
	else {
		printf("���� �ٽ� �Է�\n");
		goto re; 
	}
	return 0;
}
