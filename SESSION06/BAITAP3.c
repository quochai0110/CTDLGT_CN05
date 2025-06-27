#include <stdio.h>
int tong(int n) {
    if (n == 0) return 0;
    return n%10 + tong (n/10);
}
int main() {
    int n;
    printf("Moi ban nhap vao so nguyen");
    scanf("%d", &n);

    if ( n <=0) {
        printf("Khong hop le !");
    }

    int tongSoNguyen = tong(n);
    printf("%d", tongSoNguyen);
    return 0;
}