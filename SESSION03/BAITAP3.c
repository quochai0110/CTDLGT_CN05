//
// Created by DELL on 6/20/2025.
//
#include <stdio.h>
#include <stdlib.h>
int main () {
    int n;
    printf("nhap vao so luong phan tu  (0 < n < 1000)");
    scanf("%d",&n);
    while (n<0 || n>1000) {
        printf("so luong phan tu khong hop le");
        printf("nhap vap so luong phan tu thoa man (0 < n < 1000)");
        scanf("%d",&n);
    };
    int *arr=(int*)malloc(n*sizeof(int));
    if (arr==NULL) {
        printf("cap phat khong thanh cong!");
        return 0;
    }

    for (int i=0; i<n; i++) {
        printf("nhap phan tu thu %d",i+1);
        scanf("%d",&arr[i]);
    }
    int sum=0;
    int count=0;
    for (int i=0; i<n; i++) {
        if (arr[i] % 2 == 0 ) {
            sum += arr[i];
            count++;
        }
    }
    if (count == 0) {
        printf("mang khong co phan tu chan");
        return 0;
    }
    int avg=sum/count;
    printf(" ket qua %d",avg);
    free(arr);

}