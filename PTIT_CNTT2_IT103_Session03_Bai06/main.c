#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int *arr = NULL;

    do {
        printf("Nhap so phan tu n (0 < n < 1000): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Nhap so phan tu muon them (m): ");
    scanf("%d", &m);

    int *temp = realloc(arr, (n + m) * sizeof(int));
    if (temp == NULL) {
        printf("Khong the cap phat lai bo nho.\n");
        free(arr); // Giải phóng nếu realloc thất bại
        return 1;
    }
    arr = temp;

    printf("Nhap %d phan tu muon them:\n", m);
    for (int i = n; i < n + m; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Mang sau khi them phan tu:\n");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
