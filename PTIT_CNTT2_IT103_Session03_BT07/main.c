#include <stdio.h>
#include <stdlib.h>

int tinhTongHangK(int **matrix, int cols, int k) {
    int tong = 0;
    for (int j = 0; j < cols; j++) {
        tong += matrix[k][j];
    }
    return tong;
}

int main(void) {
    int rows, cols;

    do {
        printf("Nhap so hang va cot (0 < n < 1000): ");
        scanf("%d %d", &rows, &cols);
    } while (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Nhap cac phan tu cho ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int k;
    do {
        printf("Nhap chi so hang k can tinh tong (0 <= k < %d): ", rows);
        scanf("%d", &k);
    } while (k < 0 || k >= rows);

    int tong = tinhTongHangK(matrix, cols, k);
    printf("Tong cac phan tu cua hang %d la: %d\n", k, tong);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
