#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    float d, x1, x2;

    printf("2�� �������� ��� a, b, c�� �Է��ϼ���: ");
    scanf_s("%f %f %f", &a, &b, &c);

    d = b * b - 4 * a * c;

    if (a == 0) {
        printf("a�� 0�� ���, 2�� �������� �ƴմϴ�.\n");
    } 
	else if (d> 0) {
        x1 = (-b + sqrtf(d)) / (2 * a);
        x2 = (-b - sqrtf(d)) / (2 * a);
        printf("�������� �Ǳ�: %.2f, %.2f\n", x1, x2);
    } 
	else if (d == 0) {
        x1 = -b / (2 * a);
        printf("�������� �߱�: %.2f\n", x1);
    } 
	else {
        printf("�Ǳ��� �����ϴ�.\n");
    }

    return 0;
}

