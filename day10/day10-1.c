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
        printf("1. �л��� ������ �Է�\n");
        printf("2. �л� ���� ����\n");
        printf("3. ���α׷� ����\n");
        printf("input : ");
        scanf_s("%d", &choice); // ������ �κ�

        switch (choice) {
        case 1:
            printf("�л� �̸� �Է� : ");
            scanf_s("%49s", name, (unsigned)_countof(name)); // ������ �κ�
            printf("%s�� ���� : ", name);
            scanf_s("%d", &score); // ������ �κ�
            insertStudent(&head, name, score);
            break;

        case 2:
            printf("������ �л��� �̸� �Է� : ");
            scanf_s("%49s", name, (unsigned)_countof(name)); // ������ �κ�
            deleteStudent(&head, name);
            break;

        case 3:
            printf("���α׷��� �����մϴ�.\n");
            freeList(head);
            return 0;

        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
        }
    }
}

struct Node* createNode(char* name, int score) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("�޸� �Ҵ� ����\n");
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
        printf("�л� ����� ����ֽ��ϴ�.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("�л� %s�� ã�� �� �����ϴ�.\n", name);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    }
    else {
        prev->next = current->next;
    }

    printf("�л� %s�� ������ �����Ǿ����ϴ�.\n", name);
    free(current);
}

void printStudents(struct Node* head) {
    if (head == NULL) {
        printf("�л� ������ �����ϴ�.\n");
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

