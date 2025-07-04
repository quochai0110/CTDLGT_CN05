//
// Created by DELL on 7/3/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;
// tạo hàm thêm phần tử vào danh sách liên kết
Node* insertAtTail(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        // không đủ bộ nhớ
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    // lấy được ông temp là phần tử cuối cùng
    temp->next = newNode;
    return head;
}

// tạo hàm hiển thị
void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}
// tạo hàm đảo ngược
Node* reverseList(Node* head) {
    Node* pre = NULL;
    Node* curr = head;
    Node* nextNode;
    while(curr != NULL) {
        nextNode = curr->next;// ghi nhớ node tiếp theo
        curr->next = pre; // đảo liên kết
        // phải dời pre và curr tăng lên 1 bước
        pre = curr;
        curr = nextNode;
    }
    return pre;// pre sẽ là node đầu sau khi đảo liên kết
}
int main() {

    // tạo danh sách liên kết đơn 1->2->3->4->5->NULL;

    // khởi tạo biến con trỏ kiểu Node
     Node *head = NULL;
     head = insertAtTail(head, 1);
     head = insertAtTail(head, 2);
     head = insertAtTail(head, 3);
     head = insertAtTail(head, 4);
     head = insertAtTail(head, 5);
     head = reverseList(head);
    // hiển thị
    display(head);
}