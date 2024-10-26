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
		printf("상품 id ");
		scanf_s("%d",&item[i].id);
		if(item[i].id==0)break;
		
		printf("상품명 ");
		scanf_s("%s",item[i].name);
		re:
		printf("가격 ");
		scanf_s("%d",&item[i].value);
		if(item[i].value<=0)goto re;
	}
	i=0;
	while(item[i].id!=NULL&&i<=4){
		printf("상품id %d \n상품명 %s \n가격 %d \n",item[i].id,item[i].name,item[i].value);
		i++;
	}
	return 0;
}
