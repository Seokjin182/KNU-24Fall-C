#include <stdio.h>
#include <stdlib.h>

struct Product{
	int id;
	char name[100];
	int value;
};

int main() {
	struct Product item[5];
	int i;
	for(i=0;i<=4;i++){
		printf("��ǰ id ");
		scanf_s("%d",&item[i].id);
		if(item[i].id==0)break;
		
		printf("��ǰ�� ");
		scanf_s("%s",item[i].name);
		re:
		printf("���� ");
		scanf_s("%d",&item[i].value);
		if(item[i].value<=0)goto re;
	}
	i=0;
	while(item[i].id!=NULL&&i<=4){
		printf("��ǰid %d \n��ǰ�� %s \n���� %d \n",item[i].id,item[i].name,item[i].value);
		i++;
	}
	return 0;
}
