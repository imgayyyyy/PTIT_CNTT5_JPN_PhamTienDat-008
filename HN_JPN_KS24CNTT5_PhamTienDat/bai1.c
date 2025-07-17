#include<Stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[20];
    bool status;
    int avg;
}Student;

typedef struct Node {
    Student data;
    struct Node *next;
    struct Node *prev;
}Node;
typedef struct {
    Student students[MAX_STUDENTS];
    int size;
} StudentArray;

typedef struct {
    Node* head;
    Node* tail;
} DoublyLinkedList;

void initArray(StudentArray* arr) {
    arr->size = 0;
}

void initList(DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}


void addSv(StudentArray* arr, int id, char* name, bool status, int avg) {
    if (arr->size < MAX_STUDENTS) {
        arr->students[arr->size].id = id;
        strcpy(arr->students[arr->size].name, name);
        arr->students[arr->size].status = status;
        arr->students[arr->size].avg = avg;
        arr->size++;
    }
}
void addToInactiveList(DoublyLinkedList* list, Student student) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = student;
    newNode->next = NULL;

    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void showSv(StudentArray* arr, DoublyLinkedList* inactiveList) {
    printf("\nsv dang hoat dong:\n");
    for (int i = 0; i < arr->size; i++) {
        if (arr->students[i].status) {
            printf("ID: %d, Name: %s, Status: hoat dong, diem: %d\n",
                   arr->students[i].id,
                   arr->students[i].name,
                   arr->students[i].avg
                   );
        }
    }

    printf("\nsinh vien khong hoat dong:\n");
    Node* current = inactiveList->head;
    while (current != NULL) {
        printf("ID: %d, Name: %s, Status: khong hoat dong, diem: %d\n",
               current->data.id,
               current->data.name,
               current->data.avg);

        current = current->next;
    }
}

void deleteSv(StudentArray* arr, int id) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->students[i].id == id) {
            for (int j = i; j < arr->size - 1; j++) {
                arr->students[j] = arr->students[j + 1];
            }
            arr->size--;
            break;
        }
    }
}


void updateSv(StudentArray* arr, int id, char* name, int avg) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->students[i].id == id) {
            strcpy(arr->students[i].name, name);
            arr->students[i].avg = avg;
            break;
        }
    }
}



void changeStatusSv(){
}



void sapXepSv(){
}



void searchSv(){

}




int main(){
    StudentArray arr;
    DoublyLinkedList inactiveList;
    initArray(&arr);
    initList(&inactiveList);
    int choice,id,avg,status;
    char name[20];
    while(1){
        printf("\n___________STUDENT MANAGER____________\n");
        printf("\n1.add sv");
        printf("\n2.show sv");
        printf("\n3.delete sv");
        printf("\n4.update sv");
        printf("\n5.change status sv");
        printf("\n6.sap xep sv");
        printf("\n7.search sv");
        printf("\n8.exit");
        printf("\nnhap lua chon: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("ID: ");
                scanf("%d", &id);
                getchar();
                printf("name: ");
                // scanf(" %[]", name);
                fgets(name, 20, stdin);
                printf("trang thai (1-hoat dong, 0-khong hoat dong): ");
                scanf("%d", &status);
                printf("nhap diem: ");
                scanf("%d", &avg);
                addSv(&arr, id, name, status, avg);
                if (!status) {
                    Student newStudent = {id, "", false, avg};
                    strcpy(newStudent.name, name);
                    addToInactiveList(&inactiveList, newStudent);
                }
                break;
            case 2:
                showSv(&arr, &inactiveList);
                break;
            case 3:
                printf("nhap id: ");
                scanf("%d", &id);
                deleteSv(&arr, id);
                break;
            case 4:
                printf("nhap id: ");
                scanf("%d", &id);
                printf("ten moi: ");
                scanf(" %[^\n]", name);
                printf("diem moi: ");
                scanf("%d", &avg);
                updateSv(&arr, id, name, avg);
                break;
            case 5:

                break;
            case 6:
                sapXepSv();
                break;
            case 7:
                printf("Enter ID to search: ");
                scanf("%d", &id);

                break;
            case 8:
                printf("thoat chuong trinh");
                return 0;
            default:
                printf("khong hop le, vui long chon lai");
        }
    }

}