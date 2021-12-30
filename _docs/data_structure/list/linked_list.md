---
layout: default
title: Linked List
nav_order: 3
description: 'Linked List'
grand_parent: Data Structure
parent: List
---

Linked List
{: .fs-9}

How to [implement](#implement) a Linked List?
{: .fs-6 .fw-300  }

I hope that you already know what is a [list]({{site.baseurl}}/data_structure/list). You can read about it [here]({{site.baseurl}}/data_structure/list). 

There are three types of linked lists: Singly, Doubly, and Circular (Singly or Doubly). 

In singly and doubly, you can find a *head* and a *tail*, the difference remains that in a singly linked list the node references only to the *next* element. A doubly linked list has two pointers, one to the *next* node and another to the *previous* node. In those cases, the *next* in last node and *prev* in the first node reference is equal to NULL. That changes in the circular linked list, at the last node the *next* reference is equal to the *head* and the first node the *prev* reference is equal to the *tail*. You can see the image to understand better. 

<a href="{{ site.baseurl }}/assets/images/list/linked_list.jpg" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/list/linked_list.jpg" class="img-fluid" />
</a>

###### From [KEARNEY (2014)](#ref1)

Why do we have so many lists?
{: #why}

Well, the singly list is used when there is memory limitation or there is no need of searching. When you need to perform search operations, you can use the doubly. As is more efficient in accessing elements, since it is possible to traverse both forward and backwards

Circular lists are useful in applications to repeatedly go around the list. We can traverse the whole list by starting from any point. However, it uses a lot of memory.

My advice, first you have to understand your problem and situation before decide which data structure to use.

Lists has four basic operations: 
- Push: Add a node at the end.
- Pop:  removes the item at the given index
- atPos: A node at a certain position.
- indexOf: Search a node information through the List.

## Implement a Singly Linked List
{: #implement}

Today, right here, right now, I am going to implement a singly linked list, but you can access other implementation on my git.

[See the code](https://github.com/giovannabbottino/notebook/tree/master/data_structure/list)

Just like in the [Queue]({{site.baseurl}}/data_structure/list/queue) or the [Stack]({{site.baseurl}}/data_structure/list/stack) you're going to need a Node, we are going to use a *struct* in C. *Struct* group variables under the same data. The idea is to allow you to store and group data into a single data category

This Node can be a Character or a Book whatever you need, you can change it to whatever you want, this is just an example. But, it needs to have a reference to the *next* Node, we are going to use this pointer as a guide through the List, so don't forget about that.

If you are looking for a Doubly List, add the pointers to the previous Node.

```c
// your struct 
typedef struct node{
    int info;
    struct node *next;
    // struct node *prev;
}Node;
```
And you can initialize it as we did before in the others [data structures]({{site.baseurl}}/data_structure). With the information, but the pointer as *NULL*.

```c
Node *createNode(int info){
    Node * node = (Node *) malloc(sizeof(Node));
    node->info = info;
    node->next =  NULL;
    return node;
}
```

We have our Node iniatialized, so lets make another *struct* in C to represent our List. As said before, we have a *head* and a *tail*, the beging and the end.


```c
typedef struct list{
    int size;
    Node *head, *tail;
} List;
```

Our List is empty so we need to point both *head* and *tail* to null and also set its size to zero.

```c
List *createList(){
    List *l = (List*)malloc(sizeof(List));
    l->head = l->tail = NULL;
    l->size = 0;
    return l;
}
```

To populate the List, we will use the *push* function. This *push* needs a valid List and Node. 

There is two conditions to push, when the list is empty and when the list is not empty. When is empty you need to cast the *head* and the *tail* to be the Node. In others conditions you have to define the *next* in the *tail* to be the new Node. This way, when you push it to the end, it will have a pointer *next* to to the Node.

Now you are ready to finally update the tail to the Node. 

```c
void push(List * list, Node * node){
    if(list->size == 0){
        list->head = node;
        list->tail = node;
        list->size++;
    }else{
        list->tail->next = node;
        list->tail = node;
        list->size++;
    }
}
```

We already saw, basically, everything studying about [Queue]({{site.baseurl}}/data_structure/list/queue) or the [Stack]({{site.baseurl}}/data_structure/list/stack). Now comes the fun part: the *atPos* and the *indexOf*.

*atPos* is a function to access a item in a certain position, will need a List and an *index* of the position. If this *index* is not bettewn the List *size* and zero, it is invalid. Other wise you are going to do a loop through the List and stop it when you find the index.

```c
Node *atPos(List * list, int index){
    if( index<0 || index>list->size){
        printf("Invalid Input!\n");
    }else{
        Node *pointer = list->head;
        for (int j=0; j<list->size; j++){
            if(j == index){
                return pointer;
            }
            pointer = pointer->next;
        }
    }
    return NULL;
}
```

The same logic aplies to indexOf but we use an auxiliar node to help us search for our wanted node throughout the list

```c
int indexOf(List *list, Node *node){
    Node *aux = list->head;
    for (int i=0; i<list->size; i++){
        if ( node->info == aux->info ){
            return i;
        }
        aux = aux->next;
    }
    return -1;
}
```


The *pop*, I promise it is easier to understand if you already have the *atPos*. To *pop* a position in the list, first the position has to be valid. So create a condition to verify it.

```c
void pop(List *list, int index){
    if ( index < 0 || index > list->size)
        printf("Invalid position!\n");
```
Ok, *index* is valid. Now, we have some cases, 1- when the index is at the first position or 2-when the index is at the last position or 3- the index is any other.

Case 1
We are going to need an auxiliar Node that is the first Node in the List. Update the *head* to be the *next* at this auxiliar. With that, you can decrease the *size* and free the auxiliar.

Case 2
We are also going to need an auxiliar Node, but this time is the last but one in the List. Free the last position. Update the *tail* to be the auxiliar and you can decrease the *size*.

Case 3
This time, colect the node *after* and *before* the index. Free the node at the *index* and update the *next* in the *before* to the *after*. 

```c
void pop(List *list, int index){
    if ( index < 0 || index > list->size){
        printf("Invalid position!\n");
    } else if (index==0){
        Node * aux = list->head;
        list->head = aux->next;
        free(aux);
    } else if(index == list->size - 1){ 
        Node *aux = atPos(list, list->size - 2);
        free(atPos(list,index));
        aux->next = NULL;
        list->tail = aux;
    } else{
        Node *after = atPos(list, index+1);
        Node *before = atPos(list, index-1);
        free(atPos(list,index));
        before->next = after;
    }
    list->size--;
}
    
```

## The [Big-O notation]({{site.baseurl}}/algorithm/computational_complexity#bigO)
{: #bigO}

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
        <th>Singly-Linked List</th>	<td>O(n)</td>	<td>O(n)</td>	<td>O(1)</td>	<td>O(1)</td>	<td>O(n)</td>	<td>O(n)</td>	<td>O(1)</td>	<td>O(1)</td>	<td>O(n)</td>
    </tr>
    <tr>
        <th>Doubly-Linked List</th>	<td>O(n)</td>	<td>O(n)</td>	<td>O(1)</td>	<td>O(1)</td>	<td>O(n)</td>	<td>O(n)</td>	<td>O(1)</td>	<td>O(1)</td>	<td>O(n)</td>
    </tr>
    <tr>
        <th>Circular Linked List</th>	
        <td>O(n)</td>	
        <td>O(n)</td>
        <td>O(n)</td>
        <td>O(n)</td>
        <td>O(n)</td>
        <td>O(n)</td>
        <td>O(n)</td>
        <td>O(n)</td>
        <td>O(1)</td>
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

typedef struct node{
    int info;
    struct node *next;
}Node;

typedef struct list{
    int size;
    Node *head, *tail;
} List;

Node *createNode(int info);
List *createList();
void push(List *list, Node *node);
void pop(List *list, int index);
Node *atPos(List *list, int index);
int indexOf(List *list, Node *node);

int main(){

    List *list = createList();
    Node * node = createNode(10);
    push(list, node);

    Node * node2 = createNode(5);
    int index = indexOf(list, node2);

    Node * node3 = atPos(list, 0);
    
    pop(list, 0);

    return 0;
}

Node *createNode(int info){
    if(info >= 0){
        Node * node = (Node *) malloc(sizeof(Node));
        node->info = info;
        return node;
    }else{
        return NULL;
    }
}

List *createList(){
    List *l = (List*)malloc(sizeof(List));
    l->head = l->tail = NULL;
    l->size = 0;
    return l;
}

void push(List * list, Node * node){
    if(list->size == 0 ){
        list->head = node;
        list->tail = node;
        list->size++;
    }else{
        list->tail->next = node;
        list->tail = node;
        list->size++;
    }
}

void pop(List *list, int index){
    if ( index < 0 || index > list->size){
        printf("Invalid position!\n");
    } else if (index==0){
        Node * aux = list->head;
        list->head = aux->next;
        free(aux);
    } else if(index == list->size - 1){ 
        Node *aux = atPos(list, list->size - 2);
        free(atPos(list,index));
        aux->next = NULL;
        list->tail = aux;
    } else{
        Node *after = atPos(list, index+1);
        Node *before = atPos(list, index-1);
        free(atPos(list,index));
        before->next = after;
    }
    list->size--;
}

Node *atPos(List * list, int index){
    if( index < 0 || index > list->size){
        printf("Invalid Input!\n");
    }else{
        int i=0;
        Node *aux = list->head;
        while(aux != NULL){
            if(i == index){
                return aux;
            }
            i++;
            aux = aux->next;
        }
    }
    return NULL;
}

int indexOf(List *list, Node *node){
    Node *aux = list->head;
    for (int i=0; i< list->size; i++){
        if ( node->info == aux->info ){
            return i;
        }
        aux = aux->next;
    }
    return -1;
}
```

## References

[1] KEARNEY, S. (2014) LIST PROCESSING. *SlidePlayer*. Available at: <https://slideplayer.com/slide/1608081/>. Accessed: December 27, 2021.
{: #ref1}
