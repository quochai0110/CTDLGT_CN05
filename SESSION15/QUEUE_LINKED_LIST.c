//
// Created by DELL on 7/10/2025.
// TRIỂN KHAI HÀNG ĐỢI SỬ DỤNG DANH SÁCH LIÊN KẾT ĐƠN
#include <stdio.h>
#include <stdlib.h>

// BƯỚC 1: KHAI BÁO CẤU TRÚC 2 cấu trúc
typedef struct Node {
    int data;
    struct Node* next;
}Node;
typedef struct {
    Node* front;
    Node* rear;
}Queue;
// BƯỚC 2: KHOI TẠO HÀNG ĐỢI
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}
// BƯỚC 3: THÊM PHẦN TỬ VÀO
void enQueue(Queue* queue, int data) {
    // cấp phát ô nhớ
    Node* newNode = (Node*)malloc(sizeof(Node));
    // kiểm tra xem cấp phát có thành công hay không?
    if (newNode == NULL) {
        printf("cap phat o nho khong thanh cong");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    // khi cấp phát thành công
    // kiểm tra nếu đầu tiên hàng đợi không có phần tử nào thì rear và front sẽ là newNode
    if (queue->front == NULL) {
        // chứng tỏ hàng đợi chưa có phan tử nào
        queue->front = newNode;
        queue->rear = newNode;
    }else {
        // trong hàng đợi đã có phần tử
        queue->rear->next = newNode;// liên kết phần tử cuối với phần tử mới thêm vào
        // cập nhật rear là phần tử cuối cùng( newNode)
        queue->rear = newNode;
    }

}
// BƯỚC 4: TẠO HÀM XÓA PHẦN TỬ
int deQueue(Queue* queue) {
    // kiểm tra hàng đợi có phần tử thì mới xóa
    if (queue->front == NULL) {
        printf("hang doi khong co phan tu nao");
        return -1;
    }
    Node* temp = queue->front;
    // trả về giá trị phần tử muốn xóa
    int value = temp->data;
    // gán front bằng phần tử  tiếp theo
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        // tức la hàng đợi không còn phần tử nào thì phải cập nhật rear về NULL
        queue->rear = NULL;
    }
    free(temp);
    return value;
}
// BƯỚC 5: TẠO HÀM HIỂN THỊ CÁC PHẦN TỬ TRONG HÀNG ĐỢI
void displayQueue(Queue* queue) {
    if (queue->front == NULL) {
        // chứng tỏ hàng đợi không có phần tử
        printf("hang doi rong");
        return;
    }
    Node* temp = queue->front;// trỏ đến phần tử đầu tiên
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }

}
int main() {
    //
    Queue queue;// tạo 1 biến queue kiểu dữ liệu kiểu Queue
    initQueue(&queue);
    // thêm phần tử vào hàng đợi
    enQueue(&queue, 1);
    enQueue(&queue, 2);
    enQueue(&queue, 3);
    enQueue(&queue, 4);
    enQueue(&queue, 5);
    deQueue(&queue);
    displayQueue(&queue);
}
