/* 
 * Giovanna Borges Bottino 
 * giovannabbottino@gmail.com
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int info;
    struct node *next, *prev;
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
void printInverseList(List *list);

int main(){
    List * list = createList();
    
    for (int info = 0; info<5; info++){
        Node * node = createNode(info);
        push_front(list, node);
    }

    printList(list);
    printInverseList(list);

    while (!empty(list)){
        printf("front: %d \tback: %d \tsize: %d\n", front(list)->info, back(list)->info, size(list));
        pop_front(list);
    }

    for (int info = 0; info<5; info++){
        Node * node = createNode(info);
        push_back(list, node);
    }

    printList(list);
    printInverseList(list);

    while (!empty(list)){
        printf("front: %d \tback: %d size: %d\n", front(list)->info, back(list)->info, size(list));
        pop_back(list);
    }

    // 3 0 2 1
    insert(list, createNode(0), 0);
    printf("front: %d \tback: %d size: %d\n", front(list)->info, back(list)->info, size(list));
    insert(list, createNode(1), 1);
    printf("front: %d \tback: %d size: %d\n", front(list)->info, back(list)->info, size(list));
    insert(list, createNode(2), 1);
    printf("front: %d \tback: %d size: %d\n", front(list)->info, back(list)->info, size(list));
    insert(list, createNode(3), 0);
    printf("front: %d \tback: %d size: %d\n", front(list)->info, back(list)->info, size(list));
    
    printList(list);
    printInverseList(list);

    printf("front: %d \tback: %d \tsize: %d\n", front(list)->info, back(list)->info, size(list));
    erase(list, 3);
    printf("front: %d \tback: %d \tsize: %d\n", front(list)->info, back(list)->info, size(list));
    erase(list, 1);
    printf("front: %d \tback: %d \tsize: %d\n", front(list)->info, back(list)->info, size(list));
    erase(list, 0);
    
    for (int i = 0; i<5; i++){
        Node * node = createNode(i);
        insert(list, node, i);
    }
    
    printList(list);
    printInverseList(list);

    Node * node = atPos(list, 0);
    printf("Node info at 0: %d\n", node->info);

    int index = indexOf(list, node);
    printf("index: %d\n", index);

    clear(list);

    printList(list);

    return 0;
}
Node *createNode(int info){
    Node * node = (Node *) malloc(sizeof(Node));
    node->next = node->prev = NULL;
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
            list->head->prev = node;
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
            node->prev = list->tail;
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
            after_node->prev = node;
            node->next = after_node;

            Node * before_node = atPos(list, before_index);
            node->prev = before_node;
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
        list->head->prev = NULL;
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
        Node *prev = list->tail->prev;
        prev->next = NULL;
        list->tail = prev;
        list->size--;
    }
}
void erase(List *list, int index){
    if (index < 0 || index > size(list))
        printf("Invalid position!\n");
    else {
        if (index==0){
            pop_front(list);
        } else if(index == size(list) - 1){ 
            pop_back(list);
        }
        else{
            Node *node = atPos(list, index);
            Node *before = node->prev;
            Node *after = node->next;
            free(node);
            before->next = after;
            after->prev = before;
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
void printInverseList(List *list){
     if (empty(list)){
        printf("List is empty\n");
        return;
    }
    Node *aux = list->tail;
    while(aux != NULL){
        printf("%d\t", aux->info);
        aux = aux->prev;
    }
    printf("\n");
}