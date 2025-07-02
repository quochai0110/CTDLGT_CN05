//
// Created by DELL on 7/1/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[]={10, 5, 3, 9, 2};
  int n=sizeof(arr)/sizeof(arr[0]);
  int x;
  printf("nhap gia tri x: ");
  scanf("%d", &x);
  // bubble sort
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      int distance1=abs(arr[j]-x);
      int distance2=abs(arr[j+1]-x);
      // so sánh
      if (distance1>distance2 || distance1==distance2 && arr[j]>arr[j+1]) {
        int temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
