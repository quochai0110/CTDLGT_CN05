//
// Created by DELL on 7/1/2025.
//
#include <stdio.h>
int main() {
    int arr[]={1, 14, 21, 7, 5, 8, 3, 6}; // 2 4 6 8 7 5 3 1
    int n=sizeof(arr)/sizeof(arr[0]);
    // B1: đi đếm số lượng phần tử chẵn và lẻ
    int evenCount=0;
    int oddCount=0;
    for(int i=0;i<n;i++) {
        if(arr[i]%2==0) {
            evenCount++;
        }else {
            oddCount++;
        }
    }
    int even[evenCount];
    int m=0;
    int k=0;
    int odd[oddCount];
    for(int i=0;i<n;i++) {
        if(arr[i]%2==0) {
            even[m]=arr[i];
            m++;
        }
    }
    for(int i=0;i<n;i++) {
        if(arr[i]%2!=0) {
            odd[k]=arr[i];
            k++;
        }
    }
    // buoc 3: tiến hành sắp xếp
    for(int i=0;i<evenCount-1;i++) {
        for(int j=0;j<evenCount-i-1;j++) {
            if(even[j]>even[j+1]) {
                int temp=even[j];
                even[j]=even[j+1];
                even[j+1]=temp;
            }
        }
    }
    for(int i=0;i<oddCount;i++) {
        for(int j=0;j<oddCount-i-1;j++) {
            if(odd[j]<odd[j+1]) {
                int temp=odd[j];
                odd[j]=odd[j+1];
                odd[j+1]=temp;
            }
        }
    }

    // bước 4 : gộp 2 mảng này lại
    int count=0;
    for(int i=0;i<evenCount;i++) {
        arr[count]=even[i];
        count++;
    }
    for(int i=0;i<oddCount;i++) {
        arr[count]=odd[i];
        count++;
    }
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);

    }


}
