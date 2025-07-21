//
// Created by DELL on 7/21/2025.
//DFS_ DUYỆT THEO CHIỀU SÂU  CÓ 3 CÁCH

#include <stdio.h>
#include <stdlib.h>

// BƯỚC 1:  CẤU TRÚC 1 NODE TRONG CÂY
typedef struct Student {
    int id;
    char name[20];
    char address[50];
} Student;

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// BƯỚC 2: HÀM TẠO NODE MỚI
Node *createNode(int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("cap phat o nho khong thanh cong!");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// BƯỚC 3: TRIỂN KHAI DFS THEO 3 CÁCH
// CÁCH 1: INORDER (LEFT_NODE_RIGHT)
void inorder(Node *root) {
    // dùng hàm đệ quy để duyệt
    // điều kiện dừng của hàm
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}
// CÁCH 2: PREORDER( NODE_LEFT_RIGHT)
void preorder(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}
// CÁCH 3: POST_ORDER LEFT_RIGHT_NODE
void postorder(Node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}

// BƯỚC 4: TẠO CÂY VÀ TRIỂN KHAI TRONG MAIN
int main() {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Duyet cay theo inorder \n");
    // inorder(root);
    preorder(root);
}
