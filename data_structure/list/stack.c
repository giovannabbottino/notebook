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

typedef struct stack{
    Node * top;
    int size;
}Stack;

Stack * createStack();
Node * createNode(int info);
void push(Stack * stack, Node * node);
void pop(Stack * stack);
bool empty(Stack *stack);
int size(Stack *stack);
Node * top(Stack *stack);

int main(){
    Stack * stack = createStack();
    
    for (int info = 0; info<5; info++){
        Node * node = createNode(info);
        push(stack, node);
    }

    while (!empty(stack)){
        printf("top: %d \n", top(stack)->info);
        pop(stack);
    }
    
    return 0;
}

Stack * createStack(){
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

Node * createNode(int info){
    Node * node = (Node *) malloc(sizeof(Node));
    node->next = NULL;
    node->info = info;
    return node;
}

void push(Stack * stack, Node * node){
    if(node){
        node->next = stack->top;
        stack->top = node;
        stack->size++;
    }
}

void pop(Stack * stack){
    if(empty(stack)){
        return;
    }
    Node * aux = stack->top;
    stack->top = aux->next;
    free(aux);
    stack->size--;
}
bool empty(Stack *stack){
    if(stack->size == 0 ) return true;
    else return false;
}

int size(Stack *stack){
    return stack->size;
}

Node * top(Stack *stack){
    return stack->top;
}