/* 
 * Giovanna Borges Bottino 
 * giovannabbottino@gmail.com
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int info;
    struct node *next;
}Node;

typedef struct queue{
    Node * front, * rear;
    int size;
}Queue;

Queue * createQueue();
Node * createNode(int info);
void push(Queue * queue, Node * node);
void pop(Queue * queue);
bool empty(Queue *queue);
int size(Queue *queue);
Node * front(Queue *queue);
Node * back(Queue *queue);

int main(){
    Queue * queue = createQueue();
    
    for (int info = 0; info<5; info++){
        Node * node = createNode(info);
        push(queue, node);
    }

    while (!empty(queue)){
        printf("front: %d \tback: %d \n", front(queue)->info, back(queue)->info);
        pop(queue);
    }
    
    return 0;
}

Queue * createQueue(){
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

Node * createNode(int info){
    Node * node = (Node *) malloc(sizeof(Node));
    node->next = NULL;
    node->info = info;
    return node;
}

void push(Queue * queue, Node * node){
    if(node){
        if(empty(queue)){
            queue->front = node;
            queue->rear = node;
            queue->size++;
        }else{
            queue->rear->next = node;
            queue->rear = node;
            queue->size++;
        }
    }
}

void pop(Queue * queue){
    if(empty(queue)){
        printf("Empty Queue!\n");
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

bool empty(Queue *queue){
    if(queue->size == 0 ) return true;
    else return false;
}

int size(Queue *queue){
    return queue->size;
}

Node * front(Queue *queue){
    return queue->front;
}
Node * back(Queue *queue){
    return queue->rear;
}