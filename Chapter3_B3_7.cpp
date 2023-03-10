
#include <iostream>
void printfArray(int a[], int n) {                 // CÔNG CỤ
    for (int i = 0; i < n; i++)
        printf("%d   ", a[i]);
}
void permutation(int* x, int* y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
void Le_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > 0)
            for (int j = i + 1; j < n; j++)
                if (a[j] > 0 && a[j] < a[i])
                    permutation(&a[i], &a[j]);
    }
}
int main()
{

    int n = 18;
    int a[100];
    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++)
        a[i] = rand() % 30;
    printfArray(a, n);
    Le_sort(a, n);
    printf("\nArray after sorting:");
    printfArray(a, n);
}
