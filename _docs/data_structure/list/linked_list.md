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

I hope that you already know what is a [list]({{site.baseurl}}/data_structure/list). If you don't, go read it. 

There are three types of linked lists: Singly, Doubly, and (Singly or Doubly) Circular. 

In both, you can find a head and a tail, the difference remains that in a singly linked list the node references only to the next. A doubly linked list has two, one to the next node and another to the previous node. In this case, the next reference in last node is equal to NULL. That changes in the circular linked list, the reference is equal to the head. You can see the image to understand better. 

<a href="{{ site.baseurl }}/assets/images/list/linked_list.jpg" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/list/linked_list.jpg" class="img-fluid" />
</a>

###### From [KEARNEY (2014)](#ref1)

Why do we have so many lists?
{: #why}

Well, the singly is used when there is memory limitation or there is no need of searching. When you need to perform search operations, you can use the doubly. As is more efficient in accessing elements, since it is possible to traverse both forward and backwards

Even better, the circular list. Circular lists are useful in applications to repeatedly go around the list. We can traverse the whole list by starting from any point. However, it uses a lot of memory.

My advice, first you have to understand your problem and situation before decide what data structure to use.

It has four basic operations: 
- Push: Add a node at the end.
- Pop: Remove a node at the start.
- atPos: A node at a certain position.
- indexOf: Search an information through the List.

## Implement a Singly Linked List
{: #implement}

Today, right here, right now, I am going to implement a singly linked list, buut you can access other implementation on my git.

[See the code](https://github.com/giovannabbottino/notebook/)

Just like in the [Queue]({{site.baseurl}}/data_structure/list/queue) or the [Stack]({{site.baseurl}}/data_structure/list/stack) you're going to need a Node, we are going to use a *struct* in C. *Struct* group variables under the same data. The idea is to allow you to store and group data into a single data category

This Node can be a Character or a Book whatever you need, you can change it to whatever you want, this is just an example. But, it needs to have a reference to the *next* Node, we are going to use this pointer as a guide through the List, so don't forget about that.

If you are looking for a Doubly List, add the previous Node.

```c
// your struct 
typedef struct node{
    int info;
    struct node *next;
    // struct node *prev;
}Node;
```
And you can initialize as we did before in others [data structures]({{site.baseurl}}/data_structure). With the information, but the pointer as *NULL*.

```c
Node *createNode(int info){
    Node * node = (Node *) malloc(sizeof(Node));
    node->info = info;
    node->next =  NULL;
    return node;
}
```

We have our Node iniatialize, so lets make another *struct* in C to represent our List. As said before, we have a *head* and a *tail*, the beging and the end.


```c
typedef struct list{
    int size;
    Node *head, *tail;
} List;
```

Our List is empty so we need to point both *head* and *tail* to null and also set size as zero.

```c
List *createList(){
    List *l = (List*)malloc(sizeof(List));
    l->head = l->tail = NULL;
    l->size = 0;
    return l;
}
```

To populate the List, the *push* can be used. This *push* need a valid List and Node. You have to define the *next* in the *tail* to be the new Node. This way, when you push it to the end, it will have a *next* pointer to to the Node.

Now you are ready to finally update the tail to the Node. 

```c
void push(List * list, Node * node){
    list->tail->next = node;
    list->tail = node;
    list->size++;
}
```

The *pop*, I promise it is easier to understand. To *pop* a list, first it needed to have an item, if the *size* is equal to zero you don't need to *pop* it. If the *size* is different to zero, we are going to need an auxiliar Node that is the first Node in the List. 

Update the *head* to be the *next* at this auxiliar. With that, you can decrease the *size* and free the auxiliar.

```c
void pop(List * list){
    if(list->size == 0){
        return;
    }
    Node * aux = list->head;

    list->head = aux->next;
    free(aux);
    list->size--;
}
```

We already saw, basically, everything studying about [Queue]({{site.baseurl}}/data_structure/list/queue) or the [Stack]({{site.baseurl}}/data_structure/list/stack). Now comes the fun part: the *atPos* and the *indexOf*.

*atPos*, a function to access a item in a certain position, will need a List and an *index* of the position. If this *index* is not bettewn the List *size* and zero, it is invalid. In cases you can continue, you are going to do a loop through the List and stop it if you find the index.

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

The same logic applies to *indexOf*. Use the auxiliar to search the right Node through the List.

```c
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
/*Giovanna Borges Bottino giovannabbottino@gmail.com*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct Node *next;
    
} Node;

typedef struct list{
    int size;
    Node *head, *tail;
} List;

Node *createNode(int info);
List *createList();
void push(List *list, Node *node);
void pop(List *list);
Node *atPos(List *list, int index);
int indexOf(List *list, Node *node);

int main(){

    List *list = createList();
    Node * node = createNode(10);
    push(list, node);

    Node * node2 = createNode(5)
    index = indexOf(list, node2);

    Node * node = atPos(list, 0)
    
    pop(list);

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
    list->tail->next = node;
    list->tail = node;
    list->size++;
}

void pop(List * list){
    if (isEmpty(list)){
        return;
    }
    Node * aux= list->head;
    list->head = aux->next;
    free(aux);
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
