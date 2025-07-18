//
// Created by DELL on 7/18/2025.
// BAI1:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// BƯỚC 1: TẠO CẤU TRÚC
//  CẤU TRÚC CỦA 1 DỰ ÁN
typedef struct Project {
    int id; // mã dự án
    char title[100]; // tên dự án
    char owner[100]; // tên quản lý dự án
    int priority; // độ ưu tiên của dự án
} Project;

// CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN
typedef struct SNode {
    // singly linked list _ danh sách liên kết đơn
    Project data;
    struct SNode *next; // con trỏ next để lưu địa chỉ phần tử tiếp theo
} SNode;

// CẤU TRÚC DANH SÁCH LIÊN KẾT ĐÔI
typedef struct DNode {
    // doubly linked list _ danh sách liên kết đôi
    Project data;
    struct DNode *next;
    struct DNode *prev;
} DNode;

// BƯỚC 2: TẠO CAC HÀM CHỨC NĂNG
//. TẠO HÀM THÊM DỰ ÁN MỚI
int nextId = 1;

SNode *addProject(SNode *head) {
    Project project; // tạo 1 BIẾN công việc có kiểu dữ liệu là Project
    project.id = nextId++;
    printf("moi nhap ten du an:");
    fgets(project.title, 100,stdin);
    project.title[strlen(project.title) - 1] = '\0'; // bỏ ký tự \n
    printf("moi quan ly du an:");
    fgets(project.owner, 100,stdin);
    project.owner[strlen(project.owner) - 1] = '\0';
    printf("moi nhap do uu tien du an:");
    scanf("%d", &project.priority);
    getchar();
    // tạo ô nhớ
    SNode *newNode = (SNode *) malloc(sizeof(SNode));
    newNode->data = project;
    newNode->next = head;
    head = newNode;
    return head;
}

// HÀM IN DANH SÁCH DỰ ÁN
void printProject(SNode *head) {
    SNode *temp = head;
    while (temp != NULL) {
        printf("Ma du an: %d| Ten du an: %s | Ten quan ly %s|"
               " Do uu tien %d \n", temp->data.id, temp->data.title, temp->data.owner, temp->data.priority);
        temp = temp->next;
    }
}

// HÀM XÓA DỰ ÁN
SNode *delProject(SNode *head, int id) {
    SNode *temp = head;
    SNode *prev = NULL; // tạo con trỏ , trỏ đến nút trước nút cần xóa
    while (temp != NULL) {
        if (temp->data.id == id) {
            // CÓ PHẦN TỬ TRÙNG ID
            // sảy ra 2 trường hợp: 1 phần tử đầu tiên, 2 phần tử xóa không phải đầu
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// TẠO HÀM CẬP NHẬT DỰ ÁN
void updateProject(SNode *head, int id) {
    SNode *temp = head;
    int check = 0;
    while (temp != NULL) {
        if (temp->data.id == id) {
            check = 1;
            // cập nhật
            temp->data.id = id; // lưu lại id ban đầu
            printf("nhap ten du an moi:");
            fgets(temp->data.title, 100, stdin);
            temp->data.title[strlen(temp->data.title) - 1] = '\0';
            printf("nhap quan ly du an moi:");
            fgets(temp->data.owner, 100, stdin);
            temp->data.owner[strlen(temp->data.owner) - 1] = '\0';
            printf("nhap do uu tien moi:");
            scanf("%d", &temp->data.priority);
            getchar();
        }
        temp = temp->next;
    }
    if (!check) {
        printf("khong co du an co id la: %d \n", id);
    }
}

// BƯỚC 3: TRIỂN KHAI CÁC HÀM TRONG MAIN

int main() {
    int choice;
    SNode *sHead = NULL; // khởi tạo node đầu tiên trong DSLK_Đơn = NULL
    DNode *dHead = NULL; // khởi tạo node đầu tiên trong DSLK_Đôi =NULL

    do {
        printf("MENU:\n");
        printf("1. Them du an\n");
        printf("2. Hien thi thong tin tung du an!\n");
        printf("3. Xoa du an\n");
        printf("4. Cap nhat du an\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1: {
                // đi gọi hàm thêm mới 1 dự án
                sHead = addProject(sHead);
                break;
            }
            case 2: {
                printProject(sHead);
                break;
            }
            case 3: {
                int id;
                printf("Nhap ID du an can xoa: ");
                scanf("%d", &id);
                getchar();
                sHead = delProject(sHead, id);
                break;
            }
            case 4: {
                int idUpdate;
                printf("Nhap ID du an can cap nhat: ");
                scanf("%d", &idUpdate);
                getchar();
                updateProject(sHead, idUpdate);

                break;
            }
        }
    } while (choice != 8);
}
