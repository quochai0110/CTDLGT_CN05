#include <stdio.h>

int main() {
    int n;
    printf("so luong phan tu: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int checkNum;
    printf("so ban muon tim: ");
    scanf("%d", &checkNum);
    for (int i = 0; i < n; i++) {
        if (checkNum == arr[i]) {
            printf("vi tri so ban muon tim xuat hien dau tien trong mang: %d", i);
            return 0;
        }
    }
        printf("khong ton tai");
    return 0;
}