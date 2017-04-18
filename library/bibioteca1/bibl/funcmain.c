#include<stdio.h>
#include "bibl.h"
#include <stdbool.h>


int main ()
{

    int a[11];
    int n,i;
    n=10;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    BubleSort(a,n);

    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}


