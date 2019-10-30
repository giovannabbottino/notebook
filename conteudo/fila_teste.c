
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int idade;
    struct node *next;
}Node;

typedef struct queue{
    Node * front, * rear;
    int size;
}Queue;

Queue * create_queue(){
    Queue * queue = (Queue *) malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

Node * create_node(){
    Node * node = (Node *) malloc(sizeof(Node));
    node->next = NULL;
    printf("Digite a idade:");
    scanf("%d", &node->idade);
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

void print_queue(Queue * queue){
    Node * aux = queue->front;
    while(aux){
        printf("%d, ", aux->idade);
        aux = aux->next;
    }
}
int main(){
    int i;
    Queue * queue = create_queue();
    Node * node;
    for(i=0; i<10; i++){
        node = create_node();
        enqueue(queue, node);
    }
    
    print_queue(queue);
    printf("\n-------------------\n");
    dequeue(queue);
    dequeue(queue);
    print_queue(queue);
    dequeue(queue);
    printf("\n-------------------\n");
    print_queue(queue);
    dequeue(queue);
    printf("\n-------------------\n");
    print_queue(queue);
    dequeue(queue);
    printf("\n-------------------\n");
    print_queue(queue);
    dequeue(queue);
    printf("\n-------------------\n");
    print_queue(queue);
    dequeue(queue);
    printf("\n-------------------\n");
    print_queue(queue);
    dequeue(queue);
    printf("\n-------------------\n");
    print_queue(queue);
    dequeue(queue);
    printf("\n-------------------\n");
    print_queue(queue);
    dequeue(queue);
    printf("\n-------------------\n");
    print_queue(queue);
    dequeue(queue);
    printf("\n-------------------\n");
    print_queue(queue);
    dequeue(queue);
    printf("\n-------------------\n");
    print_queue(queue);
    dequeue(queue);
    printf("\n-------------------\n");
    print_queue(queue);
    dequeue(queue);
    printf("\n-------------------\n");
    print_queue(queue);
    dequeue(queue);
    
    return 0;
}
