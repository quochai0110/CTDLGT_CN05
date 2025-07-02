//
// Created by DELL on 6/30/2025.
//
#include <stdio.h>
void tower(int n, char cotNguon, char cotTrungGian, char cotDich) {
    // 1. điều kiện dừng
    if(n==1) {
        printf("di chuyen dia 1 tu cot %c sang cot %c \n", cotNguon, cotDich);
        return ;
    }
    // can di chuyen n-1 dia tu cot nguon sang cot trung gian
    tower(n-1, cotNguon, cotDich, cotTrungGian);
    // 2. gọi lại chính nó
    printf("di chuyen dia %d tu coc %c sang coc %c \n", n,cotNguon,cotDich);
    // can di chuyen n-1 dia tu cot trung gian sang cot dich
    tower(n-1,cotTrungGian, cotNguon, cotDich);

}
int main() {
 // buoc 1: yeu cau nguoi dung nhap vao so dia
    int n;
    do {
        printf("nhap so dia: ");
        scanf("%d", &n);
    }while (n<1 || n>100);// so dia gioi han tu 1 cho den 100
    tower(n,'A','B','C');


}
