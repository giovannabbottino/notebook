---
layout: default
title: Queue
nav_order: 1
description: 'Queue'
grand_parent: Data Structure
parent: List
---

Queue
{: .fs-9}

How to [implement](#implement) a Queue?
{: .fs-6 .fw-300  }


First, let me see if you know what queue is.

Think of a bank, there's a queue, right? The first person to arrive is (probably) the first to be served. And that's a queue! Congratulations, you already know what queue is. Go implement it!

Just kidding.

A queue is a linear structure that follows an order: First in, First out (FIFO) [[1]](#ref1).

It basically has four operations, queuing, unqueuing, front and rear. See image below for illustration.

<a href="{{ site.baseurl }}/assets/images/queue/queue.png" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/queue/queue.png" class="img-fluid" />
</a>

###### From [MORAIS (2018)](#ref2)

- Enqueue: adds an item to the end of the queue
- Rear: Take the last item in line
- Dequeue: removes an item at the beginning of the queue
- Front: get the item from the front of the queue

Why use a queue? In cases where you only need *front* and *rear* access and the order is First In, First Out (FIFO).
{: #why}

## Implement a Queue
{: #implement}

Let's implement it in C!!!

You're going to need a Node, so let's create it. This Node can be a Person or a Car whatever you need, you can change it to whatever you want, this is just an example. But, it needs to have a pointer to the next node, so don't forget about that.

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

Now that we have a Node struct, we have to initialize our Node. Let's say or *info* and we point our *pointer* to *NULL*. Why? Because we still don't know who the next Node will be, but we already know our information.

<a href="{{ site.baseurl }}/assets/images/queue/create_node.png" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/queue/create_node.png" class="img-fluid" />
</a>

###### From Bottino(2021)

```c
// your function to creat a Node 
Node * createNode(){
    Node * node = (Node *) malloc(sizeof(Node));
    node->next = NULL;
    printf("Info:");
    scanf("%d", &node->info);
    return node;
}

// you can call it later as
// Node * node = createNode();
```

We have now our Node with a pointer to another Node. Lets make the Queue.

For the Queue, we are going to need a pointer *front* and *rear* to a Node, and also a *size*.

<a href="{{ site.baseurl }}/assets/images/queue/queue_c.png" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/queue/queue_c.png" class="img-fluid" />
</a>

###### From Bottino(2021)

```c
// your queue 
typedef struct queue{
    Node * front, * rear;
    int size;
}Queue;
```

We can initialize with no *front* or *rear* and *size* equal zero, as follown. Why? Because our Queue is empty.

<a href="{{ site.baseurl }}/assets/images/queue/create_queue.png" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/queue/create_queue.png" class="img-fluid" />
</a>

###### From Bottino(2021)

```c
Queue * createQueue(){
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}
// you can call it later as
// Queue * queue = createQueue();
```

To end our implementation we need to do the Enqueue and the Dequeue. This is because we can access the *front* and *rear* this way:

```c
queue->front;
queue->rear;
```

To populate our Queue we use the Enqueue, and to do so we need a Node and a Queue. That is why our function have those as parameters.

```c
void enqueue(Queue * queue, Node * node){
    // you can call it later as 
    // enqueue(queue, node);
}
```

Now, we can just add our Node in *rear* and *front* of the Queue, and increase the *size*. 

```c
void enqueue(Queue * queue, Node * node){
    queue->front = node;
    queue->rear = node;
    queue->size++;
}
```

However, if you try to do this, you will find that it doesn't work as we thought. Our Queue should tell who is the new *rear* AND who is the previous *rear*. For that, we are going to point our pointer *next* in the *rear* to the new Node. After that, we can make our *rear* be the new Node.

<a href="{{ site.baseurl }}/assets/images/queue/enqueue.gif" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/queue/enqueue.gif" class="img-fluid" />
</a>

###### From Bottino(2021)

So let's create a condition for if it's not empty.

```c
void enqueue(Queue * queue, Node * node){
    // if empty
    // the first node will be also the last
    if(queue->rear == NULL){
        queue->front = node;
        queue->rear = node;
        queue->size++;
    }else{
        // the last but one will be our old rear
        queue->rear->next = node;
        // the last will be our new rear
        queue->rear = node;
        queue->size++;
    }
}
```

And now, you have created and populated your Queue.

Let's make it Dequeue. To dequeue you will only need the Queue itself.

```c
void dequeue(Queue * queue){
    // you can call it later as 
    // dequeue(queue);
}
```

We can just remove the first node. 

```c
void dequeue(Queue * queue){
    free(queue->front);
    queue->size--;
}
```

But, (there is always a but) if you do only that you wont be updanting the new *front*. For do that we are going to be needing a aux Node, it is just the *front*. With this aux, we are going to make the new *front* be the *next* Node in our aux Node. 


<a href="{{ site.baseurl }}/assets/images/queue/dequeue.gif" data-toggle="lightbox">
    <img src="{{ site.baseurl }}/assets/images/queue/dequeue.gif" class="img-fluid" />
</a>

###### From Bottino(2021)

```c
void dequeue(Queue * queue){
    Node * aux = queue->front;
    queue->front = aux->next;
    free(aux);
    queue->size--;
}
```

We are almost in the end. We only need to be certain that the Queue is not empty. Lets make some *ifs*.

```c
void dequeue(Queue * queue){
    if(queue->front == NULL){
        printf("Fila vazia!\n");
    }else{
        Node * aux = queue->front;
        queue->front = aux->next;
        free(aux);
        if(queue->front == NULL){
            queue->rear = NULL;
        }
        queue->size--;
    }
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
    <th>Queue</th><td>Θ(n)</td>	<td>Θ(n)</td>	<td>Θ(1)</td>	<td>Θ(1)</td>	<td>O(n)</td>	<td>O(n)</td>	<td>O(1)</td>	<td>O(1)</td>	<td>O(n)</td>
    </tr>
</tbody>
</table>

## References

[1] GEEKSFORGEEKS, (2021) Queue Data Structure. *GeeksforGeeks*. Available at: <https://www.geeksforgeeks.org/queue-data-structure/>. Accessed: December 21, 2021.
{: #ref1}

[2] MORAIS, J. (2018) RTOS: Uso de Queue para sincronização e comunicação de tarefas. *Embarcados*. Available at: <https://www.embarcados.com.br/rtos-queue-sincronizacao-e-comunicacao/>. Accessed: December 21, 2021.
{: #ref2}
