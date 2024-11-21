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
    printf("������ ���� ���� �Է��ϼ���: ");
    scanf_s("%d", &start);
    printf("������ �� ���� �Է��ϼ���: ");
    scanf_s("%d", &end);
    printf("������ �ִ� ���� ���� �Է��ϼ��� (2^n): ");
    scanf_s("%d", &max);

    if (start <= 0 || end <= 0) {
        printf("���� ���� �� ���� 0���� Ŀ�� �մϴ�.\n");
        goto re;
    }

    printf("\n����\t���� ���\n");
    printf("---------------------\n");

    for (i = 0; i <= max; i++) {
        int inte = pow(2, i);
        float result = rec(start, end, inte);
        printf("%d\t%.6f\n", inte, result);
    }

    return 0;
}

