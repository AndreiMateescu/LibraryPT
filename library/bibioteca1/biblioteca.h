#include <stdbool.h>
#define MAX 20
typedef struct Nod{
    int val;
    struct Nod *next;
}Nod;


void poz_elem(Nod *cap, int poz, int valoarea);
void ultimul_elem(Nod *cap, int valoarea);
void afisare_elem(Nod *cap);
void primul_elem(Nod *cap, int valoare);
int delprimul_elem(Nod *cap);
int delultimul_elem(Nod *cap);
int delpoz_elem(Nod *cap, int poz);
void Merge(int L[], int R[], int A[], int nL, int nR);
int MergeSort (int A[],int n);
void HeapSort(int v[], int vSize);
void dfs(int Adj[][MAX], int n, int source);
void minHeap(int arr[], int vsize);
void BubleSort (int A[],int n);
void qsort(int a[], int left, int right);
int partition(int a[], int left, int right);
void swap(int a[], int i, int j);


