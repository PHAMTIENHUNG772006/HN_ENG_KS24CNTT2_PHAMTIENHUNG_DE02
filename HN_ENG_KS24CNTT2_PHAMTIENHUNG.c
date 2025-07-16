#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct Activety {
    int id;
    char Type[100];
    int Duration;
    int Calories;
    char Date[20];
}Activety;
typedef struct SNode {
    Activety data;
    struct  SNode* next;
}SNode;

SNode* head = NULL;



int checkId(SNode* head,int index) {
    SNode* temp = head;
    while (temp != NULL) {
        if (temp->data.id == index) {
            printf("ID da xua hien vui long nhap id khac \n");
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void insertActivety() {
    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    if (newNode == NULL) {
        printf("khong the cap phat bo nho \n");
        return;
    }
    int n;
    printf("Moi nhap so luong hoat dong trong ngay : ");
    scanf("%d",&n);
    getchar();
    for (int i=0;i<n;i++) {
        do {
            printf("Moi nhap ID :");
            scanf("%d",&newNode->data.id);
            getchar();
        }while (checkId(head,newNode->data.id) == -1);
        printf("Moi nhap kieu hoat dong : ");
        fgets(newNode->data.Type,100,stdin);
        newNode->data.Type[strcspn(newNode->data.Type, "\n")] = '\0';
        printf("Moi nhap thoi gian thuc hien : ");
        scanf("%d",&newNode->data.Duration);
        getchar();
        printf("Moi nhap luong calo tieu thu : ");
        scanf("%d",&newNode->data.Calories);
        getchar();
        printf("Moi nhap thoi gian thu hien hanh dong : ");
        fgets(newNode->data.Date,100,stdin);
        newNode->data.Date[strcspn(newNode->data.Date, "\n")] = '\0';
        newNode->next = head;
        head = newNode;
        printf("them hoat dong thanh cong \n");
    }
}

void deleteActivety(int id) {
    if (head == NULL) {
        printf("khong co sach nao trong danh sach \n");
        return;
    }
    SNode* current = head;
    SNode* prev = NULL;
    while (current != NULL) {
        if (current->data.id == id) {
            if (prev == NULL) {
                head = current->next;
            }else {
                prev->next = current->next;
            }
            free(current);
            printf("Xoa hoat dong thanh cong \n");
        }
        current = current->next;
    }
}

void printListActivety() {
    SNode* temp = head;
    if (temp == NULL) {
        printf("Khong co phan tu nao trong ds \n");
        return;
    }
    printf("Danh sach khoa hoc : \n");
    while (temp != NULL) {
        printf(" ID : %d, Type : %s, Duration : %d, CALORIES : %d, DATE : %s \n ",temp->data.id,temp->data.Type,temp->data.Duration,temp->data.Calories,temp->data.Date);
        temp = temp->next;
    }
    printf("\n");
}

void editActivety() {
    if (head == NULL) {
        printf("khong co sach nao trong danh sach \n");
        return;
    }
    SNode* current = head;
    int id;
    printf("nhap ID khoa hoc can sua : ");
    scanf("%d",&id);
    getchar();
    while (current != NULL) {
        if (current->data.id == id) {
            printf("Moi nhap kieu hoat dong : ");
            fgets(current->data.Type,100,stdin);
            current->data.Type[strcspn(current->data.Type, "\n")] = '\0';
            printf("Moi nhap thoi gian thuc hien : ");
            scanf("%d",&current->data.Duration);
            getchar();
            printf("Moi nhap luong calo tieu thu : ");
            scanf("%d",&current->data.Calories);
            getchar();
            printf("Moi nhap thoi gian thu hien hanh dong : ");
            fgets(current->data.Date,100,stdin);
            current->data.Date[strcspn(current->data.Date, "\n")] = '\0';
            printf("Cap nhat sach thanh cong \n");
            return;
        }
        current = current->next;
    }
}



int SelectionSort() {
    SNode* i,*j;
    SNode* min;
    for (i = head ; i != NULL ; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            min = i;
            if (j->data.Calories > min->data.Calories) {
                min->data.Calories = j->data.Calories;
            }
            Activety temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }
}

void findActivety() {
    char value[20];
    printf("Moi nhap hoat dong can tim : ");
    fgets(value,100,stdin);
    value[strcspn(value, "\n")] = '\0';
    SNode* temp = head;
    int flag = 0;
    while (temp != NULL) {
        if (strstr(temp->data.Type,value) != NULL) {
            printf("khoa hoat dong tim thay \n");
            printf(" ID : %d, Type : %s, Duration : %d, CALORIES : %d, DATE : %s \n ",temp->data.id,temp->data.Type,temp->data.Duration,temp->data.Calories,temp->data.Date);
            flag = 1;
        }
        temp = temp->next;
    }
    if (flag == 0) {
        printf("khong tim thay hoat dong \n");
    }
}
int main() {
    int choice;
    do {
        printf("===MENU=== \n");
        printf("1.Them hoat dong \n");
        printf("2.Hien thi danh dach hoat dong \n");
        printf("3.Xoa hoat dong \n");
        printf("4.Cap nhat thong tin hoat dong \n");
        printf("5.Thong ke tong calo tieu thu trong ngay\n");
        printf("6.Sap xep hoat dong\n");
        printf("7.Tim kiem hoat dong theo kieu\n");
        printf("8.Thoat\n");
        printf("Moi ban nhap lua chon : ");
        scanf("%d",&choice);
        getchar();
        switch (choice) {
            case 1:
                insertActivety();
                break;
            case 2:
                printListActivety();
                break;
            case 3:
                int x;
                printf("Nhap id khoa hoc can xoa : ");
                scanf("%d",&x);
                deleteActivety(x);
                break;
            case 4:
                editActivety();
                break;
            case 5:

                break;
            case 6:
                SelectionSort();
                printListActivety();
                break;
            case 7:
                findActivety();
                break;
            case 8:
                printf("Da thoat chuong trinh..! \n");
                break;
            default:
                printf("lua chon khong hop le ,vui long nhap lai \n");
                break;
        }

    }while (choice != 8);
}
