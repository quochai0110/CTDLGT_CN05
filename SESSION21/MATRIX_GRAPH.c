#include <stdio.h>
// TẠO MA TRẬN 2 CHIỀU
int MATRIX[3][3];
// HÀM KHỞI TẠO MA TRẬN 2 CHIỀU VỚI CÁC GIÁ TRỊ CÁC Ô LÀ 0
void matrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            MATRIX[i][j] = 0;
        }
    }
}
// KHỎI TẠO HÀM TẠO LIÊN KẾT
void adjacency(int U,int V) {
    MATRIX[U][V] = 1;
    MATRIX[V][U] = 1;// Đồ thị vô hướng thì phải quan hệ 2 chiều
}
// TẠO HÀM HIỂN THỊ MA TRẬN
void printMatrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", MATRIX[i][j]);
        }
        printf("\n");
    }
}
int main() {
    matrix();
    adjacency(0, 1);
    printMatrix();

}
