//
// Created by DELL on 6/17/2025.
//
#include <stdio.h>

int main(){
    int arr[6]={1,3,3,4,5};
    int check=0;
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++) {
        for(int j=i+1;j<size;j++) {
            if (arr[i]==arr[j]) {
                check=1;
            }
        }
    }
    if (check==1) {
        printf("mang co phan tu trung lap\n");
    }else {
        printf("mang khong co phan tu trung lap\n");
    }

}

