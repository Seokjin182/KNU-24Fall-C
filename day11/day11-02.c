#include <stdio.h>
#include <math.h>

float f(float x) {
    return log10(x) + sin(x);
}

float rec(float start, float end, int inte) {
    int i;
	float h = (end - start) / inte;
    float integral = 0.0;

    for (i = 0; i < inte; i++) {
        float x = start + i * h; 
        integral += f(x) * h; 
    }

    return integral;
}

int main() {
    int max,start,end,i;
	re:
    printf("적분할 시작 값을 입력하세요: ");
    scanf_s("%d", &start);
    printf("적분할 끝 값을 입력하세요: ");
    scanf_s("%d", &end);
    printf("시행할 최대 구간 수를 입력하세요 (2^n): ");
    scanf_s("%d", &max);

    if (start <= 0 || end <= 0) {
        printf("시작 값과 끝 값은 0보다 커야 합니다.\n");
        goto re;
    }

    printf("\n구간\t적분 결과\n");
    printf("---------------------\n");

    for (i = 0; i <= max; i++) {
        int inte = pow(2, i);
        float result = rec(start, end, inte);
        printf("%d\t%.6f\n", inte, result);
    }

    return 0;
}

