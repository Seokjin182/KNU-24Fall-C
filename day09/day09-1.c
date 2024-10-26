#include <stdio.h>
#include <stdlib.h>

struct Vec{
	int x[2];
	int y[2];
	int z[2];
};

int main() {
	struct Vec v;
	int a,xf,yf,zf,total;
	while(1){
		printf("첫번째 백터 x ,y, z	");
		scanf_s("%d %d %d",&v.x[0],&v.y[0],&v.z[0]);
		printf("두번째 백터 x ,y, z	");
		scanf_s("%d %d %d",&v.x[1],&v.y[1],&v.z[1]);
		printf("1.백터의 합 \n 2.백터의 차\n 3.백터의 내적\n 4.백터의 외적\n5.종료\n");
		scanf_s("%d",&a);
		if(a==1){
			xf=v.x[0]+v.x[1];
			yf=v.x[0]+v.x[1];
			zf=v.z[0]+v.z[1];
			printf("x = %d y = %d z = %d\n",xf,yf,zf);
		}
		if(a==2){
			xf=v.x[0]-v.x[1];
			yf=v.x[0]-v.x[1];
			zf=v.z[0]-v.z[1];
			printf("x = %d y = %d z = %d\n",xf,yf,zf);
		}
		if(a==3){
			xf=v.x[0]*v.x[1];
			yf=v.x[0]*v.x[1];
			zf=v.z[0]*v.z[1];
			total=xf+yf+zf;
			printf("백터 내적 = %d\n",total);
		}
		if(a==4){
			xf=(v.y[0]*v.z[1])-(v.z[0]*v.y[1]);
			yf=(v.z[0]*v.x[1])-(v.x[0]*v.z[1]);
			zf=(v.x[0]*v.y[1])-(v.y[0]*v.x[1]);
			printf("x = %d y = %d z = %d\n",xf,yf,zf);
		}
		if(a==5){
			printf(" 종료\n");
			break;
		}
		if(a<0||a>5){
			printf("다시 입력\n");
		}
	}
	
	
	return 0;
}
