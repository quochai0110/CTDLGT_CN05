//
// Created by DELL on 6/25/2025.
//
#include <stdio.h>
#include <string.h>

int main() {
    // buoc 1:
    struct SinhVien {
        int id;
        char name[50];
        int age;
    };
    // buoc 2:
    struct SinhVien sinhvien[3];
    // buoc 3:
    for (int i = 0; i < 3; i++) {
        printf("nhap id:");//1 enter(\n)
        scanf("%d", &sinhvien[i].id);
        getchar();
        printf("nhap name:");
        fgets(sinhvien[i].name, 50, stdin);
        sinhvien[i].name[strlen(sinhvien[i].name) - 1] = '\0';
        printf("nhap age:");
        scanf("%d", &sinhvien[i].age);
    }
    int id;
    printf("nhap id:");
    scanf("%d", &id);
    for (int i = 0; i < 3; i++) {
        if (sinhvien[i].id == id) {
            printf("%s %d \n", sinhvien[i].name, sinhvien[i].age);
            return 0;
        }
    }
    printf("khong tim thay");

}
