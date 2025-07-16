#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100
typedef struct  Node {
    char action[MAX_LENGTH];
    char Timestamp[30];
    struct Node* next;
}Node;
typedef struct {
    Node* top;
}Stack;

void initStack(Stack* s) {
    s->top = NULL;
}

int isEmptyStack(Stack* s) {
    return s->top == NULL;
}
void push(Stack* s,const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("khong the cap phat bo nho \n");
        return;
    }
    strcpy(newNode->action,value);
    newNode->next = s->top;
    s->top = newNode;
}


void undoToRedo(Stack* undo,Stack* redo) {
    if (isEmptyStack(undo)) {
        printf("Stack rong \n");
        return;
    }
    Node* temp = undo->top;
    undo->top = temp->next;
    push(redo,temp->action);
    free(temp);
    printf("Day thao tac thanh cong \n");
    return;
}
void redoToUndo(Stack* undo,Stack* redo) {
    if (isEmptyStack(redo)) {
        printf("Stack rong \n");
        return;
    }
    Node* temp = redo->top;
    redo->top = temp->next;
    push(undo,temp->action);
    free(temp);
    printf("Day thao tac thanh cong \n");
    return;
}

void printStack(Stack* s) {
    if (isEmptyStack(s)) {
        printf("Stack rong \n");
        return;
    }
    Node* temp = s->top;
    int i=0;
    while (temp != NULL) {
        printf("thao tac ve %d : %s\n",++i,temp->action);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    Stack undoStack, redoStack;
    initStack(&undoStack);
    initStack(&redoStack);
    do {
        printf("== MENU ==\n");
        printf("1. Thuc hien thao tac ve \n");
        printf("2. UNDO \n");
        printf("3. REDO \n");
        printf("4. Hien thi \n");
        printf("5. Thoat\n");
        printf("Moi chon lua chon : ");
        scanf("%d",&choice);
        getchar();
        switch (choice) {
            case 1:
                char value[MAX_LENGTH];
                printf("Moi nhap thao tac ve : ");
                fgets(value,MAX_LENGTH,stdin);
                value[strcspn(value,"\n")] = '\0';
                push(&undoStack,value);
                break;
            case 2:
                undoToRedo(&undoStack,&redoStack);
                break;
            case 3:
                redoToUndo(&undoStack, &redoStack);
                break;
            case 4:
                printf("Undo \n");
                printStack(&undoStack);
                printf("Redo\n");
                printStack(&redoStack);
                break;
            case 5:
                printf("Da thoat chuong trinh \n");
                break;
            default:
                printf("Lua chon sai vui long nhap lai \n");
        }
    }while (choice != 5);

}
