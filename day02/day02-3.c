#include <stdio.h>


int main() {
	int a,b;
	for(a=0;a<=99;a++){
		if(a%3==0&&a%4==0&&a%7==0){
			printf("%d ",a);
			a=a+1;
		}
		else if(a%3==0&&a%4==0){
			printf("%d ",a);
			
		}
		else if(a%7==0)printf("%d\n",a);		
	}	
	return 0;
}
