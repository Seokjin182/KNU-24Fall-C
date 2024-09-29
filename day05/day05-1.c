#include <stdio.h>
#include <stdlib.h>

struct Student{
	int snum;
	char name[100];
	int score;
};

int main() {
	struct Student *p;
	int i,n,max=0,min,avg=0;
		
	printf("학생수 입력");
	scanf_s("%d",&n);
	p=(struct Student*)malloc(n*sizeof(struct Student));

	
	for(i=0;i<n;i++){
		printf("학번 : "); 
		scanf_s("%d",&p[i].snum);
		printf("이름 : ");
		scanf_s("%s",p[i].name,100);
		printf("점수 : ");
		scanf_s("%d",&p[i].score);
		if(max<p[i].score)max=p[i].score;
		if(i==0)min=p[i].score;
		if(min>p[i].score)min=p[i].score;
		avg=avg+p[i].score;
	}
	avg=avg/n;
	printf("최대값 : %d\n",max);
	printf("최소값 : %d\n",min);
	printf("평균값 : %d\n",avg);
	
	free(p);
	p=NULL;
	
	
	return 0;
}
