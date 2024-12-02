#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h> // Windows 전용

int i, j, k; // 반복문 변수 선언
int height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, poisonx, poisony, flag;

// 꼬리 좌표 저장 배열 및 길이
int tailX[100], tailY[100];
int tailLength = 0;

// 특수 벽의 위치 및 타이머
int wallx, wally;
int wallTimerActive = 0;
DWORD wallTimerStart;

void setup() {
    srand(time(0)); // 난수 생성 시드 설정
    gameover = 0;
    x = height / 2;
    y = width / 2;

    fruitx = 1 + rand() % (height - 2);
    fruity = 1 + rand() % (width - 2);

    wallx = fruitx - 1; // 초기 특수 벽 위치
    wally = fruity;

    poisonx = 1 + rand() % (height - 2);
    poisony = 1 + rand() % (width - 2);

    score = 0;
    tailLength = 0; // 초기 꼬리 길이
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
                printf("X"); // 특수 벽
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
                        printf("*");  // 과일
                    } else if (i == poisonx && j == poisony) {
                        printf("@");  // 독사과
                    } else {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
    printf("점수 = %d\n", score);
    printf("게임을 종료하려면 'X'를 누르세요\n");
}

void input() {
    if (_kbhit()) {
        switch (getch()) {
            case 'a': flag = 1; break; // 왼쪽
            case 's': flag = 2; break; // 아래
            case 'd': flag = 3; break; // 오른쪽
            case 'w': flag = 4; break; // 위
            case 'x': gameover = 1; break; // 종료
        }
    }
}

void logic() {
    Sleep(100);

    // 꼬리 좌표 업데이트
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

    // 방향에 따라 뱀의 머리 위치 변경
    switch (flag) {
        case 1: y--; break;
        case 2: x++; break;
        case 3: y++; break;
        case 4: x--; break;
    }

    // 경계 충돌 시 게임 종료
    if (x <= 0 || x >= height - 1 || y <= 0 || y >= width - 1) {
        gameover = 1;
    }

    // 자신과 충돌 시 게임 종료
    for (k = 0; k < tailLength; k++) {
        if (tailX[k] == x && tailY[k] == y) {
            gameover = 1;
        }
    }

    // 과일을 먹으면 점수 증가 및 꼬리 길이 증가
    if (x == fruitx && y == fruity) {
        fruitx = 1 + rand() % (height - 2);
        fruity = 1 + rand() % (width - 2);

        // 새로운 특수 벽 위치 설정
        wallx = fruitx - 1;
        wally = fruity;

        // 벽 타이머 시작
        wallTimerActive = 1;
        wallTimerStart = GetTickCount();

        poisonx = 1 + rand() % (height - 2);
        poisony = 1 + rand() % (width - 2);

        score += 10;
        tailLength++;
    }

    // 독사과를 먹으면 꼬리 길이 감소
    if (x == poisonx && y == poisony) {
        // 꼬리가 하나만 남아 있을 때 독사과를 먹으면 게임 종료
        if (tailLength == 0) {
            gameover = 1;
        } else {
            tailLength--;
        }

        poisonx = 1 + rand() % (height - 2);
        poisony = 1 + rand() % (width - 2);
    }

    // 특수 벽과 충돌 시 게임 종료
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

