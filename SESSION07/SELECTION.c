//
// Created by DELL on 6/30/2025.
//
#include <stdio.h>
int main() {

    int arr[6]={11,2,31,14,25,26};
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i++) {
        int minIndex=i;
        for(int j=i+1;j<n;j++) {
            if (arr[j]<arr[minIndex]) {
                minIndex=j;
            }
        }
        if (minIndex!=i) {
            int temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }
    }
    for(int i=0;i<n;i++) {
        printf("%d \n ",arr[i]);
    }
}
