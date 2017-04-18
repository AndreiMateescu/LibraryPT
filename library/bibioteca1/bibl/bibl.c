#include<stdio.h>
#include"bibl.h"

void swap(int a[], int i, int j)
{
    int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}


int partition(int a[], int left, int right)
{
    int v = a[left];
    int i = left + 1;
    int j = right;

    while (true) {
        while (a[i] < v && i < right)
            i++;
        while (a[j] >= v && j > left)
            j--;
        if (i >= j)
            break;
        swap(a, i, j);
    }
    swap(a, left, j);
    return j;
}

void qsort(int a[], int left, int right)
{
    if (left >= right)
        return;
    int v = partition(a, left, right);
    qsort(a, left, v - 1);
    qsort(a, v + 1, right);
}

///
void BubleSort (int A[],int n)
{
    int i,j,aux;

    for(i=0;i<n-1;i++)
        for(j=i;j<n;j++)
            if(A[i]>A[j])
                swap(A, i, j);
}


///
    void heapSort(int numbers[], int array_size)
    {
      int i, temp;

      for (i = (array_size / 2)-1; i >= 0; i--)
        siftDown(numbers, i, array_size);

      for (i = array_size-1; i >= 1; i--)
      {
        temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i-1);
      }
    }


    void siftDown(int numbers[], int root, int bottom)
    {
      int done, maxChild, temp;

      done = 0;
      while ((root*2 <= bottom) && (!done))
      {
        if (root*2 == bottom)
          maxChild = root * 2;
        else if (numbers[root * 2] > numbers[root * 2 + 1])
          maxChild = root * 2;
        else
          maxChild = root * 2 + 1;

        if (numbers[root] < numbers[maxChild])
        {
          temp = numbers[root];
          numbers[root] = numbers[maxChild];
          numbers[maxChild] = temp;
          root = maxChild;
        }
        else
          done = 1;
      }
    }

=================================================================================================
int st[100],k,n,i,as,ev;

void init ()
{
    st[k] = 0;
}

void succesor()
{
    if (st[k]<n && k<=n){
        as = 1;
        st[k]++;
    }
    else
        as = 0;
}

void valid ()
{
    ev = 1;
    for (i=1;i<=k-1;i++)
        if (st[i] == st[k])
            ev = 0;
}

int solutie (int k)
{
    if (k==n)
        return 1;
    else
        return 0;
}

void write ()
{
    for (i=1;i<=k;i++)
        printf("%d ", st[i[]);
    printf("\n");
}

int main ()
{
    scanf("%d", &n);
    k = 1;
    init();
    while (k>0){
        do{
            succesor();
            if(as)
                valid();
        }
        while (!((!as) || (as && ev)));

        if (as)
            if(solutie(k))
                write();
            else{
                k++;
                init();
            }
        else
            k--;
    }
    return 0;
}
================================================================================================

void dfs(int Adj[][MAX], int n, int source) {
	int i, j;
	bool change = false;

	int visited[MAX];

	int tos = 0;

	int stack[STACK_SIZE];

	for(i = 0; i < MAX; i++) {
		visited[i] = 0;
	}

	visited[source] = 1;

	stack[tos] = source;

	printf("%d ", source);

	while(tos >= 0) {

		change = false;

		i = stack[tos];

		for(j = 0; j < n; j++) {
			if(visited[j] == 0 && Adj[i][j] == 1) {

				visited[j] = 1;

				tos++;
				stack[tos] = j;

				printf("%d ", j);

				change = true;

				break;
			}
		}
		if(change == false) {
			tos--;
		}
	}
	printf("\n");
}

