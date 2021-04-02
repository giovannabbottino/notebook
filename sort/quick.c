/*Giovanna Borges Bottino giovannabbottino@gmail.com*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j);
int separa(int *arr, int l, int r);
void quickSelect(int *arr, int l, int r, int k);
void quickSort (int *arr, int l, int r);
void printList(int list[], int start, int end);

int main(){
    int n;
    scanf(" %d", &n);

    int id;
    int *arr = (int*) malloc( n * sizeof(int));
    for(int i= 0; i < n; i++){
        scanf("%d", &id);
        arr[i] = id;
    }

    int start, end;
    start = 0;
    end = n;
    
    quickSelect(arr,0,n-1, start);
    quickSort(arr, start, n-1);

    printList(arr, start,end);
    
    return 0;
}

void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int separa(int *arr, int l, int r){
    int c = arr[r];
    int j = l, k, aux;
    k = l;
    while(k<r){
        if(arr[k]<c){
            swap(arr,k,j);
            j++;
        }
        k++;
    }
    swap(arr,k,j);
    return j;
}

void quickSelect(int *arr, int l, int r, int k){
    int i;
    if(r<=l){
        return;
    }
    i = separa(arr,l,r);
    if(i>k){
        quickSelect(arr,l,i-1,k);
    }
    if(i<k){
        quickSelect(arr,i+1,r,k);}
    }

void quickSort(int *arr, int l, int r){
    int j, aux = 0;
    int mid;
    mid = (l+r)/2;
    if(r<=l){
        return;
    }
    if(arr[mid] < arr[r]){
        swap(arr,mid,r);
    }
    if(arr[l] < arr[mid]){
        swap(arr,l,mid);
    }
    if(arr[r] < arr[mid]){
        swap(arr,r,mid);
    }

    j = separa(arr,l,r);
    quickSort(arr,l,j-1);
    quickSort(arr,j+1,r);
}

void printList(int *arr, int start, int end){
    int j;
    int count =0;

    for(j = start; j<end; j++){
        printf("%d", arr[start+count]);
        printf("\n");
        
        count++;
    }
}

