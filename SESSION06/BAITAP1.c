//
// Created by DELL on 6/27/2025.
//
#include <stdio.h>
int recursion(int n) {
    // 1. điều kiện dừng
    if (n == 0) return 0;
    // 2. gọi lại hàm
    recursion(n/2);
    printf("%d",n%2);
}
int main() {
    int n;
    printf("Enter the number of digits you want to enter: ");
    scanf("%d", &n);
    recursion(n);
}