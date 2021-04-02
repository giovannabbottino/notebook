/*Giovanna Borges Bottino giovannabbottino@gmail.com*/

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
Node * createNode();
void push(Stack * stack, Node * node);
void pop(Stack * stack);
void top(Stack *stack);
bool isEmpty(Stack * stack);
void printStack(Stack * stack);

int main(){
    int i;
    Stack * stack = createStack();
    Node * node;
    for(i=0; i<10; i++){
        node = createNode();
        push(stack, node);
    }
    
    printStack(stack);
    printf("\n-------------------\n");
    top(stack);
    pop(stack);
    top(stack);
    
    return 0;
}

Stack * createStack(){
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

Node * createNode(){
    Node * node = (Node *) malloc(sizeof(Node));
    node->next = NULL;
    printf("Info:");
    scanf("%d", &node->info);
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
    if(isEmpty(stack)){
        return;
    }
    Node * aux = stack->top;
    stack->top = aux->next;
    free(aux);
    stack->size--;
}

void top(Stack *stack){
    if(stack->top){
        printf("TOP: %d\n", stack->top->info);
    } else{
        printf("Stack empty\n");
    }
}

bool isEmpty(Stack * stack){
    return stack->size == 0;
}


void printStack(Stack * stack){
    Node * aux = stack->top;
    while(aux){
        printf("%d, ", aux->info);
        aux = aux->next;
    }
}