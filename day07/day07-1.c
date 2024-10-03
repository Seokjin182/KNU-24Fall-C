#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int i,n,j,a,b;
	printf("피라미드 층 수 입력 : ");
	scanf_s("%d",&n);
	b=n-1;
	n+=3;
	for(i=0;i<n;i++){
		for(a=0;a<=b;a++){
			printf(" ");
		}
		
		for(j=0;j<=i;j++){
			if(i%2==0)printf("*");
		}
		if(i%2==0)printf("\n");
		b-=1;
	}
	return 0;
}
