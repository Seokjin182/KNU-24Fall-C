#include <stdio.h>
#include <stdlib.h>


int main() {
	int i;
	char *b;
	b=malloc(sizeof(char)*10);
	scanf_s("%s",b);
	for(i=9;i>=0;i--){
		printf("%c",*(b+i));
	}
	return 0;
}
