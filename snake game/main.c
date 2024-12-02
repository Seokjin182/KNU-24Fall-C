#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h> // Windows ����

int i, j, k; // �ݺ��� ���� ����
int height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, poisonx, poisony, flag;

// ���� ��ǥ ���� �迭 �� ����
int tailX[100], tailY[100];
int tailLength = 0;

// Ư�� ���� ��ġ �� Ÿ�̸�
int wallx, wally;
int wallTimerActive = 0;
DWORD wallTimerStart;

void setup() {
    srand(time(0)); // ���� ���� �õ� ����
    gameover = 0;
    x = height / 2;
    y = width / 2;

    fruitx = 1 + rand() % (height - 2);
    fruity = 1 + rand() % (width - 2);

    wallx = fruitx - 1; // �ʱ� Ư�� �� ��ġ
    wally = fruity;

    poisonx = 1 + rand() % (height - 2);
    poisony = 1 + rand() % (width - 2);

    score = 0;
    tailLength = 0; // �ʱ� ���� ����
}

void draw() {
    system("cls");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("#");
            } else if (i == x && j == y) {
                printf("0");
            } else if (i == wallx && j == wally) {
                printf("X"); // Ư�� ��
            } else {
                int isTail = 0;
                for (k = 0; k < tailLength; k++) {
                    if (tailX[k] == i && tailY[k] == j) {
                        printf("o");
                        isTail = 1;
                        break;
                    }
                }
                if (!isTail) {
                    if (i == fruitx && j == fruity) {
                        printf("*");  // ����
                    } else if (i == poisonx && j == poisony) {
                        printf("@");  // �����
                    } else {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
    printf("���� = %d\n", score);
    printf("������ �����Ϸ��� 'X'�� ��������\n");
}

void input() {
    if (_kbhit()) {
        switch (getch()) {
            case 'a': flag = 1; break; // ����
            case 's': flag = 2; break; // �Ʒ�
            case 'd': flag = 3; break; // ������
            case 'w': flag = 4; break; // ��
            case 'x': gameover = 1; break; // ����
        }
    }
}

void logic() {
    Sleep(100);

    // ���� ��ǥ ������Ʈ
    int prevX = tailX[0], prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (k = 1; k < tailLength; k++) {
        prev2X = tailX[k];
        prev2Y = tailY[k];
        tailX[k] = prevX;
        tailY[k] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // ���⿡ ���� ���� �Ӹ� ��ġ ����
    switch (flag) {
        case 1: y--; break;
        case 2: x++; break;
        case 3: y++; break;
        case 4: x--; break;
    }

    // ��� �浹 �� ���� ����
    if (x <= 0 || x >= height - 1 || y <= 0 || y >= width - 1) {
        gameover = 1;
    }

    // �ڽŰ� �浹 �� ���� ����
    for (k = 0; k < tailLength; k++) {
        if (tailX[k] == x && tailY[k] == y) {
            gameover = 1;
        }
    }

    // ������ ������ ���� ���� �� ���� ���� ����
    if (x == fruitx && y == fruity) {
        fruitx = 1 + rand() % (height - 2);
        fruity = 1 + rand() % (width - 2);

        // ���ο� Ư�� �� ��ġ ����
        wallx = fruitx - 1;
        wally = fruity;

        // �� Ÿ�̸� ����
        wallTimerActive = 1;
        wallTimerStart = GetTickCount();

        poisonx = 1 + rand() % (height - 2);
        poisony = 1 + rand() % (width - 2);

        score += 10;
        tailLength++;
    }

    // ������� ������ ���� ���� ����
    if (x == poisonx && y == poisony) {
        // ������ �ϳ��� ���� ���� �� ������� ������ ���� ����
        if (tailLength == 0) {
            gameover = 1;
        } else {
            tailLength--;
        }

        poisonx = 1 + rand() % (height - 2);
        poisony = 1 + rand() % (width - 2);
    }

    // Ư�� ���� �浹 �� ���� ����
    if (x == wallx && y == wally) {
        gameover = 1;
    }

}

int main() {
    setup();
    while (!gameover) {
        draw();
        input();
        logic();
    }
    return 0;
}
