/*Giovanna Borges Bottino giovannabbottino@gmail.com*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int info;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct list{
    int size;
    Node *head;
    Node *tail;
} List;

Node *createNode(int info);
List *createList();
void push(List *list, Node *node);
bool isEmpty(List *list);
void pop(List *list);
void printList(List *list);
Node *atPos(List *list, int index);
int indexOf(List *list, Node *node);
void insert(List *list, Node *node, int index);
void erase(List *list, int index);

int main(){

    List *list = createList();
    Node * node;
    int info;
    
    printf("Node value:\n");
    scanf(" %d", &info);
    node = createNode(info);
    push(list, node);

    printf("Node value:\n");
    scanf(" %d", &info);
    node = createNode(info);
    push(list, node);

    int index;
    printf("Node value:\n");
    scanf(" %d", &info);
    node = createNode(info);
    
    printf("Insert at:\n");
    scanf(" %d", &index);
    insert(list,node, index);
    
    printList(list);

    printf("Node value to delete:\n");
    scanf(" %d", &info);
    node = createNode(info);
    
    index = indexOf(list, node);
    
    erase(list, index);

    printList(list);

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
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

void push(List * list, Node * node){
    if (node){
        if(list->head){
            node->next = list->head;
            node->prev = list->tail;
            list->head->prev = node;
            list->head = node;
            
            list->tail->next = node;
            list->head->prev = list->tail;
        } else{
            node->next = list->head;
            list->head = node;
            list->tail = node;
        }
        list->size++;
    } else {
        printf("Invalid node!\n");
    }
}

bool isEmpty(List *list){
    if(list->size == 0 ) return true;
    else return false;
}

void pop(List * list){
    if (isEmpty(list)){
        return;
    }
    Node * aux= list->head;
    list->head = aux->next;
    
    list->tail->next = list->head;
    list->head->prev = list->tail;
    free(aux);
    list->size--;
}

void printList(List *list){
     if (isEmpty(list)){
         printf("List is empty\n");
         return;
     }
    Node *pointer = list->head;
    for (int i=0; i< list->size; i++){
        printf("Node info: %d\n", pointer->info);
        pointer = pointer->next;
    }
}

Node *atPos(List * list, int index){
    if( index < 0 || index > list->size){
        printf("Invalid Input!\n");
    }else{
        int i=0;
        Node *pointer = list->head;
        for (int j=0; j< list->size; j++){
            if(i == index){
                return pointer;
            }
            i++;
            pointer = pointer->next;
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

void insert(List *list, Node *node, int index){
    if (index < 0 || index > list->size)
        printf("Invalid position!\n");
    else {
        if (index==0) {
            node->next = list->head;
            node->prev = list->tail;
            
            list->head->prev = node;
            list->head = node;
            
            list->tail->next = node;
        } else if(index == list->size){
            node->next = list->head;
            node->prev = list->tail;
            
            list->head->prev = node;
            
            list->tail->next = node;
            list->tail = node;
        } 
        else{
            Node *aux = atPos(list, index);
            Node *temp = aux->prev;
            node->next = aux;
            node->prev = temp;
            temp->next = node; 

            aux->prev = node; 
        }
        list->size++;
    }
}

void erase(List *list, int index){
    if (index < 0 || index > list->size)
        printf("Invalid position!\n");
    else {
        if (index==0){
            Node *aux = list->head->next;
            aux->prev = list->tail;

            list->head = aux;
            list->tail->next = aux;
        } else if(index == list->size-1){ 
            Node *aux = list->tail->prev;

            list->tail = aux;
            aux->next = list->head;
            list->head->prev = aux;
        }
        else{
            Node *aux = atPos(list, index);
            Node *next = aux->next;
            Node *prev = aux->prev;
            
            aux = prev;
            prev->next = next;
            next->prev = aux;
        }
        list->size--;
    }
}