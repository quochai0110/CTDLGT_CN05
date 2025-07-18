//
// Created by DELL on 7/11/2025.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CẤU TRÚC 1 KHÓA HỌC
typedef struct {
    int id;
    char title[50];
    int credit;
} Course;

// CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN
typedef struct SNode {
    Course course;
    int data;
    struct SNode *next;
} SNode;

// CẤU TRÚC DANH DÁCH LIÊN KẾT ĐÔI
typedef struct DNode {
    Course course;
    struct DNode *next;
    struct DNode *prev;
} DNode;

SNode *head = NULL;
// TẠO HÀM KIỂM TRA ID KHÔNG ĐƯỢC TRÙNG
int checkId(int id) {
    // Duyệt từng node trong danh sách liên kết đơn, đi kiểm tra với id người dùng nhập
    SNode *temp = head;
    while (temp != NULL) {
        if (temp->course.id == id) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// HÀM ĐI THÊM KHÓA HOC
void addCourse() {
    Course courseValue;
    // Nhập id ==> chú ý phải kiểm tra id không được phép trùng
    do {
        printf("nhap ID: ");
        scanf("%d", &courseValue.id);
    } while (checkId(courseValue.id));
    // loại bộ nhớ đệm
    getchar();

    // Nhập tên
    printf("nhap ten khoa hoc: ");
    fgets(courseValue.title, 50, stdin);
    // LOẠI BỎ \n
    courseValue.title[strlen(courseValue.title) - 1] = '\0';
    // Số tín chỉ của khóa học
    printf("nhap so tin chi ");
    scanf("%d", &courseValue.credit);
    // KHỞI TẠO VÙNG NHỚ CHO 1 NODE
    SNode *newNode = (SNode *) malloc(sizeof(SNode));
    if (newNode == NULL) {
        printf("cap phat o nho khong thanh cong");
        return;
    }
    newNode->course = courseValue;
    newNode->next = head;
    head = newNode;
    printf("Them khoa hoc thanh cong: ");
}

// HÀM HIỂN THỊ DANH SÁCH KHÓA HỌC
void displayCourse() {
    SNode *temp = head;
    while (temp != NULL) {
        printf("ID: %d  | Ten: %s | Tin Chi %d \n", temp->course.id, temp->course.title, temp->course.credit);
        temp = temp->next;
    }
}

int main() {
    int choice;
    do {
        printf("MENU \n");
        printf(
            "1. Them khoa hoc\n 2. Hien thi danh sach khoa hoc\n 3. Xoa\n 4. Cap nhat khoa hoc\n 5. Danh dau khoa hoc da hoan thanh\n 6. Sap xep\n 7. Tim kiem\n 8. Thoat ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("chuc nang them khoa hoc \n");
                // TẠO HÀM THÊM KHÓA HỌC, ĐI GỌI HÀM
                addCourse();
                break;
            }
            case 2: {
                // HIỂN THỊ DANH SÁCH KHÓA HỌC
                displayCourse();

                break;
            }
            default: {
                printf("lua chon khong hop le!\n");
            }
        }
    } while (choice != 8);
}
