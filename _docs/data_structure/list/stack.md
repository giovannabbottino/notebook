---
layout: default
title: Stack
nav_order: 2
description: 'Stack'
grand_parent: Data Structure
parent: List
---

Stack
{: .fs-9}

How to [implement](#implement) a Stack?
{: .fs-6 .fw-300  }

As with other one-sided conversations, I'm going to assume you don't know what a Stack is. Well, let's think about household chores, more specifically doing the dishes.

When you live with a lot of people in the same house, do the dishes is something you hate. To make it easier, you organize the dishes before it, one above the other. And when you actually start, the last dish, the first in a Stack, is the first you clean.

A Stack is a linear structure that follows an order: Last In, First Out (LIFO) [[1]](#ref1).

It basically has three operations, Push, Pop and *top*. See image below for illustration.

<a href="{{ site.baseurl }}/assets/images/stack/stack.png" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/stack/stack.png" class="img-fluid" />
</a>

###### From [SCIENCE](#ref1)

- Push: adds an item to the beginning of the stack
- Pop: removes an item at the beginning of the stack
- Top: get the first item in the stack

Why use a stack? In cases where you only need *top* access and the order is Last In, First Out (LIFO).
{: #why}

## Implement a Stack
{: #implement}

Just like in the [Queue]({{site.baseurl}}/data_structure/list/queue) you're going to need a Node, we are going to use a *struct* in C. *Struct* group variables under the same data. The idea is to allow you to store and group data into a single data category

This Node can be a Plate or a Cup whatever you need, you can change it to whatever you want, this is just an example. But, it needs to have a pointer to the next Node, we are going to use this pointer as a guide through the Stack, so don't forget about that.

<a href="{{ site.baseurl }}/assets/images/queue/node.png" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/queue/node.png" class="img-fluid" />
</a>

###### From Bottino(2021)

```c
// your struct 
typedef struct node{
    int info;
    struct node *next;
}Node;
```

Now that we have a Node struct, we have to initialize our Node. Let's say our *info* and we point our *pointer* to *NULL*. Why? Because we still don't know who the next Node will be, but we already know our information.

<a href="{{ site.baseurl }}/assets/images/queue/create_node.png" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/queue/create_node.png" class="img-fluid" />
</a>

###### From Bottino(2021)

```c
// your function to creat a Node 
Node * createNode(int info){
    Node * node = (Node *) malloc(sizeof(Node));
    node->next = NULL;
    node->info = info;
    return node;
}
}

// you can call it later as
// Node * node = createNode(info);
```

We now have our Node with a pointer to another Node. Lets make the Stack, how is also a *struct* in C.

For the Stack, we are need to know the Nodes at the *top*, for that we need one pointer. We are going to use the *top* to know which Node is the first. Also its important to know its *size*

<a href="{{ site.baseurl }}/assets/images/stack/stack_c.png" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/stack/stack_c.png" class="img-fluid" />
</a>

###### From Bottino(2021)

```c
// your stack 
typedef struct stack{
    Node * top;
    int size;
}Stack;
```

When we initialize our Stack we need to point top to null and also set size as zero. why? Because our stack is empty

<a href="{{ site.baseurl }}/assets/images/stack/create_stack.png" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/stack/create_stack.png" class="img-fluid" />
</a>

###### From Bottino(2021)

```c
Stack * createStack(){
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}
// you can call it later as
// Stack * stack = createStack();
```

We can get the first item in the Stack with the *top* as follows:

```c
stack->top;
```

To populate our Stack we use the Push, and to do so we need a Node and a Stack. That is why our function have those as parameters.

```c
void push(Stack * stack, Node * node){
    // you can call it later as 
    // push(stack, node);
}
```

Now, we can just add our Node to the *top* of the Stack, and also increase the *size*. But remember, like we did in [Queue]({{site.baseurl}}/data_structure/list/queue), we need to point our pointer *next* to, in this case, the *top*. We have to do this before updating the *top*, because we don't want to lose this Node that is below.

```c
void push(Stack * stack, Node * node){
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}
```

When the Stack is empty, you don't need to about it. Remeber, we initialize it with *NULL*.

Let's make it Pop. To Pop you will only need the Stack itself.

```c
void pop(Stack * stack){
    // you can call it later as 
    // pop(stack);
}
```

We can just remove the first node. As we saw in the [Queue]({{site.baseurl}}/data_structure/list/queue) that we are going to need an auxiliary Node, *aux*. In this case, a pointer to the *top*, the first Node in the Stack. Without storing the old *top* you wont have access to the *next* Node in the Stack, and you wont be able to update the *top* of your Stack

Don't forget to add the case where the Stack is empty.

```c
void pop(Stack * stack){
    if(isEmpty(stack)){
        return;
    }
    Node * aux = stack->top;
    stack->top = aux->next;
    free(aux);
    stack->size--;
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
    <th>Stack</th><td>O(n)</td>	<td>O(n)</td>	<td>O(1)</td>	<td>O(1)</td>	<td>O(n)</td>	<td>O(n)</td>	<td>O(1)</td>	<td>O(1)</td>	<td>O(n)</td>
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

typedef struct stack{
    Node * top;
    int size;
}Stack;

Stack * createStack();
Node * createNode(int info);
void push(Stack * stack, Node * node);
void pop(Stack * stack);

int main(){
    int info = 10;
    Stack * stack = createStack();
    Node * node = createNode(info);
    
    push(stack, node);
    
    top(stack);
    
    return 0;
}

Stack * createStack(){
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

Node * createNode(int info){
    Node * node = (Node *) malloc(sizeof(Node));
    node->next = NULL;
    node->info = info;
    return node;
}

void push(Stack * stack, Node * node){
    if(node){
        node->next = stack->top;
        stack->top = node;
        stack->size++;
    }
}

void pop(Stack * stack){
    if(isEmpty(stack)){
        return;
    }
    Node * aux = stack->top;
    stack->top = aux->next;
    free(aux);
    stack->size--;
}
```

## References
[1] SCIENCE, C. Stack. *Isaac Computer Science*. Available at: <https://isaaccomputerscience.org/concepts/dsa_datastruct_stack?examBoard=all&stage=all/>. Accessed: December 23, 2021.
{: #ref1}