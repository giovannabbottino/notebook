/*Giovanna Borges Bottino giovannabbottino@gmail.com*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void shell(Item *list, int l, int r);
void printList(int list[], int i);

int main(){
    int n, i=0;
    int arr[50000];
    while(scanf(" %d", &n) != EOF){
        arr[i] = n;
        i++;
    }
    shell(arr, 0, i-1);
    printList(arr, i);
    return 0;
}

void shell(Item *list, int l, int r) { 
    for(int i=l+1;i<=r;i++)
        for(int j=i;j>l;j--)
            cmpexch(list[j-1],list[j]);
} 

void printList(int list[], int i){
    int j;
    for (j=0;j<i; j++){
        printf("%d ", list[j]);
    }
    printf("\n");
}

