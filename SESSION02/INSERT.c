//
// Created by DELL on 6/17/2025.
//
#include <stdio.h>
void main() {
    int arr[10]={3,4,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    int post=2;
    // roi phan tu
    for(int i=size;i>post;i--) {
        arr[i]=arr[i-1];
    }
    // them gia tri
    arr[post]=5;
    // in ket qua
    for(int i=0;i<5;i++) {
        printf("%d",arr[i]);
    }

}
