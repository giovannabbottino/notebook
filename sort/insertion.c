/*Giovanna Borges Bottino giovannabbottino@gmail.com*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void insertion(Item *list, int l, int r);
void printList(int list[], int i);

int main(){
    int n, i=0;
    int arr[1000];
    while(scanf(" %d", &n) != EOF){
        arr[i] = n;
        i++;
    }
    insertion(arr, 0, i-1);
    printList(arr, i);
    return 0;
}

void insertion(Item *list, int l, int r) { 
    for(int i=r;i>l;i--){
        cmpexch(list[i-i],list[i]);
    }
    for(int i=l+2;i<=r;i++){
        int j=i; 
        Item tmp=list[j];
        while(less(tmp,list[j-1])){
            list[j]=list[j-1];
            j--;
        }
        list[j]=tmp;
    }
} 

void printList(int list[], int i){
    int j;
    for (j=0;j<i; j++){
        printf("%d ", list[j]);
    }
    printf("\n");
}

