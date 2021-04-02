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

void selection(Item *list, int l, int r);
void printList(int list[], int i);

int main(){
    int n, i=0;
    int arr[1000];
    while(scanf(" %d", &n) != EOF){
        arr[i] = n;
        i++;
    }
    selection(arr, 0, i-1);
    printList(arr, i);
    return 0;
}

void selection(Item *list, int l, int r) { 
    for(int i=l;i<r;i++){
        int min=i;
        for(int j=i+1;j<=r;j++)
            if(less(list[j],list[min]))
                min=j;
            exch(list[i],list[min]);
    }
} 

void printList(int list[], int i){
    int j;
    for (j=0;j<i; j++){
        printf("%d ", list[j]);
    }
    printf("\n");
}
