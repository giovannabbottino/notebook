/*
* aluna: Giovanna Borges Bottino giovannabbottino@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void bubble(Item *list, int l, int r);
void printList(int list[], int i);


int main(){
    int n, i=0;
    int arr[1000];
    while(scanf(" %d", &n) != EOF){
        arr[i] = n;
        i++;
    }
    bubble(arr, 0, i-1);
    printList(arr, i);
    return 0;
}

void bubble(Item *list, int l, int r) { 
   int i, j;
   for(int i=l;i<r;i++)
    for(int j=l+1;j<=r;j++)
        cmpexch(list[j-1], list[j]);
} 

void printList(int list[], int i){
    int j;
    for (j=0;j<i; j++){
        printf("%d ", list[j]);
    }
    printf("\n");
}

