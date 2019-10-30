#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    float nota;
    struct node * next;
}Node;

typedef struct list{
    Node * head;
    int size;
}List;

List * create_list();
Node * create_node(float nota);
void push(List * list, Node * node);
void print_list(List * list);
bool is_empty(List * list);
void pop(List * list);
Node * at_pos(List * list, int indice);

int main(){
    float nota;
    int num;
    List * list = create_list();
    Node * aux;
    do{
        printf("Digite uma nota: ");
        scanf("%f", &nota);
        aux = create_node(nota);
        push(list, aux);
    }while(nota >= 0);
    print_list(list);
    
    printf("-------------------------\n");
    printf("Digite quantos elementos deseja remover:");
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        pop(list);
    }
    print_list(list);
    printf("Digite um indice que deseja pesquisar:");
    scanf("%d", &num);
    aux = at_pos(list, num);
    if(aux != NULL){
        printf("Posicao: %d\n", num);
        printf("Nota: %.2f\n", aux->nota);
    }else{
        printf("Indice inexistente!\n");
    }
    return 0;
}

List * create_list(){
    List * list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

Node * create_node(float nota){
    if(nota >= 0){
        Node * node = (Node *) malloc(sizeof(Node));
        node->nota = nota;
        return node;
    }else{
        return NULL;
    }
}

void push(List * list, Node * node){
    if(node != NULL){
        node->next = list->head;
        list->head = node;
        list->size ++;
    }
}

void print_list(List * list){
    if(is_empty(list)){
        printf("Lista Vazia!\n");
        return;
    }
    Node * aux = list->head;
    while(aux != NULL){
        printf("%.2f\n", aux->nota);
        aux = aux->next;
    }
}


bool is_empty(List * list){
    if(list->size == 0){
        return true;
    }else{
        return false;
    }
}

void pop(List * list){
    if(is_empty(list)){
        return;
    }
    Node * aux = list->head;
    list->head = aux->next;
    free(aux);
    list->size--;
}

Node * at_pos(List * list, int indice){
    if(is_empty(list) || indice >= list->size){
        printf("Entrada invalida!\n");
    }else{
        int i=0;
        Node * aux = list->head;
        while(aux != NULL){
            if(i == indice){
                return aux;
            }
            i++;
            aux = aux->next;
        }
    }
    return NULL;
}
