//
// Created by DELL on 6/20/2025
#include <stdio.h>
int main() {

    int arr[8]={1,2,5,3,3,5,1,5};
    int maxCount=0;
    int item;
    for(int i=0;i<8;i++) {
        int count=1;
        for(int j=i+1;j<8;j++) {
            if (arr[i]==arr[j]) {
                count++;
            }
        }
        if (count>maxCount) {
            maxCount=count;
            item=arr[i];
        }
    }
    printf("%d",item);
}