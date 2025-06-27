//
// Created by DELL on 6/27/2025.
//
#include <stdio.h>
int recursion(int row, int col, int i, int j) {
    if (i == row || j == col) {
        return 0;
    }
    if (i==row-1 && j==col-1) {
        return 1;
    }
    return recursion(row, col, i+1,j) +recursion(row, col, i,j+1);
}
int main() {
    int rows;
    int cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    printf("The number of rows is: %d\n", recursion(rows, cols, 0, 0));


}