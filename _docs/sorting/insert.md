---
layout: default
title: Insertion Sort
nav_order: 2
description: 'Insertion Sort'
parent: Sorting Algorithms
---

Insertion Sort
{: .fs-9}

Insertion Sort is a simple and intuitive sorting algorithm that builds the final sorted array one item at a time. It is much like sorting playing cards in your hands. It is an in-place, stable, comparison-based sorting algorithm.

How Insertion Sort Works?
{: .fs-6 .fw-300 }

- Iterate: Start from the second element (element at index 1) and compare it with the elements before it.
- Compare: If the current element is smaller than the previous element, compare it with the elements before.
- Insert: Shift all the elements larger than the current element one position to the right and insert the current element at the correct position.

<a href="{{ site.baseurl }}/assets/images/sort/insertion.png" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/sort/insertion.png" class="img-fluid" />
</a>

###### From [GeeksforGeeks](#ref1)

Why Use Insertion Sort
{: .fs-6 .fw-300 }

Insertion Sort offers several advantages:

- It is simple to implement and understand.
- It is efficient for small data sets or lists that are already partially sorted.
- It is an in-place sort, requiring only a constant amount of additional memory space.
- It is stable, meaning that it does not change the relative order of elements with equal keys.

  
Implement
{: #implement}

First, we will need a few macros to simplify code and make it more readable.

less(A,B) compares if A is less than B.
lesseq(A,B) compares if A is less than or equal to B.
exch(A,B) exchanges the values of A and B.
cmpexch(A,B) compares A and B, and exchanges them if A is greater than B.
```c
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }
```

Next, we create the insertion function. This function implements the insertion sort algorithm. It iterates through the array, compares and shifts elements as needed, and inserts the current element in the correct position.

```c
void insertion(int *list, int l, int r) { 
    for(int i = r; i > l; i--){
        cmpexch(list[i-1], list[i]);
    }
    for(int i = l + 2; i <= r; i++){
        int j = i; 
        int tmp = list[j];
        while(less(tmp, list[j-1])){
            list[j] = list[j-1];
            j--;
        }
        list[j] = tmp;
    }
}
```
Code
{: #code}

```c
/* Giovanna Borges Bottino giovannabbottino@gmail.com */

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
    int n, i = 0;
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
    for(int i = r; i > l; i--){
        cmpexch(list[i-1], list[i]);
    }
    for(int i = l + 2; i <= r; i++){
        int j = i; 
        Item tmp = list[j];
        while(less(tmp, list[j-1])){
            list[j] = list[j-1];
            j--;
        }
        list[j] = tmp;
    }
}

void printList(int list[], int i){
    for (int j = 0; j < i; j++){
        printf("%d ", list[j]);
    }
    printf("\n");
}
```
The Big-O notation
Insertion Sort has a time complexity of O(n^2) in the average and worst-case scenarios. However, it performs well on small or nearly sorted datasets with a time complexity of O(n) in the best-case scenario. The space complexity is O(1) since it is an in-place sorting algorithm.

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
        <th>Insertion Sort</th>
        <td>O(n)</td><td>O(n)</td><td>O(n^2)</td><td>O(n^2)</td><td>O(n^2)</td><td>O(n^2)</td><td>O(n^2)</td><td>O(n^2)</td><td>O(1)</td>
    </tr>
</tbody>
</table>
References
[1]  Geeeks For Geeks, Difference between Insertion sort and Selection sort. Available at: [https://en.wikipedia.org/wiki/Insertion_sort](https://www.geeksforgeeks.org/difference-between-insertion-sort-and-selection-sort/). Accessed: March 01, 2024.
{: #ref1}
