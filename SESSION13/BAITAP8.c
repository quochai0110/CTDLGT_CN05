//
// Created by DELL on 7/10/2025.
//
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX 100
// B2: KHAI BÁO NGĂN XẾP

typedef struct {
    int data[MAX];
    int top;
}Stack;

// B3: KHỞI TẠO NGĂN XẾP
void initStack(Stack *s) {
    s->top = -1;
}

// B4: Tạo hàm thêm phần tử vào ngăn xếp
void pushElement(Stack* s, int value) {
    // kiểm tra xem ngăn xếp đầy hay chưa
    if (s->top == MAX - 1) {
        printf("Ngan xep da day\n");
        return;
    }
    s->data[++s->top] = value;
}
// B5: Tạo hàm xóa phần tử khỏi ngăn xếp
int popElement(Stack *s) {
    // kiểm tra ngăn xếp có rỗng hay không
    if (s->top == -1) {
        return 0;
    }
    return s->data[s->top--];
}
// B6: Tạo hàm tính toán biểu thức
int postFix(char* str) {
    Stack s;
    initStack(&s);
    // duyệt từng ký tự trong biểu thức
    for (int i = 0;str[i]!='\0'; i++) {
        char c = str[i];// lấy từng ký tự
        // nếu là ký tự số thì push vào ngăn xếp
        if (isdigit(c)) {
            pushElement(&s, c-'0');// chuyển từ kiểu char sang kiểu int
        }else if (c=='+'||c=='-'||c=='*'||c=='/') {
            // nếu không phải toán hạng gặp toán tử thì pop ra
            int op2 = popElement(&s); // lấy toán hạng sau
            int op1 = popElement(&s); // lấy toán hạng trước
            int result;
            if (c=='+') {
                result = op1 + op2;
            }else if (c=='-') {
                result = op1 - op2;
            }else if (c=='*') {
                result = op1 * op2;
            }else if (c=='/') {
                result = op1 / op2;
            }
            pushElement(&s, result);
        }
    }
    return popElement(&s);
}
int main() {
    //B1: 24+46+*
    char str[100];
    printf("Moi nhap bieu thuc hau to");
    fgets(str,100,stdin);
    str[strlen(str)-1]='\0';// xóa ký tự enter
    int result= postFix(str);
    printf("%d", result);
}
