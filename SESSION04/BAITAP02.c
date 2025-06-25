#include <stdio.h>
int main() {
    int n;
    printf("nhap vao so luong phan tu cua mang:");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) {
        printf("arr[%d]:", i);
        scanf("%d", &arr[i]);
    }
    int maxItem=arr[0];
    int maxIndex=0;

    for(int i=0;i<n;i++) {
        if(arr[i]>maxItem) {
            maxItem=arr[i];
            maxIndex=i;
        }
    }
    printf("chi so cua phan tu lon nhat dau tien cua mang la:%d",maxIndex);
    return 0;
}