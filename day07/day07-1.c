#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int i,n,j,a,b;
	printf("�� ���� �Է��Ͻÿ� : ");
	scanf_s("%d",&n);
	for(i=1;i<=n;i++){
			for(j=1;j<=n-i;j++){
				printf(" ");
			}
			for(j=1;j<=2*i-1;j++){
				printf("*");
			}
			printf("\n");
	}
	return 0;
}
