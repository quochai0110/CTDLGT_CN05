//
// Created by DELL on 6/26/2025.
//
#include <stdio.h>
int recursion(int n) {
    // điều kiện dừng
    if (n==0) {
        return 0;
    }
    return n+ recursion(n-1);// 5+4+3+2+1+0
    // gọi lại chính nó

}
int fac(int n) {
    if (n==1) {
        return 1;
    }
    return n*fac(n-1);
}
int main() {
    recursion(5);
    // tinh tong tu 1 den n : n+ n-1+ n-2 + n-3+... + 1
    // tinh giai thua 1 den n
    fac(5);

}
