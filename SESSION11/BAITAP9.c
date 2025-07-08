//
// Created by DELL on 7/7/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
 }Node;
// xây dựng hàm thêm các node vào cuối
Node* insertAtTail(Node* head, int data) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = data;
 newNode->next = NULL;
 newNode->prev = NULL;
 // nếu danh sách không có phần tử nào
 if (head == NULL) {
  head = newNode;
  return head;
 }
 Node* temp = head;
 while (temp->next != NULL) {
  temp = temp->next;
 }
 temp->next = newNode;
 newNode->prev = temp;
 return head;
}
// xây dựng hàm đảo ngược liên kết các node
Node* reverse(Node* head) {
 Node* current=head;
 Node* temp = NULL;
 while (current != NULL) {
  // đổi 2 con trỏ prev và next của node hiện tại
  temp = current->prev;
  current->prev = current->next;
  current->next = temp;
  // di chuyển tăng ban đầu lên node tiếp
  current = current->prev;
 }
 if (temp!=NULL) {
  head = temp->prev;
 }
 return head;
}
// hàm hiển thị danh sách các node
void printfList(Node* head) {
  Node* temp= head;
 while (temp != NULL) {
  printf("%d <->", temp->data);
  temp = temp->next;
 }
 printf("NULL \n");
}
int main() {
 Node* head = NULL;
 head = insertAtTail(head, 1);
 head = insertAtTail(head, 2);
 head = insertAtTail(head, 3);
 head = insertAtTail(head, 4);
 printf("danh sach truoc khi dao: \n");
 printfList(head);
 head = reverse(head);
 printf("danh sach sau khi dao: \n");
 printfList(head);
}
