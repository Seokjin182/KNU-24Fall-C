#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    float d, x1, x2;

    printf("2차 방정식의 계수 a, b, c를 입력하세요: ");
    scanf_s("%f %f %f", &a, &b, &c);

    d = b * b - 4 * a * c;

    if (a == 0) {
        printf("a가 0일 경우, 2차 방정식이 아닙니다.\n");
    } 
	else if (d> 0) {
        x1 = (-b + sqrtf(d)) / (2 * a);
        x2 = (-b - sqrtf(d)) / (2 * a);
        printf("방정식의 실근: %.2f, %.2f\n", x1, x2);
    } 
	else if (d == 0) {
        x1 = -b / (2 * a);
        printf("방정식의 중근: %.2f\n", x1);
    } 
	else {
        printf("실근이 없습니다.\n");
    }

    return 0;
}

