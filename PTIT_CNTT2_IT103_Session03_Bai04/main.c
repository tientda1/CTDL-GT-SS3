#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100000000
#define MIN_VALUE -100000000

int timMax(int **matrix, int rows, int cols) {
    int max = MIN_VALUE;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

int timMin(int **matrix, int rows, int cols) {
    int min = MAX_VALUE;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
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

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int min = timMin(matrix, rows, cols);
    int max = timMax(matrix, rows, cols);

    printf("Gia tri nho nhat trong ma tran: %d\n", min);
    printf("Gia tri lon nhat trong ma tran: %d\n", max);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
