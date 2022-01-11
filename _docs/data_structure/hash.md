---
layout: default
title: Hash Table
nav_order: 3
description: 'What is a hash table?'
parent: Data Structure
---

Hash Table
{: .fs-9}

What is a Hash Table?
{: .fs-6 .fw-300  }

A hash table or associative array is a key value lookup. In others words, it is a [data structure]({{site.baseurl}}/data_structure) that stores elements in key-value pairs where the key is a unique integer that is used for indexing the values and the value is the data associated with keys.

You use hash tables because they have a time complexity of O(1). Using a hash table is one of the fastest ways.
{: #why} 

In a hash table, a new index is processed using the keys. And, the element corresponding to that key is stored in the index. This process is called hashing.

Hashing is a technique or process of mapping keys, values into the hash table. The efficiency of mapping depends on the efficiency of the hash function used.

Let a hash function H(x) maps the value x at the index x-1. For example if the list of values is [1,2,3,4,5] it will be stored at positions {0,1,2,3,4} in the Hash table. However, when the hash function generates the same index for multiple keys, there will be a hash collision.

The hash collision can be solved using chaining or open addressing.

## Hash Collision

### Chaining

This solution uses a [Doubly Linked List]({{site.baseurl}}/data_structure/list/linked_list) to store these elements in the same index. For example, if *j* is the index for multiple elements, it contains a pointer to the head of the list of elements. If no element is present, j contains NIL.

### Open Addressing

In this solution we store only one element into the same slot. There are different techniques like Linear Probing, Quadratic Probing and Double hashing. 

#### Linear Probing and Quadratic Probing

In these collision cases, we resolve by checking the next slot. Linear polling increments the value linearly and Quadratic increments the value with an arbitrary quadratic polynomial.

#### Double hashing

In this case of collision we apply another hash function <s>or the same with the differents parameters</s>.

## Implement a Hash Table
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
        <th>Hash Table</th>
        <td >N/A</td ><td >O(1)</td ><td >O(1)</td ><td >O(1)</td ><td >N/A</td >	<td >O(n)</td >	<td >O(n)</td >	<td >O(n)</td >	<td >O(n)</td >
    </tr>
</tbody>
</table>

## Code
{: #code}

```c
```

## References

[1] PROGRAMIZ. Hash Table. *Programiz*. Available at: <https://www.programiz.com/dsa/hash-table>. Accessed: January 09, 2022.
{: #ref1}