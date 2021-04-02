/*Giovanna Borges Bottino giovannabbottino@gmail.com*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}Node;

typedef struct queue{
    Node * front, * rear;
    int size;
}Queue;

Queue * createQueue();
Node * createNode();
void enqueue(Queue * queue, Node * node);
void dequeue(Queue * queue);
void printQueue(Queue * queue);

int main(){
    int i;
    Queue * queue = createQueue();
    Node * node;
    for(i=0; i<10; i++){
        node = createNode();
        enqueue(queue, node);
    }
    
    printQueue(queue);
    printf("\n-------------------\n");
    dequeue(queue);
    printQueue(queue);
    
    return 0;
}

Queue * createQueue(){
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

Node * createNode(){
    Node * node = (Node *) malloc(sizeof(Node));
    node->next = NULL;
    printf("Info:");
    scanf("%d", &node->info);
    return node;
}

void enqueue(Queue * queue, Node * node){
    if(queue->rear == NULL){
        queue->front = node;
        queue->rear = node;
        queue->size++;
    }else{
        queue->rear->next = node;
        queue->rear = node;
        queue->size++;
    }
}

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

void printQueue(Queue * queue){
    Node * aux = queue->front;
    while(aux){
        printf("%d, ", aux->info);
        aux = aux->next;
    }
}