//
// Created by DELL on 7/1/2025.
//
#include <stdio.h>
int merge(int arr[], int left,int mid, int right) {
    int n1= mid-left+1;// so luong phan tu mang trai
    int n2= right-mid;// so luong phan tu mang phai
    // tao 2 mang chua 2 phan trai, phai
    int l[n1];
    int r[n2];
    // sao chep du lieu sang 2 mang
    for(int i=0;i<n1;i++) {
        l[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++) {
        r[j]=arr[mid+1+j];
    }
    // trộn 2 mảng thành mảng hoàn chỉnh
    int i=0,j=0;
    int k= left;
    while(i<n1 && j<n2) {
        if (l[i]<=r[j]) {
            arr[k]=l[i];
            k++;
            i++;
        }else {
            arr[k]=r[j];
            k++;
            j++;
        }
    }
    // sao chep phan tu con lai
    while(i<n1) {
        arr[k]=l[i];
        k++;
        i++;
    }
    while(j<n2) {
        arr[k]=r[j];
        k++;
        j++;
    }

}
// tao ham merge
int mergeSort(int arr[], int left, int right) {
    if (left <right) {
        int mid = (left+right)/2;
        // goi de quy sap xep tung phan
        mergeSort(arr, left, mid);// phan ben trai
        mergeSort(arr, mid+1, right);// phan ben phai
        // di gop 2 phan da sap xep
        merge(arr, left, mid, right);
    }
}
int main() {

    int arr[5] = {6, 4, 9,8, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}