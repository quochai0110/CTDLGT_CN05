#include <stdio.h>
int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu cua mang: ");
        scanf("%d", &arr[i]);
    }
    int findNumber;
    printf("Hay nhap phan tu can tim kiem");
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (findNumber == arr[i]) {
            index = i;
        }
    }
    if (index == -1) {
        printf("Khong co phan tu can tim kiem!\n");
    }else {
        printf("%d",index);
    }
}