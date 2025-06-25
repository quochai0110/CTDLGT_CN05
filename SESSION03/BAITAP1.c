//
// Created by DELL on 6/20/2025.
//
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n ;
    do {
        printf(" Nhap so luong phan tu ");
        scanf("%d",&n);
    }while (n<0 || n>1000 );
   int *arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu bat ki ");
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    free(arr);
}
