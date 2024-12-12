#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

int i, j, k; // 반복문 변수 선언
int height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, poisonx, poisony, flag,wall2y,wall2x,wall2Active;
int secondWallCreated = 0; // 두 번째 벽 생성 여부
int secondWallX, secondWallY; // 두 번째 벽 좌표
    
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

    // 과일의 초기 위치 설정
    do {
        fruitx = 1 + rand() % (height - 2);
        fruity = 1 + rand() % (width - 2);
    } while (isSnake(fruitx, fruity));

    // 특수 벽 초기화
    wallx = fruitx - 1;
    wally = fruity;


    // 독사과 초기 위치 설정
    do {
        poisonx = 1 + rand() % (height - 2);
        poisony = 1 + rand() % (width - 2);
    } while (isSnake(poisonx, poisony));

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
                printf("X"); // 첫 번째 특수 벽
            } else if (i == secondWallX && j == secondWallY) {
                printf("X"); // 두 번째 특수 벽
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

int isSnake(int fx, int fy) {
    int k;
	if (fx == x && fy == y) return 1; // 머리와 겹침
    for (k = 0; k < tailLength; k++) {
        if (tailX[k] == fx && tailY[k] == fy) return 1;
    }
    return 0;
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
        do {
            fruitx = 1 + rand() % (height - 2);
            fruity = 1 + rand() % (width - 2);
        } while (isSnake(fruitx, fruity));

        // 첫 번째 벽 위치 업데이트
        wallx = fruitx - 1;
        wally = fruity;

        do {
            poisonx = 1 + rand() % (height - 2);
            poisony = 1 + rand() % (width - 2);
        } while (isSnake(poisonx, poisony));

        score += 10;
        tailLength++;

        // 두 번째 벽 생성 조건 (과일을 먹은 후에만 생성)
        static int secondWallCreated = 0; // 두 번째 벽 생성 여부
        if (!secondWallCreated&&score>=50) {
            // 두 번째 벽이 아직 생성되지 않았다면 과일을 먹었을 때 생성
            do {
                secondWallX = 1 + rand() % (height - 2); // 랜덤 X 좌표
                secondWallY = 1 + rand() % (width - 2); // 랜덤 Y 좌표
            } while ((secondWallX == x && secondWallY == y) || isSnake(secondWallX, secondWallY) || (secondWallX == wallx && secondWallY == wally));

            secondWallCreated = 1; // 두 번째 벽 생성 완료
        }
    }

    // 독사과를 먹으면 꼬리 길이 감소
    if (x == poisonx && y == poisony) {
        if (tailLength == 0) {
            gameover = 1;
        } else {
            tailLength--;
        }

        do {
            poisonx = 1 + rand() % (height - 2);
            poisony = 1 + rand() % (width - 2);
        } while (isSnake(poisonx, poisony));
    }

    // 첫 번째 벽 또는 두 번째 벽과 충돌 시 게임 종료
    if ((x == wallx && y == wally) || (x == secondWallX && y == secondWallY)) {
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

