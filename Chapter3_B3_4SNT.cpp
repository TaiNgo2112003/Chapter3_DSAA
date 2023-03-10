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
int SNT(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return 0;
	return 1;
}
void sort_SNT(int a[], int n) {

	for (int i = 0; i < n - 1; i++) {
		if (SNT(i))
			for (int j = i + 1; j < n; j++)
				if (SNT(j))
					if (a[i] < a[j])
						permutation(&a[i], &a[j]);
	}
}
int main()
{

	int n = 10;
	int a[100];
	printf("Array before sorting:\n");
	for (int i = 0; i < n; i++)
		a[i] = rand() % 20;
	printfArray(a, n);
	sort_SNT(a, n);
	printf("\nArray after sorting:");
	printfArray(a, n);
}
