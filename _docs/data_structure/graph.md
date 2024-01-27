---
layout: default
title: Graph
nav_order: 4
description: 'What is a graph?'
parent: Data Structure
---

Graph
{: .fs-9}

What is a Graph?
{: .fs-6 .fw-300  }

Imagine a graph is like a bunch of dots (vertices) that are connected by lines (edges). Each dot is a special point, and the lines show how these points are related to each other. It's like connecting the dots with lines to create a picture.

In computer science, we use graphs to show how things are connected. The dots are called vertices, and the lines connecting them are called edges. Unlike when we write in a straight line, a graph lets us connect dots in all sorts of interesting ways.

When we want to make a graph in a computer, we have to create a plan for how the dots and lines will be stored. This plan helps the computer understand and remember all the connections between the dots.

So, in simple terms, a graph is like connecting dots with lines to represent relationships between different things. It's a cool way for computers to understand how stuff is linked together!

Why use a Graph?
{: #why} 

Graph theory is like a superpower that helps us understand and solve problems in different areas. Let's check out some cool places where graph theory is at work!

- Electrical Engineering:

Imagine you're designing a super cool circuit for gadgets. Graph theory helps in creating the perfect connections between the electronic parts. We call these connections "topologies," and they have names like star, bridge, series, and parallel. It's like making sure all the parts talk to each other in the best way!

- Computer Science:

In the world of computers, graph theory is like a superhero algorithm! Think of it as a set of instructions that help computers solve problems. Algorithms like Kruskal's, Prim's, and Dijkstra's are like the heroes of the computer world, making sure things run smoothly.

- Computer Network:

Have you ever wondered how all the computers in your house or school are connected? Graph theory plays a big role! It helps us understand how these computers talk to each other in a network.

- Science:

Even in the tiniest things, like the structure of molecules or DNA, graph theory is there! It helps scientists draw pictures (graphs) to understand how these tiny building blocks connect and work together.

- Linguistics:

Ever heard of a language superhero? Graph theory helps us understand the rules of languages. The way words are put together in sentences and the structure of languages are like big word puzzles, and graphs help solve them!

- General Stuff:

If you're planning a road trip and want to figure out the best route between cities, guess what? Graph theory comes to the rescue! Also, when you look at your family tree, that's like a special kind of graph called a tree.
Graph theory is like a secret code that helps us understand and solve puzzles in all these cool areas. It's like having a friend who can connect the dots for us in the most amazing ways!

### Types of Graphs

Hey there, curious mind! Let's talk about different ways things can be connected using something called graphs. Think of graphs like maps that help us understand how things relate to each other.

- Friendship Circles - Undirected Graphs:

Imagine you have a bunch of friends, and you all like each other equally. That's an "Undirected Graph"! It's like a friendly web where connections go both ways. You can easily see who's friends with who.

- One-Way Streets - Directed Graphs:
  
Now, picture roads where you can only go in one direction. That's a "Directed Graph." It's like having streets with arrows, showing you can travel from one place to another, but not necessarily the other way around.

- Star Connections - Star Graphs:

Think about a central point connected to other points. This is a "Star Graph." It's like having one main thing that's linked to everything else. The connections go from the center to the outer points, like the rays of a star.

- Parallel Paths - Parallel Graphs:
  
Imagine two separate roads or paths that don't connect. That's a "Parallel Graph." It's like having two things happening independently, with no interaction between them. They're like two different stories going on at the same time.

- Family Tree - Tree Graphs:
  
Consider your family tree, starting from grandparents down to cousins. It's a "Tree Graph." There's a main person (maybe your grandparent), and the family branches out like the branches of a tree.

- Web of Connections - Cyclic and Acyclic Graphs:
  
Think about connections without any loops. If you can follow a path and never come back to where you started, it's an "Acyclic Graph." But if you can loop back, it's a "Cyclic Graph." It's like exploring paths without getting stuck in a loop.

Graphs are like super cool maps that help us understand how things are linked. Each type of graph shows different ways things can connect in our world of connections! 

## Implement a Graph
{: #implement}

The code starts by including a definition of a structure called Node is created. A Node represents a house, and it has a number (data) and a connection to the next house (next).

```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```

Another structure is defined, called Graph. This represents the entire map of our city. It contains the number of houses (vertices) and a list (adjacency_list) that shows how the houses are connected.

```c
typedef struct Graph {
    int vertices;
    Node** adjacency_list;
} Graph;
```

Here, a function called createNode is defined. It creates a new house (Node) with a specific number (data).

```c
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
```

The createGraph function is like creating a big map (Graph) with a certain number of houses (vertices). It also prepares space for the connections (adjacency_list) between the houses.

```c
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Allocate memory for the adjacency list
    graph->adjacency_list = (Node**)malloc(vertices * sizeof(Node*));

    // Initialize the adjacency list
    for (int i = 0; i < vertices; ++i) {
        graph->adjacency_list[i] = NULL;
    }

    return graph;
}
```

The addEdge function is like drawing a passage between two houses on our city. It connects one house to another and also connects the other house back (assuming a two-way connection).

```c
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = newNode;

    // Add an edge from dest to src (assuming an undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjacency_list[dest];
    graph->adjacency_list[dest] = newNode;
}
```

The printGraph function is like reading the entire map and telling everyone how the houses are connected. It goes through each house and lists its connections.

```c
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; ++i) {
        printf("Vertex %d:", i);
        Node* current = graph->adjacency_list[i];
        while (current != NULL) {
            printf(" -> %d", current->data);
            current = current->next;
        }
        printf("\n");
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
            <th>Undirected Graph</th>
            <td>O(V)</td>
            <td>O(V + E)</td>
            <td>O(1)</td>
            <td>O(1)</td>
            <td>O(V)</td>
            <td>O(V + E)</td>
            <td>O(1)</td>
            <td>O(1)</td>
            <td>O(V + E)</td>
        </tr>
        <tr>
            <th>Directed Graph</th>
            <td>O(V)</td>
            <td>O(V + E)</td>
            <td>O(1)</td>
            <td>O(1)</td>
            <td>O(V)</td>
            <td>O(V + E)</td>
            <td>O(1)</td>
            <td>O(1)</td>
            <td>O(V + E)</td>
        </tr>
        <tr>
            <th>Star Graphs</th>
            <td>O(V)</td>
            <td>O(V)</td>
            <td>O(1)</td>
            <td>O(1)</td>
            <td>O(V)</td>
            <td>O(V)</td>
            <td>O(1)</td>
            <td>O(1)</td>
            <td>O(V)</td>
        </tr>
        <tr>
            <th>Parallel Graphs</th>
            <td>O(V)</td>
            <td>O(V)</td>
            <td>O(1)</td>
            <td>O(1)</td>
            <td>O(V)</td>
            <td>O(V)</td>
            <td>O(1)</td>
            <td>O(1)</td>
            <td>O(V)</td>
        </tr>
        <tr>
            <th>Tree Graphs</th>
            <td>O(V)</td>
            <td>O(V)</td>
            <td>O(1)</td>
            <td>O(1)</td>
            <td>O(V)</td>
            <td>O(V)</td>
            <td>O(1)</td>
            <td>O(1)</td>
            <td>O(V)</td>
        </tr>
        <tr>
            <th>Cyclic and Acyclic Graphs</th>
            <td>O(V)</td>
            <td>O(V + E)</td>
            <td>O(1)</td>
            <td>O(1)</td>
            <td>O(V)</td>
            <td>O(V + E)</td>
            <td>O(1)</td>
            <td>O(1)</td>
            <td>O(V + E)</td>
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

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int vertices;
    Node** adjacency_list;
} Graph;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    graph->adjacency_list = (Node**)malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; ++i) {
        graph->adjacency_list[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacency_list[dest];
    graph->adjacency_list[dest] = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; ++i) {
        printf("Vertex %d:", i);
        Node* current = graph->adjacency_list[i];
        while (current != NULL) {
            printf(" -> %d", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}
```
