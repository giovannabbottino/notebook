---
layout: default
title: Shell Sort
nav_order: 6
description: 'Shell Sort'
parent: Sorting Algorithms
---

Shell Sort
{: .fs-9}

Shell sort, also known as Shell's method, is an efficient sorting algorithm that builds upon the insertion sort algorithm. It was proposed by Donald Shell in 1959 and is renowned for its ability to improve upon the time complexity of the insertion sort algorithm, especially when dealing with larger datasets.

How Shell Sort Works?
{: .fs-6 .fw-300  }

At its core, Shell sort works by breaking down the initial list into smaller sublists and performing an insertion sort on each of these sublists. However, what sets Shell sort apart is the way it chooses which elements to compare and swap within these sublists.

Instead of comparing adjacent elements like in the insertion sort, Shell sort compares elements that are at a certain interval apart. This interval decreases with each iteration of the algorithm until it becomes 1, at which point the algorithm behaves like a traditional insertion sort on a nearly sorted list. By starting with a larger interval and gradually reducing it, Shell sort can efficiently move elements closer to their correct positions in the final sorted list.

<a href="{{ site.baseurl }}/assets/images/sort/shell.png" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/sort/shell.png" class="img-fluid" />
</a>

###### From [JavatPoint](#ref1)

Why Use Shell Sort
{: .fs-6 .fw-300  }

There are several reasons why one might choose to use Shell sort:

- Efficiency: Shell sort offers significant improvements over the basic insertion sort algorithm, especially for larger datasets. Its time complexity is influenced by the choice of gap sequence but generally falls between O(n) and O(n^2), making it suitable for practical applications.
- Adaptability: Shell sort's performance can be tuned by selecting different gap sequences, allowing developers to optimize the algorithm for specific datasets or performance requirements.
- In-Place Sorting: Like insertion sort, Shell sort can be implemented as an in-place sorting algorithm, meaning it does not require additional memory proportional to the size of the input array.

##### When is Shell Sorting Utilized?

Shell sort is particularly useful in scenarios where other efficient sorting algorithms like quicksort or mergesort may not be feasible due to memory constraints or implementation complexity. It's commonly used in situations where a moderate level of sorting performance is required and the dataset is not extremely large.

Additionally, Shell sort can be advantageous when sorting data that is nearly sorted or partially sorted, as it tends to perform well in these scenarios due to its adaptive nature.

In conclusion, Shell sorting is a versatile and efficient sorting algorithm that offers improvements over basic insertion sort while maintaining simplicity and adaptability. Its effectiveness in a wide range of scenarios makes it a valuable tool in the realm of sorting algorithms.

## Implement Shell Sort
{: #implement}

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
        <th>Shell Sort</th>
        <td>O(n log n)</td>
        <td>O(n log n)</td>
        <td>O(n log n)</td>
        <td>O(n log n)</td>
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

```
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
```

## References
[1] JavatPoint. *Shell Sort Algorithm*. Available at: <https://www.javatpoint.com/shell-sort>. Accessed: March 05, 2024.
{: #ref1}
