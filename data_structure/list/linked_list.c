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

typedef struct list{
    int size;
    Node *head, *tail;
} List;

Node *createNode(int info);
List *createList();
// capacity
bool empty(List *list);
int size(List *list);
// element access
Node * front(List *list);
Node * back(List *list);
Node *atPos(List *list, int index);
int indexOf(List *list, Node *node);
// modifiers
void push(List *list, Node *node);
void push_front(List *list, Node *node);
void push_back(List *list, Node *node);
void insert(List *list, Node *node, int index);
void pop_front(List *list);
void pop_back(List *list);
void erase(List *list, int index);
void clear(List *list);
// print
void printList(List *list);

int main(){
    List * list = createList();
    
    printf(">>> PUSH_FRONT <<<\n");
    
    for (int info = 0; info<5; info++){
        Node * node = createNode(info);
        push_front(list, node);
    }

    printf(">>> PRINT <<<\n");
    printList(list);

    printf(">>> POP_FRONT <<<\n");
    while (!empty(list)){
        printf("front: %d \tback: %d \tsize: %d\n", front(list)->info, back(list)->info, size(list));
        pop_front(list);
    }

    printf(">>> PUSH_BACK <<<\n");
    for (int info = 0; info<5; info++){
        Node * node = createNode(info);
        push_back(list, node);
    }

    printf(">>> PRINT <<<\n");
    printList(list);

    printf(">>> POP_BACK <<<\n");
    while (!empty(list)){
        printf("front: %d \tback: %d size: %d\n", front(list)->info, back(list)->info, size(list));
        pop_back(list);
    }

    printf(">>> INSERT <<<\n");
    // 3 0 2 1
    insert(list, createNode(0), 0);
    printf("front: %d \tback: %d size: %d\n", front(list)->info, back(list)->info, size(list));
    insert(list, createNode(1), 1);
    printf("front: %d \tback: %d size: %d\n", front(list)->info, back(list)->info, size(list));
    insert(list, createNode(2), 1);
    printf("front: %d \tback: %d size: %d\n", front(list)->info, back(list)->info, size(list));
    insert(list, createNode(3), 0);
    printf("front: %d \tback: %d size: %d\n", front(list)->info, back(list)->info, size(list));
    
    printf(">>> PRINT <<<\n");
    printList(list);

    printf(">>> ERASE <<<\n");
    printf("front: %d \tback: %d \tsize: %d\n", front(list)->info, back(list)->info, size(list));
    erase(list, 3);
    printf("front: %d \tback: %d \tsize: %d\n", front(list)->info, back(list)->info, size(list));
    erase(list, 0);
    printf("front: %d \tback: %d \tsize: %d\n", front(list)->info, back(list)->info, size(list));
    erase(list, 2);
    printf("front: %d \tback: %d \tsize: %d\n", front(list)->info, back(list)->info, size(list));
    erase(list, 0);
    
    printf(">>> INSERT <<<\n");
    for (int i = 0; i<5; i++){
        Node * node = createNode(i);
        insert(list, node, i);
    }
    
    printf(">>> PRINT <<<\n");
    printList(list);

    printf(">>> ATPOS <<<\n");
    Node * node = atPos(list, 0);
    printf("Node info at 0: %d\n", node->info);

    printf(">>> INDEXOF <<<\n");
    int index = indexOf(list, node);
    printf("index: %d\n", index);

    printf(">>> CLEARLIST <<<\n");
    clear(list);

    printf(">>> PRINT <<<\n");
    printList(list);

    return 0;
}

Node *createNode(int info){
    Node * node = (Node *) malloc(sizeof(Node));
    node->next = NULL;
    node->info = info;
    return node;
}
List *createList(){
    List *l = (List*)malloc(sizeof(List));
    l->head = l->tail = NULL;
    l->size = 0;
    return l;
}
bool empty(List *list){
    if(size(list) == 0 ){
        return true;
    }
    else {
        return false;
    }
}

int size(List *list){
    return list->size;
}
Node * front(List *list){
    return list->head;
}
Node * back(List *list){
    return list->tail;
}
Node *atPos(List * list, int index){
    if( index < 0 || index > size(list)){
        printf("Invalid Input!\n");
    }else{
        Node *aux = list->head;
        for (int i=0; i<size(list); i++){
            if(i == index){
                return aux;
            }
            aux = aux->next;
        }
    }
    return NULL;
}
int indexOf(List *list, Node *node){
    Node *aux = list->head;
    for (int i=0; i< size(list); i++){
        if ( node->info == aux->info ){
            return i;
        }
        aux = aux->next;
    }
    return -1;
}
void push(List *list, Node *node){
    if (node){
        list->head = node;
        list->tail = node;
        list->size++;
    }
}
void push_front(List *list, Node *node){
    if(node){
        if(empty(list) == true){
            push(list, node);
        }else{
            node->next = list->head;
            list->head = node;
            list->size++;
        }
    }
}
void push_back(List *list, Node *node){
    if(node){
        if(empty(list)){
            push(list, node);
        }else{
            list->tail->next = node;
            list->tail = node;
            list->size++;
        }
    }
}
void insert(List *list, Node *node, int index){
    if (index < 0 || index > size(list))
        printf("Invalid position!\n");
    else {
        if(empty(list)){
            push(list, node);
        } else if (index==0) {
            push_front(list, node);
        } else if(index == size(list)){
            push_back(list, node); 
        } 
        else{
            int before_index =  index-1;
            Node * after_node = atPos(list, index);
            node->next = after_node;

            Node * before_node = atPos(list, before_index);
            before_node->next = node;

            list->size++;
        }
    }
}
void pop_front(List *list){
    if (empty(list)){
        return;
    } 
    if (size(list) == 1){
        list->tail = NULL;
        list->head = NULL;
        list->size = 0;
    } else{
        Node * aux = list->head;
        list->head = aux->next;
        free(aux);
        list->size--;
    }
}
void pop_back(List *list){
    if (empty(list)){
        return;
    }
    if (size(list) == 1){
        list->tail = NULL;
        list->head = NULL;
        list->size = 0;
    } else {
        Node *tail = atPos(list, size(list) - 2);
        tail->next = NULL;
        list->tail = tail;
        list->size--;
    }
}
void erase(List *list, int index){
    if (index < 0 || index > size(list))
        printf("Invalid position!\n");
    else {
        if (index==0){
            printf("pop_front %d\n", index);
            pop_front(list);
        } else if(index == size(list)){ 
            printf("pop_back %d\n", index);
            pop_back(list);
        }
        else{
            printf("else %d\n", index);
            free(atPos(list,index));
            Node *after = atPos(list, index+1);
            Node *before = atPos(list, index-1);
            before->next = after;
            list->size--;
        }
    }
}
void clear(List *list){
    while(!empty(list)){
        pop_front(list);
    }
}
void printList(List *list){
     if (empty(list)){
        printf("List is empty\n");
        return;
    }
    Node *aux = list->head;
    while(aux != NULL){
        printf("%d\t", aux->info);
        aux = aux->next;
    }
    printf("\n");
}