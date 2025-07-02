#include <stdio.h>
#include <stdlib.h>
//
// Created by DELL on 7/2/2025.
//
typedef struct Node {
    int data;
    struct Node* next;
}Node;
// Tạo hàm thêm Node vào đầu danh sách
Node* insertAtHead(Node* head, int value) {
    // tạo con trỏ cấp phát bộ nhớ
    Node* newNode = (Node*)malloc(sizeof(Node));
    // gán giá trị cho newNode
    newNode->data = value;
    newNode->next = head;
    return newNode;
}
void printfList(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
// Tạo hàm thêm vào cuối
Node* insertAtTail(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        // trong trường hợp danh sách không có phần tử nào
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        // duyet tu dau den phan tu cuoi
        current = current->next;
    }
    current->next = newNode;
    return head;
}
// tạo hàm thêm vào vị trí bất kì
Node* insertAtPosition(Node* head, int position, int value) {
    if (position <0) {
        printf("vi tri khong hop le\n");
        return head;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    int index=0;
    while (index<position-1 && current!= NULL) {
        current = current->next;
        index++;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}
int main(void) {
   // tạo biến con trỏ có kiểu dữ liệu Node gán giá trị là null
    Node* head = NULL;
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 30);
    // printfList(head);// 30 20 10
    insertAtTail(head, 40);
    // printfList(head); // 30 20 10 40 thêm vào vị trí 2 giá trị 50 : 30 20 50 10 40
    // sau khi thêm xong hiển thị
    insertAtPosition(head,2,50);
    printfList(head);
}
