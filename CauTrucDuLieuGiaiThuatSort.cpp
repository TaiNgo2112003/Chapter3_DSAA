// CauTrucDuLieuGiaiThuatSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include<time.h>   // Thư viện thời gian
using namespace std;


//-------------------------------------------------------------------------------------------------------------------------------------------
void printfArray(int a[], int n) {                 // CÔNG CỤ
    for (int i = 0; i < n; i++)
        printf("%d   ", a[i]);
}
void permutation(int *x, int* y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
void SelectionSort(int a[], int n) {
    int min;                                                                //Giải Thuật: tạo biến min = pt thứ I, cho chạy 2 vòng lặp lồng nhau
    for (int i = 0; i < n - 1; i++) {                                       //nếu I lớn hơn J thực hiện permutation(hoán đổi).
        min = i;
        for (int j = i+1; j < n; j++) 
            if (a[j] < a[min])
                min = j;
            permutation(&a[min],&a[i]);
        
    }
    printf("\nArray after sort by SelectionSort(Chon Truc Tiep): ");
    printfArray(a, n);
}



//-----------------------------------------------------------------------------------------------------------------------------------------------
void InterchangeSort(int a[], int n) 
{                                                                           //Giải Thuật: thuật toán này(interchange) khá giống với Selectionsort
        for (int i = 0 ; i < n - 1; i++) {                                  // thay vì là cho tạo biến min = I và cho chạy hết mảng thì interchange                                                                    
        for (int j = i+1; j < n; j++)                                     //đổi chỗ nếu vị trí I lớn hơn J    
            if (a[i]> a[j] )
                permutation(&a[i], &a[j]);
    }
    printf("\nArray after sort by InterchangeSort way(Doi cho truc tiep): ");
    printfArray(a, n);
}


//------------------------------------------------------------------------------------------------------------------------------------------------


void insertSort(int a[], int n) {
    int imp; // lưu ở 1 không gian khác tránh bị đè
    int pos; //xét phần tử thứ i-1 để kiểm tra xem pt ở đó có lớn hơn ở imp không
    
    for (int i = 1; i < n; i++) //vì nếu chỉ có một phần tử duy nhất thì không càn sắp xếp.
    {
        imp = a[i];
        pos = i - 1;
        while (pos >= 0 && a[pos] > imp)  // chỉ đc đổi chỗ khi nó trước đầu mảng và giá trị i-1 lớn hơn giá trị đang xet(vì đang sắp xếp tăng dần
        {
            a[pos + 1] = a[pos];// vị trí i -1 thành vị trí i
            pos--;

        }
        a[pos+1] = imp;
    }
    printf("\n Array after sorting by insertSort way(Chen Truc Tiep): ");
    printfArray(a, n);
}




//------------------------------------------------------------------------------------------------------------------------------------------------------
 
void BubbleSort(int a[], int n) 
{
    int i, j;
    for (i = 0; i < n -1 ; i++)
    
        for (j = n - 1; j > i; j--)
        
            if ((a[j] < a[j - 1])) 
              
                    permutation(&a[j], &a[j - 1]);
            
    
    printf("\nArray after sort by Bubble sort way: ");
   return  printfArray(a, n);
   
}


void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && a[j] < a[j - 1])

        {
            permutation(&a[j], &a[j - 1]);
            j--;
        }
        
    }

    printf("\nArray after sort by Insertion  sort way: ");
    return  printfArray(a, n);
}

int main()
{

    int n = 18;
    int a[100];
    printf("Array before sorting:");
    for (int i = 0; i < n; i++) 
        a[i] = rand() % 100;
        printfArray(a, n);
        
       // insertSort(a, n); 
      //  SelectionSort(a, n);
      // BubbleSort(a, n);
      InterchangeSort(a, n);
        //InsertionSort(a, n);
    


       
        clock_t start, end;
        double duration;
        start = clock();     
        end = clock();
        duration = (double)(end - start) / CLOCKS_PER_SEC;
        printf(" \n Bubble Sort take %f seconds \n ", duration);

            return 0;
}   
    
    

