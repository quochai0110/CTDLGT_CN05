//
// Created by DELL on 6/27/2025.
//
#include <stdio.h>
int fibonacci(int n) {
    // 1. điều kiện dừng
    if (n==0) {
        return 0;
    }
    if (n==1) {
        return 1;
    }
    // 2. hàm tự gọi chính nó
    return fibonacci(n-1) + fibonacci(n-2);
}
int main() {
    // nhap n in ra n so trong day fibonaci
    int n;
    printf("nhap so luong n so fibonaci dau tien ");
    scanf("%d", &n);
    for (int i = n-1; i >=0 ; i--) {
       printf("%d ", fibonacci(i));
    }
}