#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void fill(int arr[SIZE][SIZE]);
void print(int arr[SIZE][SIZE]);
void move(void *arr);
int n=1;

int main() {
	int arr[SIZE][SIZE];
	int i,j;
	fill(arr);
	print(arr);
	move(arr);
	return 0;
}

void fill(int arr[SIZE][SIZE]){
	int i,j;
	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){
			arr[i][j]=rand()%20+1;
			printf("  %d",arr[i][j]);
		}
		printf("\n");
	}
	
}

void print(int arr[SIZE][SIZE]){
	int i,j,m=0,y=0;
	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){
			if(m==0){
				printf("���� ��ġ %d %d �迭�� %d\n",i,j,arr[i][j]);
				y=arr[i][j];
				m++;
			}
			n++;
		}
		if(y%10==0){
			printf("%d\n",y);
			i=i+(y%10);
		}
		while(y>9){
			y=y-10;
		}
		printf("���� ��ġ %d %d �迭�� %d\n",i,y,arr[i][y]);
		if(i!=9)y=y+arr[i][y];
	}
		i=i-1;
		printf("�� �̻� �̵� �Ұ�\n");
		printf("������ ��ġ %d %d �迭�� %d\n",i,y,arr[i][y]);
}

void move(void *arr){
}
