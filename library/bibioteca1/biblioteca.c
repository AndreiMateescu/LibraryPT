#include<stdio.h>
#include "biblioteca.h"
#include <stdbool.h>
#define STACK_SIZE 20
#define MAX 20


void poz_elem(Nod *cap, int poz, int valoarea){
    int numar = 0;
    Nod *aux;
    Nod *noulNod;
    aux = cap;
    while(numar < poz){
        aux = aux->next;
        numar++;
    }
    noulNod = malloc(sizeof(Nod));
    noulNod->next = aux->next;
    aux->next = noulNod;
    noulNod->val = valoarea;
}

void ultimul_elem(Nod *cap, int valoarea){
    Nod *curent;
    curent = cap;
    Nod *NoulElem;
    NoulElem = malloc(sizeof(Nod));
    while(curent->next != NULL){
        curent = curent->next;
    }
    curent->next = NoulElem;
    NoulElem->next = NULL;
    NoulElem->val = valoarea;
}

void primul_elem(Nod *cap, int valoare){
    Nod *new_elem;
    new_elem = malloc(sizeof(Nod));
    new_elem->next = cap->next;
    cap->next = new_elem;
    new_elem->val = valoare;
}

void afisare_elem(Nod *cap){
    Nod *curent;

    if (cap ->next == NULL){
        printf("Lista este goala");
    }else{
    curent = cap;

        while(curent->next != NULL){
            curent = curent->next;
            printf("%d ", curent->val);
        }
    }
}

int delprimul_elem(Nod *cap){
    int valoare;
    Nod *aux;
    aux = cap->next;
    valoare = aux->val;
    cap->next = aux->next;
    free(aux);
    return valoare;
}

int delultimul_elem(Nod *cap){
    int valoare;
    Nod *curent, *aux;
    curent = cap->next;
    while (curent->next->next != NULL){
        curent = curent->next;
    }
    valoare = curent->next->val;
    aux = curent->next->next;
    curent->next=NULL;
    free(aux);
    return valoare;
}

int delpoz_elem(Nod *cap, int poz){
    int numar = 0, valoare;
    Nod *curent, *aux;
    curent = cap->next;
    while(numar < poz-1){
        curent = curent->next;
        numar++;
    }
    aux = curent->next;
    valoare = aux->val;
    curent->next = aux->next;
    free(aux);
    return (valoare);
}

void Merge(int L[], int R[], int A[], int nL, int nR) // parametrii sunt vectori A->vectorulmare, L, R -> vectorii mai mici, nL-> lungimea lui L
//leaga cele doua siruri ordonate si le ordoneaza in vectorul mare
{
    int i, j , k;// i->poz L, j->poz R, k->poz A
    i = j = k = 0;

    while(i < nL && j < nR){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < nL){  //cand mai raman elementu in unul dintre subsiruri
        A[k] = L[i];
        i++;
        k++;
    }

    while(j < nR){
        A[k] = R[j];
        k++;
        j++;
    }
}

int MergeSort (int A[],int n) // creeaza cele doua subsiruri
{
    //int n; // lungimea lui a;
    int mid; // jumatera lui n
    int i;

    if(n < 2){
        return;
    }

    mid = n/2;
    int left[mid];//prima jumatate lungimea mid
    int right[n-mid]; // a doua jumatate lungimea n-mid

    for (i=0;i<mid;i++){
        left[i] = A[i];
    }
    for (i=mid;i<n;i++){
        right[i-mid] = A[i];
    }
    MergeSort(left,mid);
    MergeSort(right,n-mid);
    Merge(left,right,A,mid,n-mid);
}

//n->nr noduri, source->nodul de plecare
void dfs(int Adj[][MAX], int n, int source) {
	//variables
	int i, j;
	bool change = false;

	//visited array to flag the vertex that
	//were visited
	int visited[MAX];

	//top of the stack
	int tos = 0;

	//stack
	int stack[STACK_SIZE];

	//set visited for all vertex to 0 (means unvisited)
	for(i = 0; i < MAX; i++) {
		visited[i] = 0;
	}

	//mark the visited source
	visited[source] = 1;

	//push the vertex into stack
	stack[tos] = source;

	//print the vertex as result
	printf("%d ", source);

	//continue till stack is not empty
	while(tos >= 0) {
		//to check if any vertex was marked as visited
		change = false;

		//get vertex at the top of the stack
		i = stack[tos];

		for(j = 0; j < n; j++) {
			if(visited[j] == 0 && Adj[i][j] == 1) {
				//mark vertex as visited
				visited[j] = 1;

				//push vertex into stack
				tos++;
				stack[tos] = j;

				//print the vertex as result
				printf("%d ", j);

				//vertex visited
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

 void HeapSort(int v[],int vsize) //size->dimensiuneaq vector  ( vectorul initializt de la 1 si size n+1 )
{
    int i, j, tmp, v_sortat[vsize];
    v_sortat[0] = -1; //indexul0 nu se foloseste;

    for(i=vsize,j=1;i>=1;i--,j++){
        minHeap(v,i);
        v_sortat[j] = v[1];
        v[1]=v[i-1]; //put last element to root node
    }

    //set the result
	for(i = 0; i < vsize; i++) {
		v[i] = v_sortat[i];
	}
}


void minHeap(int arr[], int vsize) {
	int i, left, right, tmp, val;

	for(i = vsize / 2; i >= 1; i--) {

		//taking 1 as the start index
		//if parent node = i
		//so left child = 2i
		//and right child = 2i+1
		tmp = i;
		left = (2 * i);
		right = (2 * i) + 1;

		if(left < vsize && arr[left] < arr[tmp]) {
			tmp = left;
		}

		if(right < vsize && arr[right] < arr[tmp]) {
			tmp = right;
		}

		if(tmp != i) {
			val = arr[i];
			arr[i] = arr[tmp];
			arr[tmp] = val;
			minHeap(arr, vsize);
		}
	}
}


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

void BubleSort (int A[],int n) {
    int i,j,aux;

    for(i=0;i<n-1;i++)
        for(j=i;j<n;j++)
            if(A[i]>A[j])
                swap(A, i, j);
}

