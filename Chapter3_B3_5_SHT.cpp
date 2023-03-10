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
bool PN(int n) {
	int sum = 0;//khai bao biem sum
	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0)
			sum += i;
	}
	if (sum == n) return true; // tra ve true
	return false;
}
void sortPerfectN(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (PN(i))
			for (int j = i + 1; j < n; j++)
				if (PN(j) && a[j] < a[i])
					permutation(&a[i], &a[j]);
						
						
						
	}
}
void main() {

	/*int n = 50;
	int a[100];*/
	int n = 3;
	int a[3] = { 496,6,28 };
	printf("Array before sorting:\n");
	/*for (int i = 0; i < n; i++)
		a[i] = rand() % 30;*/
	printfArray(a, n);
	sortPerfectN(a, n);
		printf("\nArray after sorting:");
	printfArray(a, n);
}