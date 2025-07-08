//
// Created by DELL on 7/8/2025.
//
#include <stdio.h>
#define MAX 100
 // KHAI BÁO CẤU TRÚC NGAN XẾP VỚI MẢNG
typedef  struct {
 int data[MAX];// 1 mảng chứa dữ liệu (tối đa 100 phần tử)
 int top; // lưu chỉ số phần tử đỉnh của ngăn xếp
} Stack ;

// KHỞI TẠO NGĂN XẾP
void initStack(Stack* s) {
 s->top = -1;// ngăn xếp chưa có phần tử nào thì gán top =-1
}
// TẠO HÀM KIỂM TRA XEM NGĂN XẾP ĐÃ ĐẦY HAY CHƯA
int isFull(Stack* s) {
  return s->top == MAX - 1;
 // khi đầy: 1
 // chưa đầy: 0
}
// THÊM PHẦN TỬ VÀO TRONG NGAN XẾP
void push(Stack* s, int x) {
 // trước khi thêm phải kiểm tra xem ngan xếp đã đầy hay chưa
 if (isFull(s)) {
  printf("Stack is full\n");
 }else {
  // chưa đầy
  // int temp= s->top + 1;
  s->data[++s->top]=x;
 }
}

// HÀM KIỂM TRA NGĂN XẾP CÓ RỖNG HAY KHÔNG
int isEmpty(Stack* s) {
 return s->top == -1;
 // 1: thì rỗng
 // 0: thì có phần tử
}
// XÓA PHẦN TỬ TRONG NGĂN XẾP
int pop(Stack* s) {
 // trước khi xóa phần tử, kiểm tra ngăn xếp có trống hay không
 if (isEmpty(s)) {
  printf("Stack is empty\n");
  return -1;
 }
 // trả về phần tử bị xóa, sau đó giảm top đi 1
 return s->data[s->top--];
}

// HIỂN THỊ PHẦN TỬ ĐỈNH CỦA NGĂN XẾP
int top(Stack* s) {
 if (isEmpty(s)) {
  printf("Stack is empty\n");
  return -1;
 }
 return s->data[s->top];
}
// HIỂN THỊ PHẦN TỬ TRONG NGĂN XẾP

void printStack(Stack* s) {
 // kiểm tra danh sách có phần tử thì mới in, tức là không rỗng
 if (isEmpty(s)) {
  printf("Stack is empty\n");
 }else {
  // có phần tử-> hiển thị
  for (int i=s->top; i>=0; i--) {
   printf("%d\n", s->data[i]);
  }
 }
}
int main() {
 Stack s;
 initStack(&s);
 push(&s, 4);
 push(&s, 6);
 push(&s, 8);
 // printStack(&s);
 // printf("phan tu dinh vua xoa la: %d\n", pop(&s));
  // printStack(&s);
 printf("phan tu dinh cua ngan xep la: %d",top(&s));
}
