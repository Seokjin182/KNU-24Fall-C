#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    int score;
    struct Node* next;
};

struct Node* createNode(char* name, int score);
void insertStudent(struct Node** head, char* name, int score);
void deleteStudent(struct Node** head, char* name);
void printStudents(struct Node* head);
void freeList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice;
    char name[50];
    int score;

    while (1) {
        printf("------------------------------\n");
        printStudents(head);
        printf("------------------------------\n");
        printf("1. 학생의 성적을 입력\n");
        printf("2. 학생 정보 제거\n");
        printf("3. 프로그램 종료\n");
        printf("input : ");
        scanf_s("%d", &choice); // 수정된 부분

        switch (choice) {
        case 1:
            printf("학생 이름 입력 : ");
            scanf_s("%49s", name, (unsigned)_countof(name)); // 수정된 부분
            printf("%s의 성적 : ", name);
            scanf_s("%d", &score); // 수정된 부분
            insertStudent(&head, name, score);
            break;

        case 2:
            printf("삭제할 학생의 이름 입력 : ");
            scanf_s("%49s", name, (unsigned)_countof(name)); // 수정된 부분
            deleteStudent(&head, name);
            break;

        case 3:
            printf("프로그램을 종료합니다.\n");
            freeList(head);
            return 0;

        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
        }
    }
}

struct Node* createNode(char* name, int score) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

void insertStudent(struct Node** head, char* name, int score) {
    if (head == NULL) return;

    struct Node* newNode = createNode(name, score);
    if (*head == NULL || (*head)->score < score) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->score >= score) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteStudent(struct Node** head, char* name) {
    if (head == NULL || *head == NULL) {
        printf("학생 목록이 비어있습니다.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("학생 %s를 찾을 수 없습니다.\n", name);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    }
    else {
        prev->next = current->next;
    }

    printf("학생 %s의 정보가 삭제되었습니다.\n", name);
    free(current);
}

void printStudents(struct Node* head) {
    if (head == NULL) {
        printf("학생 정보가 없습니다.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%s : %d\n", current->name, current->score);
        current = current->next;
    }
}

void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

