---
layout: default
title: List
nav_order: 1
description: 'What is a list?'
parent: Data Structure
has_children: true
---

List
{: .fs-9}

What is a list?
{: .fs-6 .fw-300  }

When you think of a list, what comes to your mind? This **IS** a one sided conversation, so I assume your answer is "connected items written consecutively, one under the other". *Thanks, Google*.

Now try connecting it to [data structures]({{site.baseurl}}/data_structure). How could you implement this?

Connected items of same type stored in contiguous memory [[1]](#ref1). Well no. This is an Array.

In an array, each item stored in contiguous memory is uniquely identified by its index [[1]](#ref1). In C, you can declare it as follows.

```c
// specifying size
int arr[10];

// specifying size and initializing elements
int arr2[10] = { 1, 2, 3, 4 }
```

As you can see, in a non-dynamic array, its size is fixed. Once the array is initialized with values and allocated space in memory, you cannot change its size. Hence, it is a memory-efficient [data structure]({{site.baseurl}}/data_structure) where each element occupies a single space. It is best suited for frequent accessing of elements regardless of their position [[4]](#ref4).

So perhaps a linked list is a kind of dynamic array that has the ability to automatically resize after inserting or deleting elements?

No.

That is a vector.

Vectors elements are also stored in continuous memory locations so they can be accessed and traversed using iterators. Here, an element is inserted at the end of the vector [[4]](#ref4).

A typical vector implementation grows by doubling its allocated space instead of incrementing it by 1. Memory reallocation is generally an expensive operation in vectors, it takes a lot of memory, due to its dynamic nature. Unlike arrays, you use vectors if you need to add or remove elements frequently [[4]](#ref4).

Finally, answering the first question: list is a linear data structure in which elements are not stored in contiguous memory locations. In a linked list each elements are nodes that contains a data field and a reference to the next node [[3]](#ref3).

It has non-contiguous memory and there is no pre-allocated memory. Each element requires extra space for the node that contains the element, including pointers to the next and previous element in the list. Different from vectors insertion and deletion are cheap no matter where it occurs [[4]](#ref4). 

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
        <th>Vector/Array</th>
        <td >Θ(1)</td >	<td >Θ(n)</td >	<td >Θ(n)</td >	<td >Θ(n)</td >	<td >O(1)</td >	<td >O(n)</td >	<td >O(n)</td >	<td >O(n)</td >	<td >O(n)</td >
    </tr>
    <tr>
<th>Doubly-Linked List</th>	<td >Θ(n)</td >	<td >Θ(n)</td >	<td >Θ(1)</td >	<td >Θ(1)</td >	<td >O(n)</td >	<td >O(n)</td >	<td >O(1)</td >	<td >O(1)</td >	<td >O(n)</td >
</tr>
</tbody>
</table>

Here we are going to implement some lists in C: 
- Queue
- Stack
- Linked List
- Linked Circular List
- Doubly Linked List
- Doubly Linked Circular List

## References

[1] GEEKSFORGEEKS, (2021) Array Data Structure. *GeeksforGeeks*. Available at: <https://www.geeksforgeeks.org/array-data-structure/>. Accessed: December 21, 2021.
{: #ref1}

[2] GEEKSFORGEEKS, (2021) Difference Between Vector and List. *GeeksforGeeks*. Available at: <https://www.geeksforgeeks.org/difference-between-vector-and-list/>. Accessed: December 21, 2021.
{: #ref2}

[3] GEEKSFORGEEKS, (2021) Linked List Data Structure. *GeeksforGeeks*. Available at: <https://www.geeksforgeeks.org/arrays-in-c-cpp/>. Accessed: December 21, 2021.
{: #ref3}

[4] TEAM, E. C++ Vector vs. Array. *Educative*. Available at: <https://www.educative.io/edpresso/cpp-vector-vs-array>. Accessed: December 21, 2021.
{: #ref4}