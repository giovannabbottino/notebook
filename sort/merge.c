/*Giovanna Borges Bottino giovannabbottino@gmail.com*/

#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void printList(int list[], int i);
void mergesort(int *V,int l, int r);
void merge(int *V, int l, int m, int r);

int main(){
    int n;
    while(1){
        scanf(" %d", &n);
        if (n == 0){
            break;
        }
        int *p=malloc(sizeof(int)*(n * 2));
        
        for (int i=0;i<n;i++){
            scanf(" %d", &p[i]);
        }
        
        mergesort(p,0, n-1);
        printList(p, n);
        
        free(p);
    }
    
    return 0;
}

void merge(int *V, int l, int m, int r){
  int *R=malloc(sizeof(int)*(r-l+1));
  int i=l,j=m+1,k=0;

  while(i<=m && j<=r)
  {
    if(lesseq(V[i],V[j]))
      R[k++]=V[i++];
    else
      R[k++]=V[j++];
  }

  while(i<=m)
      R[k++]=V[i++];
  while(j<=r)
      R[k++]=V[j++];


  k=0;
  for(i=l;i<=r;i++)
    V[i]=R[k++];
  free(R);
}

void mergesort(int *V,int l, int r){
  if (l>= r) return;
  int middle=(l+r)/2;
  mergesort(V,l,middle);
  mergesort(V,middle+1,r);
  merge(V,l,middle,r);
}

void printList(int list[], int i){
    int j;
    for (j=0;j<i; j++){
        printf("%d ", list[j]);
    }
    printf("\n");
}
