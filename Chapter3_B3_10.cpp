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
void Create_ARR(int a[], int& n)//Create random array
{
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
		if ((a[i] % 2 == 0 && a[i - 1] % 2 == 0) || (a[i] % 2 != 0 && a[i - 1] % 2 != 0))
			a[i]++;
	}
	printf("Array 1: ");
	printfArray(a, n);
	for (int j = 0; j < n; j++) {
		a[j] = rand() % 100;
		if ((a[j] % 2 == 0 && a[j - 1] % 2 == 0) || (a[j] % 2 != 0 && a[j - 1] % 2 != 0))
			a[j]++;
	}
	printf("Array 2: ");
	printfArray(a, n);
}

 
void sort(int a[], int n) {
	int min;
	for (int i = 0; i < n-1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				permutation(&a[min], &a[j]);
	}
}

void main() {
	int a[100];
	int n = 10;
	
	printf("Array before sort: ");
	//printfArray(a, n);
	Create_ARR(a, n);


	printf("\nArray after sort: \n");
	sort(a, n);
	printfArray(a, n);


}