//
// Created by DELL on 6/26/2025.
//
#include <stdio.h>
#include <string.h>

int isPalin(char str[], int left, int right) {
    // điều kiện dừng
    if (left > right) {
        return 1;
    }
    if (str[left] != str[right]) {
        return 0;
    }
    return isPalin(str, left+1, right-1);

}
int main() {

    // Bước 1: cho người dùng nhập string
    char str[50];
    printf("moi nhap string: ");
    fgets(str, 50, stdin);
    str[strlen(str)-1] = '\0';
    int len = strlen(str);
    int result= isPalin(str, 0, len-1);
    if (result == 1) {
        printf("doi xung");
    }else {
        printf("khong doi xung");
    }

}
