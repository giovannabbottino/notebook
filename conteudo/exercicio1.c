/*Giovanna Borges Bottino 170011267 gibottino@gmail.com*/

#include <stdio.h>
#include <stdlib.h>
typedef struct idade{
    int idade;
    struct idade *next;
    struct idade *prev;
    
} Idade;

typedef struct lista{
    int tamanho;
    Idade *head;
    Idade *tail;
} Lista;

Lista *cria_lista(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->head = NULL;
    l->tail = NULL;
    l->tamanho = 0;
    return l;
}

void push(Lista * l, Idade * i){
    if (i){
        if (l->head){
            i->next = l->head;
            l->head->prev = i;
            l->head = i;
        } else{
            i->next = l->head;
            l->head = i;
            l->tail = i;
        }
    } else {
        printf("i invalidado\n");
    }
}

void print_lista(Lista *list){
    Idade * aux = list->head;
    while (aux){
        printf("%d\n", aux->idade);
        aux = aux->next;
    }
}

void print_lista_inversa(Lista *list){
    Idade * aux = list->tail;
    while (aux){
        printf("%d\n", aux->idade);
        aux = aux->prev;
    }
}

Idade*cria_idade(int idade){
    if(idade >= 0){
        Idade * i = (Idade *) malloc(sizeof(Idade));
        i->idade = idade;
        return i;
    }else{
        return NULL;
    }
}

int main(){
    float idade;
    Lista * list = cria_lista();
    Idade * aux;
    do{
        printf("Digite uma idade: ");
        scanf("%f", &idade);
        aux = cria_idade(idade);
        push(list, aux);
    }while(idade >= 0);
    printf("Lista normal\n");
    print_lista(list);
    printf("Lista inversa\n");
    print_lista_inversa(list);
    return 0;
}
