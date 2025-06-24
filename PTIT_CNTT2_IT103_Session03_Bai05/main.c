#include <stdio.h>
#include <stdlib.h>

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

    int tongDuongCheoChinh = 0;
    int tongDuongCheoPhu = 0;

    if (rows == cols) {
        for (int i = 0; i < rows; i++) {
            tongDuongCheoChinh += matrix[i][i];
            tongDuongCheoPhu += matrix[i][rows - i - 1];
        }

        printf("Tong duong cheo chinh cua ma tran la: %d\n", tongDuongCheoChinh);
        printf("Tong duong cheo phu cua ma tran la: %d\n", tongDuongCheoPhu);
    } else {
        printf("Khong tinh duoc duong cheo vi ma tran khong vuong.\n");
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
