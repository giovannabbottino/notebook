---
layout: default
title: Bubble Sort
nav_order: 1
description: 'Bubble Sort'
parent: Sorting Algorithms
---

Bubble Sort
{: .fs-9}

Bubble Sort is one of the simplest sorting algorithms used to arrange elements in a list in a specified order. It's called "Bubble Sort" because smaller elements "bubble" to the top (beginning) of the list while larger elements sink to the bottom (end) through successive iterations.

How Bubble Sort Works?
{: .fs-6 .fw-300  }

1. Compare Adjacent Elements: Starting from the beginning of the list, compare each pair of adjacent elements.
2. Swap if Necessary: If the current pair of elements is out of order (for ascending sort, if the first element is greater than the second), swap them.
3. Repeat: Move to the next pair and repeat the comparison and swapping process until you reach the end of the list.
4. Passes: Repeat the entire process for the entire list. After each full pass through the list, the next largest element will have bubbled up to its correct position.
5. Optimization: If no swaps are made during a pass, the list is already sorted, and you can terminate the algorithm early.

### Detailed Example:
Let's sort the list [5, 2, 9, 1, 5] in ascending order:

1. First Pass:
   
- Compare 5 and 2, swap -> [2, 5, 9, 1, 5]
- Compare 5 and 9, no swap -> [2, 5, 9, 1, 5]
- Compare 9 and 1, swap -> [2, 5, 1, 9, 5]
- Compare 9 and 5, swap -> [2, 5, 1, 5, 9]

2. Second Pass:

- Compare 2 and 5, no swap -> [2, 5, 1, 5, 9]
- Compare 5 and 1, swap -> [2, 1, 5, 5, 9]
- Compare 5 and 5, no swap -> [2, 1, 5, 5, 9]
- Compare 5 and 9, no swap -> [2, 1, 5, 5, 9]

3.Third Pass:

- Compare 2 and 1, swap -> [1, 2, 5, 5, 9]
- Compare 2 and 5, no swap -> [1, 2, 5, 5, 9]
- Compare 5 and 5, no swap -> [1, 2, 5, 5, 9]
- Compare 5 and 9, no swap -> [1, 2, 5, 5, 9]

4. Fourth Pass:
- No swaps are needed, so the list is sorted -> [1, 2, 5, 5, 9]

Why Use Bubble Sort
{: .fs-6 .fw-300  }

- Educational Purposes: Bubble Sort is often taught as an introduction to sorting algorithms due to its simplicity and ease of understanding.
- Small Data Sets: It can be efficient for very small datasets or nearly sorted datasets because its simplicity can outweigh the overhead of more complex algorithms in such cases.
- Stable Sort: Bubble Sort is stable, meaning it preserves the relative order of equal elements, which can be important for certain applications.

Limitations
{: .fs-6 .fw-300  }

- Inefficiency for Large Data Sets: Bubble Sort has a worst-case and average time complexity of 𝑂(𝑛2), where 𝑛 is the number of elements in the list. This makes it inefficient for large datasets compared to more advanced algorithms like Quick Sort, Merge Sort, or Heap Sort, which have better average and worst-case performance.
- Number of Comparisons and Swaps: Bubble Sort performs many comparisons and swaps, which can be inefficient for lists with many elements.

## Implement 
{: #implement}

First, we will need some macros. 
- less: `#define less(A,B) ((A) < (B))` : A macro to check if A is less than B
- exch: `#define exch(A,B) { int t; t=A; A=B; B=t; }` :  A macro to exchange the values of A and B.
- cmpexch: `#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }` : A macro that compares A and B, and exchanges them if B is less than A.

And the Bubble Sort Function, which will compare and exchange the elements at the list

```
void bubble(Item *list, int l, int r) { 
   int i, j;
   for(i=l; i<r; i++)
       for(j=l+1; j<=r; j++)
           cmpexch(list[j-1], list[j]);
}
```

## The [Big-O notation]({{site.baseurl}}/algorithm/computational_complexity#bigO)

<table>
<thead>
    <tr>
        <th id="str" scope="col">
            Data Structure / Algorithm
        </th>
        <th id="time" scope="col" class="span" colspan="4">
            Time Complexity
        </th>
        <th id="wr" scope="col">
            Space Complexity
        </th>
    </tr>
</thead>
<tbody>
    <tr>
        <th></th>
        <th>Best Case</th>
        <th>Average Case</th>
        <th>Worst Case</th>
    </tr>
    <tr>
        <th>Bubble Sort</th>
        <td>O(n)</td>
        <td>O(n<sup>2</sup>)</td>
        <td>O(n<sup>2</sup>)</td>
        <td>O(1)</td>
    </tr>
</tbody>
</table>

## Code
{: #code}

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;
#define less(A,B) ((A) < (B))
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
```
