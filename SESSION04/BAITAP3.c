#include <stdio.h>
int main() {
    int n;
    printf("Nhap so luong phan tu :");
    scanf("%d",&n);
    int a[n];
    for (int i=0 ; i<n ; i++) {
       printf("Nhap phan tu thu %d:",i+1);
        scanf("%d",&a[i]);
    }
    int minNum=a[0];
    int index=0;
    for (int i=1 ; i<n ; i++) {
        if (a[i]<minNum) {
            minNum=a[i];
            index=i;
        }
    }
    printf("vi tri phan tu nho nhat la %d",index);
    return 0;
}