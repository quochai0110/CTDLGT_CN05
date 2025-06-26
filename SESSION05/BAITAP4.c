//
// Created by DELL on 6/26/2025.
//
#include <stdio.h>
int sum(int start, int end) {
    if (start==end) {
        return end;
    }
    return start+sum(start+1, end);
}
int main() {

    int start;
    int end;
    printf("Enter start:");
    scanf("%d", &start);
    printf("Enter end:");
    scanf("%d", &end);
    if (start<0 || end<0) {
        printf("Invalid Input");
        return 0;
    }
    int result=sum(start, end);
    printf(" sum %d", result);
}