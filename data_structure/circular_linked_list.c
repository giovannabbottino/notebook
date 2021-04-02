/*Giovanna Borges Bottino giovannabbottino@gmail.com*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int info;
    struct Node *next;
    
} Node;

typedef struct list{
    int size;
    Node *head;
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
    l->size = 0;
    return l;
}

void push(List * list, Node * node){
    if (node){
        node->next = list->head;
        list->head = node;
        list->size++;

        Node *temp = atPos(list, list->size-1);
        temp->next = list->head;
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

void insert(List *list, Node *node, int index){
    if (index < 0 || index > list->size)
        printf("Invalid position!\n");
    else {
        if (index==0) {
            node->next = list->head;
            list->head = node;

            Node *temp = atPos(list, list->size);
            temp->next = list->head;
        } else if(index == list->size){
            node->next = list->head;
            
            Node *temp = atPos(list, index-1);
            temp->next = node; 
        } 
        else{
            Node *aux = atPos(list, index);
            node->next = aux;

            Node *temp = atPos(list, index-1);
            temp->next = node; 
        }
        list->size++;
    }
}

void erase(List *list, int index){
    if (index < 0 || index > list->size)
        printf("Invalid position!\n");
    else {
        free(atPos(list, index));
        if (index==0){
            Node *aux = list->head->next;
            list->head = aux;

            Node *temp = atPos(list, list->size-1);
            temp->next = list->head;
        } else if(index == list->size){ 
            Node *temp = atPos(list, index-1);
            temp->next = list->head;
        }
        else{
            Node *aux = atPos(list, index+1);

            Node *temp = atPos(list, index-1);
            temp->next = aux;
        }
        list->size--;
    }
}