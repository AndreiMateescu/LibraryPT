#include <stdbool.h>
#define MAX 20

void Merge(int L[], int R[], int A[], int nL, int nR);
int MergeSort (int A[],int n);
void BubleSort (int A[],int n);
void qsort(int a[], int left, int right);
int partition(int a[], int left, int right);
void swap(int a[], int i, int j);
void dfs(int Adj[][MAX], int n, int source);
void heapSort(int v[], int vSize);
void siftDown(int numbers[], int root, int bottom);

