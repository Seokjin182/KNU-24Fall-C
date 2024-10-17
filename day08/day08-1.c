#include <stdio.h>
#include <string.h>


int isAlphabet(char* str) {
	int i;
	for (i = 0; i < strlen(str); i++) {
		char cur = *(str + i);
		if (!((cur >= 65 && cur <= 90) || (cur >= 97 && cur <= 122))) return 0;
	}
	return 1;
}

void reverse_string(char* str) {
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
	do {
		printf("문자열을 입력하세요 : ");
		scanf_s("%s", &str, 10);
	} while (!isAlphabet(str));
	reverse_string(str);
	printf("%s", str);
}
