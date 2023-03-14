
#include <iostream>
#include < math.h>
#include <conio.h>
#define MAX 100

void intput(int a[], int& n)
{
	do {
		printf("\nintput so phan tu: ");
		scanf_s("%d", &n); if (n <= 0 || n > MAX)
		{
			printf("\n Nhap lai di ");
		}
	} while (n <= 0 || n > MAX);
	for (int i = 0; i < n; i++)
	{
		printf("\n Nhap pt a[%d]: ", i);
		scanf_s("%d", &a[i]);
	}
}
void Output(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		printf("%4d", a[i]);
	}
}
void permutation(int& a, int& b)
{
	int temp = a; a = b; b = temp;
}
void SapXep(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j]) { permutation(a[i], a[j]); }
		}
	}
} void Tron2MangThanh1Mang(int a[], int b[], int c[], int na, int nb, int& nc)
{
	nc = na + nb;
	SapXep(a, na);
	SapXep(b, nb);
	int vitriA = 0, vitriB = 0;
	for (int i = 0; i < nc; i++)
	{
		if (vitriA < na && vitriB < nb)
		{
			if (a[vitriA] < b[vitriB])
			{
				c[i] = a[vitriA++];
			}
			else {
				c[i] = b[vitriB++];
			}
		}
		else if (vitriB == nb)
		{
			c[i] = a[vitriA++];
		}
		else {
			c[i] = b[vitriB++]; 
		}
	}
}
int main() {
	int na, nb, nc;
	int a[MAX], b[MAX], c[MAX];
	intput(a, na); Output(a, na);
	intput(b, nb); Output(b, nb);
	Tron2MangThanh1Mang(a, b, c, na, nb, nc);
	printf("\nMang sau khi tron 2 mang : ");
	Output(c, nc); _getch(); return 0;


}
//void intput(int a[], int &n) {
//	do {
//		printf("\nintput so luong phan tu: ");
//		scanf_s("%d", &n);
//		if (n <= 0 || n > MAX) {
//			printf("\nintput lai so luong pt: ");
//		}
//		
//	} while (n <= 0 || n > MAX);
//	for (int i = 0; i < n; i++) {
//		printf("\nintput pt a[%d]:  ", i);
//		scanf_s("%d", &a[i]);
//	}
//}
//void Output(int a[], int n) {
//	for (int i = 0; i < n; i++) {
//		printf(" %d ", a[i]);
//	}
//}
//
//void permutation(int x, int y) {
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//
//void sort(int a[], int n) {
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = i + 1; j < n; j++) {
//			if (a[j] < a[i])
//				permutation(a[j], a[i]);
//		}
//	}
//}
//
//void sort_two_Array(int a[], int b[], int c[], int A, int B, int &C) {
//	C = A + B;
//	sort(a, A);
//	sort(b, B);
//	int posA = 0; int posB = 0;
//
//	for (int i = 0; i < C; i++) {
//
//		if (posA < A && posB < B) {
//			if (a[posA] < b[posB]) {
//				c[i] = a[posA++];
//			}
//			else {
//				c[i] = b[posB++];
//			}
//		}
//		else if (posB == B) // nếu tăng 1 B bằng số pt của mảng thì tiếp tục sắp xếp mảng A
//		{
//			c[i] = a[posA++];
//		}
//		else
//		{
//			c[i] = b[posB++];
//		}
//	}
//}
//int main() {
//	int a[MAX], b[MAX], c[MAX];
//	int A, B, C;
//
//	intput(a, A);	
//	Output(a, A);
//
//	intput(b, B);
//	Output(b, B);
//
//	sort_two_Array(a, b, c, A, B, C);
//	Output(c, C);
//
//	return 0;
//}