//
// Created by DELL on 6/20/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    do {
        printf("Nhap so phan tu:");
        scanf("%d", &n);
        if (n==0 || n==-1) {
            printf("Nhap lai\n");
        }
    }while (n<=0 || n>1000);
    arr =(int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu:");
        scanf("%d", &arr[i]);
    }
    int max=arr[0];
    for (int i=1;i<n;i++) {
        if (arr[i]>max) {
            max=arr[i];
        }
    }
    printf("Phan tu lon nhat la:%d",max);
    free(arr);
    return 0;
}
