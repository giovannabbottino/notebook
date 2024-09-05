---
layout: default
title: Breadth-First Search
nav_order: 1
description: 'Breadth-First Search'
parent: Search Algorithms
---

Breadth-First Search (BFS)
{: .fs-9}

Breadth-First Search (BFS) is a traversal algorithm for searching or exploring tree or graph data structures. It explores nodes layer by layer, visiting all neighbors of a node before moving to the next level of neighbors.

How BFS Works?
{: .fs-6 .fw-300 }

1. **Start at a node**: Begin at a given source node and mark it as visited.
2. **Visit all neighbors**: Explore all unvisited neighbors of the current node and mark them as visited.
3. **Use a queue**: Enqueue each neighbor into a queue to ensure they are processed in the order they were discovered.
4. **Dequeue and repeat**: Dequeue the first element from the queue and repeat the process for each of its neighbors.
5. **End**: The algorithm continues until there are no more nodes left in the queue.

Why Use BFS
{: .fs-6 .fw-300 }

- **Shortest Path in Unweighted Graphs**: BFS guarantees finding the shortest path between two nodes in an unweighted graph.
- **Layered Exploration**: BFS is ideal for level-order traversal, especially when working with tree structures or multi-level data.
- **Cycle Detection**: BFS can detect cycles in a graph by checking for visited nodes.

Limitations
{: .fs-6 .fw-300 }

- **Memory Usage**: BFS requires memory proportional to the width of the graph, which can be substantial for wide graphs.
- **Not Optimal for Weighted Graphs**: BFS does not account for edge weights, making it less suitable for finding the shortest path in weighted graphs (Dijkstra’s algorithm would be better).

## Implement 
{: #implement }

The BFS algorithm can be implemented using an adjacency list to represent the graph and a queue to keep track of the nodes to be visited.

We will now go through each major step of the BFS algorithm implemented in C.

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue.h>

#define MAX_NODES 1000

int adj[MAX_NODES][MAX_NODES]; // Adjacency matrix
bool visited[MAX_NODES];
```
### Step 1: Define the Graph and Visited Nodes

- We represent the graph using an adjacency matrix (adj[][]), where adj[i][j] = 1 if there is an edge between node i and node j.
- We use a visited[] array to keep track of whether a node has already been visited. This prevents the algorithm from visiting the same node multiple times.

```c
void bfs(int start, int n) {
    std::queue<int> q;
    q.push(start);
    visited[start] = true;
```

### Step 2: Initialize the BFS

- A queue is used to control the order in which nodes are explored. BFS is a level-order traversal, so we need a first-in-first-out (FIFO) structure like a queue.
- Enqueue the starting node (start) and mark it as visited.
  - This ensures that we will start exploring the graph from the start node, and we won't visit it again.
 
```c
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        printf("%d ", node);
```

### Step 3: Dequeue and Visit Nodes

- Dequeue a node from the front of the queue.
  - This node represents the current node being explored.
- Print the node: In this example, we print the node to indicate its traversal.

```c
        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
```

### Step 4: Explore the Neighbors

- For each node, check all of its neighbors by iterating through the adjacency matrix.
  - If an edge exists between the current node (node) and another node (i), i.e., adj[node][i] == 1, and the neighbor hasn’t been visited yet, it will be enqueued.
- Mark the neighbor as visited: This ensures that we don’t process this neighbor multiple times in future iterations.
- Enqueue the neighbor: Add the neighbor to the queue to be explored in the next BFS layer.

```c
int main() {
    int n, edges, x, y;
    scanf("%d %d", &n, &edges);
    
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &x, &y);
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    bfs(0, n);
    return 0;
}

```

### Step 5: Input and Graph Construction

- We first read the number of nodes (n) and edges from the input.
- We then populate the adjacency matrix using the edges provided. For each edge, we set both adj[x][y] = 1 and adj[y][x] = 1 to represent an undirected graph.
- Finally, we call the bfs function, starting from node 0.

## The [Big-O notation]({{site.baseurl}}/algorithm/computational_complexity#bigO)
<table> <thead> <tr> <th id="str" scope="col"> Data Structure / Algorithm </th> <th id="time" scope="col" class="span" colspan="4"> Time Complexity </th> <th id="wr" scope="col"> Space Complexity </th> </tr> </thead> <tbody> <tr> <th></th> <th>Best Case</th> <th>Average Case</th> <th>Worst Case</th> </tr> <tr> <th>BFS</th> <td>O(V + E)</td> <td>O(V + E)</td> <td>O(V + E)</td> <td>O(V)</td> </tr> </tbody> </table> 

## Code
{: #code}

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue.h>

#define MAX_NODES 1000

int adj[MAX_NODES][MAX_NODES]; // Adjacency matrix
bool visited[MAX_NODES];

void bfs(int start, int n) {
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int n, edges, x, y;
    scanf("%d %d", &n, &edges);
    
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &x, &y);
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    bfs(0, n);
    return 0;
}
```
