#include <stdio.h>


int main() {
	int a;
	double num1,num2;
	re:
	printf("원하는 기능 1.더하기 2.빼기 3.나누기 4.곱하기 : ");
	scanf_s("%d",&a);
	printf("숫자입력 1 : ");
	scanf_s("%lf",&num1); 
	printf("숫자입력 2 : ");
	scanf_s("%lf",&num2);
	
	if(a==1)printf("%f + %f = %f",num1,num2,num1+num2);
	else if(a==2)printf("%f - %f = %f",num1,num2,num1-num2);
	else if(a==3)printf("%f / %f = %f",num1,num2,num1/num2);
	else if(a==4)printf("%f * %f = %f",num1,num2,num1*num2);
	else {
		printf("숫자 다시 입력\n");
		goto re; 
	}
	return 0;
}
