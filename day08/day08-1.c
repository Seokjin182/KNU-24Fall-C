#include <stdio.h>
#include <stdlib.h>

void rev(char* str) {
	int i;
	char tmp;
	char* start = str;
	char* end = str + strlen(str) - 1;
	for (i = 0; i < strlen(str)/2; i++) {
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

int main() {
	char str[10];
	printf("문자열을 입력하세요 : ");
	scanf_s("%s", &str, 10);
	rev(str);
	printf("%s", str);
}
