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

This solution uses a [Doubly Linked List]({{site.baseurl}}/data_structure/list/linked_list) to store these elements in the same index. 

### Open Addressing

In this solution we store only one element into the same slot. There are different techniques like Linear Probing, Quadratic Probing and Double hashing. 

#### Linear Probing and Quadratic Probing

In these collision cases, we resolve by checking the next slot. Linear polling increments the value linearly and Quadratic increments the value with an arbitrary quadratic polynomial.

#### Double hashing

In this case of collision we apply another hash function <s>or the same with the differents parameters</s>.

## Implement a Hash Table
{: #implement}

As always our [data structure]({{site.baseurl}}/data_structure) will use a struct to group variables under the same data. This is our Node with a key and value.

```c
struct node 
{
	int key;
	int value;
};

Node * createNode(int key, int data){
    Node* node = (Node *)malloc(sizeof(Node));
 
    node->key = key;
    node->data = data;
    return node;
    // you can call it as Node * node = createNode(int, int);
}
```

Our hash table will be a [list]({{site.baseurl}}/list) of Nodes and need to store it size and capacity. Also, we are going to use a constant value CAPACITY not only here but in all code.

```c
#define CAPACITY 10

typedef struct hash_table
{
  int capacity;
  int size;
  struct node **array;
}Hash_table;

Hash_table * createHashTable(){
    Hash_table* hash_table = (Hash_table *)malloc(sizeof(Hash_table));

    hash_table->size = 0;
    hash_table->capacity = CAPACITY;
    hash_table->array = calloc((size_t)hash_table->capacity, sizeof(Node*));

    return hash_table;
    // you can call it as Hash_table * hash_table = createHashTable();
}
```

And will be hashed by the key and capacity. A simple and an example of hash function.

```c
int hashing(int key){
	return (key % CAPACITY);
}
```

Now, we can implement the three main function in a hash table. Push, pop and search.

First, lets populate it. We use the hash function here, to collect the index to the array in the hash table. 
```c
Hash_table * push(Hash_table * hash_table, Node * node){
    int index = hashing(node->key) + (hashing(node->key) * attempt);

    hash_table->array[index] = node;
    hash_table->size++;

    return hash_table;
}
```

This way, could work, but in case of collision it is not that effective. When do we know that happened a collision? Just check the position, if is not null, is not empty then is a collision. 

In cases of collision this example will use Double hashing. Create a variable attempt to store how many attempts we have made and help with the double hashin. With this we can control how many times it will recursivelly call push, and stop when it has reached the capacity of the hash table.

```c
int attempt = 0;

Hash_table * push(Hash_table * hash_table, Node * node){
    int index = hashing(node->key) + (hashing(node->key) * attempt);

    Node * at_pos = hash_table->array[index];

    if (at_pos == NULL){
        hash_table->array[index] = node;
        hash_table->size++;
        attempt = 0;
    } else if (hash_table->capacity == attempt){
        printf("There isnt space left\n");
    } else{
        attempt++;
        hash_table = push(hash_table, node);
    }
    return hash_table;
}
```

For the pop, we use a loop to verify if the contest of the position is the same as in the Node. The hasing function and attempt variable are also used here, to make the search for the Node quicker.

```c
void pop(Hash_table * hash_table, Node * node) {
    int index = hashing(node->key) + (hashing(node->key) * attempt);
    Node * closestNode = hash_table->array[index];
    while (closestNode != NULL) {
        if (closestNode->key == node->key &&  closestNode->data == node->data) {
            free(closestNode);
            hash_table->array[index] = NULL;
            attempt = 0;
            break;
        }
        attempt++;
        index = hashing(node->key) + (hashing(node->key) * attempt);
        closestNode = hash_table->array[index];
    } 
    hash_table->size--;
}
```

The search follown the same logic as in the pop, we use a loop to search for the Node, and use the hashing function and attempt variable to make it quicker.
```c
Node * search(Hash_table * hash_table, int key) {
    int index = hashing(key) + (hashing(key) * attempt);
    Node * closestNode = hash_table->array[index];
    while (closestNode != NULL) {
        if (closestNode->key == key) {
            attempt = 0;
            return closestNode;
        }
        attempt++;
        index = hashing(key) + (hashing(key) * attempt);
        closestNode = hash_table->array[index];
    }
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
        <th>Hash Table</th>
        <td >N/A</td ><td >O(1)</td ><td >O(1)</td ><td >O(1)</td ><td >N/A</td >	<td >O(n)</td >	<td >O(n)</td >	<td >O(n)</td >	<td >O(n)</td >
    </tr>
</tbody>
</table>

## Code
{: #code}

```c
/*
 * Giovanna Borges Bottino 
 * giovannabbottino@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

typedef struct node
{
  int key;
  int data;
}Node;

typedef struct hash_table
{
  int capacity;
  int size;
  struct node **array;
}Hash_table;

int attempt = 0;

int hashing(int key);
Node * createNode(int key, int data);
Hash_table * createHashTable();
Hash_table * push(Hash_table * hash_table, Node * node);
void pop(Hash_table * hash_table, Node * node);
Node * search(Hash_table * hash_table, int key);

int main(){

    Hash_table * hash_table = createHashTable();
    Node * node = createNode(1, 1);

    hash_table = push(hash_table, node);

    Node * searchNode = search(hash_table, node->key);

    printf("Key: %d\tData: %d\n", searchNode->key, searchNode->data);

    pop(hash_table, node);

    return 0;
}

int hashing(int key){
	return (key % CAPACITY);
}

Node * createNode(int key, int data){
    Node* node = (Node *)malloc(sizeof(Node));
 
    node->key = key;
    node->data = data;
    return node;

}

Hash_table * createHashTable(){
    Hash_table* hash_table = (Hash_table *)malloc(sizeof(Hash_table));

    hash_table->size = 0;
    hash_table->capacity = CAPACITY;
    hash_table->array = calloc((size_t)hash_table->capacity, sizeof(Node*));

    return hash_table;
}

Hash_table * push(Hash_table * hash_table, Node * node){
    int index = hashing(node->key) + (hashing(node->key) * attempt);

    Node * at_pos = hash_table->array[index];

    if (at_pos == NULL){

        hash_table->array[index] = node;
        hash_table->size++;
        attempt = 0;
    } else if (hash_table->capacity == attempt){
        printf("There isnt space left\n");
    } else{
        attempt++;
        hash_table = push(hash_table, node);
    }
    return hash_table;
}

void pop(Hash_table * hash_table, Node * node) {
    int index = hashing(node->key) + (hashing(node->key) * attempt);
    Node * closestNode = hash_table->array[index];
    while (closestNode != NULL) {
        if (closestNode->key == node->key &&  closestNode->data == node->data) {
            free(closestNode);
            hash_table->array[index] = NULL;
            attempt = 0;
            break;
        }
        attempt++;
        index = hashing(node->key) + (hashing(node->key) * attempt);
        closestNode = hash_table->array[index];
    } 
    hash_table->size--;
}

Node * search(Hash_table * hash_table, int key) {
    int index = hashing(key) + (hashing(key) * attempt);
    Node * closestNode = hash_table->array[index];
    while (closestNode != NULL) {
        if (closestNode->key == key) {
            attempt = 0;
            return closestNode;
        }
        attempt++;
        index = hashing(key) + (hashing(key) * attempt);
        closestNode = hash_table->array[index];
    }
}
```

## References

[1] PROGRAMIZ. Hash Table. *Programiz*. Available at: <https://www.programiz.com/dsa/hash-table>. Accessed: January 09, 2022.
{: #ref1}