#include <stdio.h>
#include <stdlib.h>

float evenAvg(int *arr, int n) {
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
            count++;
        }
    }
    if (count == 0)
        return 0;
    return (float)sum / count;
}

int main() {
    int n;

    do {
        printf("Nhap so luong phan tu (0 < n < 1000): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    int *arr = (int *)malloc(n * sizeof(int));


    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    float avg = evenAvg(arr, n);
    if (avg == 0)
        printf("Khong co so chan trong mang.\n");
    else
        printf("Trung binh cong cac so chan trong mang la: %.2f\n", avg);

    free(arr);

    return 0;
}
