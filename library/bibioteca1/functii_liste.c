#include<stdio.h>
#include "biblioteca.h"
#include <stdbool.h>
#define MAX 20

int main ()
{
    /*Nod *cap = NULL;
    cap = malloc(sizeof(Nod));
    cap->next = NULL;
    primul_elem(cap,120);
    ultimul_elem(cap,2);
    ultimul_elem(cap,3);
    ultimul_elem(cap,4);
    poz_elem(cap,3,5);
    afisare_elem(cap);
    printf("\n");
    printf("%d\n",delpoz_elem(cap,3));
    afisare_elem(cap);*/
    /*int vector[13] = { 6,8,3,4,5,23,65,98,4,56,1,546,2};
	int i,n = 10;

    HeapSort(vector,13);
	for (i = 0; i < 13; i++){

		printf("%d ", vector[i]);
	}*/
    int a[11];
    int n,i;
    n=10;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    BubleSort(a,n);

    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}


