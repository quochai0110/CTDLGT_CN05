//
// Created by DELL on 7/23/2025.
//
#include <stdio.h>
#include <stdlib.h>
// DANH SÁCH KỀ : Ý TƯỞNG MỖI ĐỈNH SẼ LÀ 1 DANH SÁCH LIÊN SÁCH VỚI CÁC ĐỈNH KHÁC

// TẠO CẤU TRÚC 1 NODE
typedef  struct Node {

    int data;
    struct Node* next;
}Node;
Node* adjacency[4];
// VIẾT HÀM TẠO NODE
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
// TẠO MẢNG CHỨA DANH SÁCH CÁC CON TRỎ TRỎ TỚI TỪNG ĐỈNH

// VIẾT HÀM TẠO LIÊN KẾT
Node* addAdjacency(int U,int V) {
    // TẠO 1 NỐT MỚI, THÊM VÀO ĐẦU
    Node* newNode = createNode(U);
    // ĐI LIÊN KẾT VỚI PHẦN TỬ BAN ĐẦU
    newNode->next = adjacency[V];
    adjacency[V]=newNode;// NEWNODE lúc này sẽ là phần tử đầu

    newNode= createNode(V);
    newNode->next = adjacency[U];// LIÊN KẾT VỚI PHẦN TỬ BAN ĐẦU
    adjacency[U]=newNode; // newNode bây giờ sẽ thanh phần tu đầu tiên
}
// HÀM hiển thị liên kết các điểm
void printAdjacency() {
    for (int i=0; i<4; i++) {
        Node* current= adjacency[i];
        printf("dinh thu %d:",i);
        while (current != NULL) {
            printf("%d ", current->data);
            current= current->next;
        }
        printf("\n");
    }
}
int main() {
    // khởi tạo cac gia tri trong mảng về NULL
    for (int i = 0; i < 4; i++) {
        adjacency[i] = NULL;
    }
    addAdjacency(0,1);
    addAdjacency(1,2);
    printAdjacency();
}
