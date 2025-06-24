#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int *arr;
    int max = 0;

    do {
        printf("Nhap so luong phan tu cua mang:");
        scanf("%d", &n);
    } while (n <=0 || n > 1000);

    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d:", i+1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Phan tu lon nhat la : %d", max);
    free(arr);
}
