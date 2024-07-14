---
layout: default
title: Quick Select
nav_order: 4
description: 'Quick Select'
parent: Sorting Algorithms
---

Quick Select
{: .fs-9}

Quick select is a deterministic algorithm for finding the k-th smallest element in an unordered list. It is closely related to the quicksort sorting algorithm. 

How Quick Select Works?
{: .fs-6 .fw-300 }

The quick select algorithm works by selecting a pivot element from the list and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot. The process is then repeated recursively on the sub-array where the desired element is located.

Unlike the quicksort algorithm which recursively processes both sides of the partition, quick select only recurses into one side (the side that contains the desired element), which leads to a worst-case time complexity of O(n^2). However, on average, the algorithm runs in O(n) time, making it efficient for finding the k-th smallest element in linear time on average.

<a href="{{ site.baseurl }}/assets/images/sort/quickselect.png" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/sort/quickselect.png" class="img-fluid" />
</a>

###### From [GeeksforGeeks](#ref1)

Why Use Quick Select
{: .fs-6 .fw-300 }

Quick select is particularly useful when there is a need to find the k-th smallest or largest element in an unordered list without having to sort the entire list. It provides a more efficient solution than sorting the entire list and then picking the desired element.

Additionally, quick select can be adapted to find elements based on their rank or percentile, making it versatile for various statistical and computational tasks.


## Implement 
{: #implement}

First create the swap function: This function swaps two elements in an array. It's used by both Quick Sort and Quick Select to reorganize elements.
```c
void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
```

Then we create a separa function, the partition function used by both Quick Sort and Quick Select. It selects a pivot (in this case, the last element arr[r]), partitions the array into two parts (elements smaller than the pivot and elements larger than the pivot), and returns the index (j) of the pivot after partitioning.

```c
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
```

Then you are ready to create your quick select function, it finds the k-th smallest element in an array using the Quick Select algorithm. It recursively partitions the array around a pivot until it finds the element at index k. If the pivot index i is greater than k, it recursively calls itself on the left subarray (arr[l] to arr[i-1]). If i is less than k, it calls itself on the right subarray (arr[i+1] to arr[r]). Once i equals k, arr[k] contains the k-th smallest element.

```c
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
```

## The [Big-O notation]({{site.baseurl}}/algorithm/computational_complexity#bigO)

<table>
<thead>
    <tr>
        <th id="str" scope="col">
            Data Structure
        </th>
        <th id="time" scope="col" class="span" colspan="8">
            Time Complexity
        </th>
        <th id="space" scope="col">
            Space Complexity
        </th>
    </tr>
</thead>
<tbody>
    <tr>
        <th></th>
        <th id="av" class="span" colspan="4" scope="colgroup">
            Average
        </th>
        <th id="wr" class="span" colspan="4" scope="colgroup">
            Worst
        </th>
        <th>
            Worst
        </th>
    </tr>
    <tr>
        <th></th>
        <th>Access</th>
        <th>Search</th>
        <th>Insertion</th>
        <th>Deletion</th>
        <th>Access</th>
        <th>Search</th>
        <th>Insertion</th>
        <th>Deletion</th>
        <th></th>
    </tr>
    <tr>
        <th>Quick Select</th>
        <td>O(n)</td>
        <td>O(n)</td>
        <td>O(n)</td>
        <td>O(n)</td>
        <td>O(n^2)</td>
        <td>O(n^2)</td>
        <td>O(n^2)</td>
        <td>O(n^2)</td>
        <td>O(1)</td>
    </tr>
</tbody>
</table>

## Code
{: #code}

```c
#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j);
int separa(int *arr, int l, int r);
void quickSelect(int *arr, int l, int r, int k);
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
```
