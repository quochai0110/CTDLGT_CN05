//
// Created by DELL on 7/1/2025.
//
#include <stdio.h>
// tao ham quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];// chọn phần tử cuối làm pivot
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // dua pivot ve dung vi tri
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;

}
int quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex =partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);// đê quy sắp xếp phần bên trái
        quickSort(arr, pivotIndex + 1, high);// đệ quy sắp xếp phần bên phải
    }

}
int main() {
    // buoc 1:
    int n;
    do {
        printf("nhap so luong phan tu trong mang( 0<n<1000) ");
        scanf("%d", &n);
    }while (n<0||n>1000);

    int arr[n];// tao mang
    // nhap gia tri tung phan tu trong mang
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu trong mang(%d) ", i+1);
        scanf("%d", &arr[i]);
    }
    //buoc 2: hien thi cac phan tu truoc khi sap xep
    for (int i = 0; i < n; i++) {
        printf("%d \n", arr[i]);
    }
    // buoc 3: dung thuat toan quick_sort
    // goi ham bang thuat toan quick_sort
    quickSort(arr, 0, n-1);
    printf("mang sau khi da duoc sap xep \n" );
    for (int i = 0; i < n; i++) {
        printf("%d \n", arr[i]);
    }
    return 0;
}

