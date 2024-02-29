---
layout: default
title: Merge Sort
nav_order: 5
description: 'Merge Sort'
parent: Sorting Algorithms
---

Merge Sort
{: .fs-9}

Merge Sort is a sorting algorithm that follows the "divide and conquer" strategy to efficiently sort a list of elements. It works by recursively dividing the unsorted list into smaller sublists until each sublist contains only one element. Then, it repeatedly merges the sublists in a sorted order until the entire list is sorted.

How Merge Sort Works?
{: .fs-6 .fw-300  }

1. Divide: The unsorted list is divided into two halves recursively until each sublist contains only one element.
2. Conquer: Once the sublists are sufficiently small (containing only one element), they are merged back together in a sorted order.
3. Merge: During the merge phase, the sublists are merged pairwise, with elements being compared and rearranged to form larger sorted sublists. This process continues until the entire list is sorted.

Why Use Merge Sort
{: .fs-6 .fw-300  }

Merge Sort offers several advantages:

- It has a time complexity of O(n log n) in all cases, making it efficient even for large datasets.
- It guarantees stable sorting, meaning that elements with equal keys remain in their original order after sorting.
- Merge Sort is well-suited for sorting linked lists, as it does not require random access to elements.

## Implement a Graph
{: #implement}
