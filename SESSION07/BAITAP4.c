//
// Created by DELL on 6/30/2025.
//
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int sortCharacter(char str[]) {
    int len = strlen(str);
    // sap xep dùng bubble sort
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-i-1; j++) {
            if (str[j] > str[j+1]) {
                char temp =str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}
int main() {
    char str[100];
    printf("nhap vao chuoi bat ki ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    sortCharacter(str);
    printf(" chuoi sau khi da duoc sap xep: %s\n", str);


}
