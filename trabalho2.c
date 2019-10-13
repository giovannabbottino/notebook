/*Giovanna Borges 170011267 trabalho2 gibottino@gmail.com*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM 20

// Cria a struct Aluno
typedef struct node{
    char *Nome;
    int Matricula;
    char *Email; 
    struct node * next;
    struct node * prev;
} Node;

// Cria a struct Lista
typedef struct lista_aluno {
    Node *head; 
    Node *tail;
    int tamanho;
} Lista_aluno;

Lista_aluno * cria_lista_aluno();
Node * cria_node();
bool is_empty(Lista_aluno * list);
void push_aluno(Lista_aluno * list, Node * node);
Node * at_pos(Lista_aluno * list, int indice);
void cadastra_aluno(Node *alunos, Lista_aluno * list);
void print_lista_aluno(Lista_aluno *list);
void edita_aluno();
void deleta_aluno(Lista_aluno *list, char * elemento);
void exclui_aluno(Lista_aluno *list);
int Menu();
void escolha_Menu(int resposta, Lista_aluno * lista_aluno, Node * alunos);

int main(){
    int resposta;
    Lista_aluno *lista_aluno = cria_lista_aluno();
    Node *alunos;
    do{
        resposta = Menu();
        escolha_Menu(resposta, lista_aluno, alunos);
    }while(resposta != 6);
}

Lista_aluno * cria_lista_aluno(){
    Lista_aluno * list = (Lista_aluno *) malloc(sizeof(Lista_aluno));
    list->head = NULL;
    list->tail = NULL;
    list->tamanho = 0;
    return list;
}
Node * cria_node(){
    Node * a = (Node *) malloc(sizeof(Node));

    printf("Insira o nome:\n");
    a->Nome = (char*)malloc(TAM*sizeof(char*));
    scanf(" %s", a->Nome);

    printf("Insira a matricula:\n");
    scanf(" %d", &a->Matricula);
    
    printf("Insira o e-mail:\n");
    a->Email = (char*)malloc(TAM*sizeof(char*));
    scanf(" %s", a->Email);

    return a;
}

bool is_empty(Lista_aluno * list){
    if(list->tamanho == 0){
        return true;
    }else{
        return false;
    }
}

void push_aluno(Lista_aluno * l, Node * i){
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
        l->tamanho++;
    }
}

Node * at_pos(Lista_aluno * list, int indice){
    if(is_empty(list) || indice >= list->tamanho){
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

void cadastra_aluno(Node *alunos, Lista_aluno *list){
    int nova_quantidade, quantidade, i;
    printf("Quantos novos alunos deseja adicionar?\n");
    scanf(" %d", &quantidade); 
    nova_quantidade = list->tamanho + nova_quantidade;
    for (i=nova_quantidade- quantidade; i<nova_quantidade; i++){
        alunos = cria_node();
        push_aluno(list, alunos);
    }
}

void print_lista_aluno(Lista_aluno *list){
    if(!is_empty(list)){
        Node * aux = list->head;
        printf("Nome\t|Matricula\t|Email\n");
        printf("____\t|_________\t|_____\n");
        while (aux){
            printf("%s\t|%d\t|%s\n", aux->Nome, aux->Matricula, aux->Email);
            aux = aux->next;
        }
    } else {
        printf("Não há alunos matriculados\n");
    }
}

void altera_aluno(Node* a){
    int resposta;
    printf("O que deseja alterar?\n<1> Nome\t<2> Matricula\t<3> Email\n");
    scanf(" %d", &resposta);
    while (resposta <1 || resposta >3){
            printf("OPSS!!\nTente novamente\n");
            scanf(" %d", &resposta);
    }
    printf("Qual o novo valor?\n");

    switch (resposta){
        case 1:
            scanf(" %s", a->Nome);
        break;
        case 2:
            scanf(" %d", &a->Matricula);
        break;
        case 3:
            scanf(" %s", a->Email);
        break;
    }
}

void edita_aluno(Lista_aluno *list){
    char elemento[20];
    if(!is_empty(list)){
        printf("Quem você deseja alterar?\n");
        scanf(" %s", elemento);
        Node * aux = list->head;
        for (int i=0; i< list->tamanho; i++){
            if (strcmp(at_pos(list, i)->Nome, elemento)==0 ||strcmp( at_pos(list, i)->Email, elemento)==0){
	        altera_aluno(at_pos(list, i));
                break;
            }else if (i == (list->tamanho - 1) ){
                printf("Não existe esse funcionario\n");
            }
        }// END FOR
    } else {
        printf("Não há alunos matriculados\n");
    } 
}

void deleta_aluno(Lista_aluno *list, char* elemento){
    int i;
    for (i=0; i<list->tamanho; i++){
        if (strcmp(at_pos(list, i)->Nome, elemento)==0 || (strcmp(at_pos(list, i)->Email, elemento)==0)){
            if (list->head == at_pos(list, i) &&  list->tail == at_pos(list, i)){
                at_pos(list, i)->next = list->head;
            } else {
                if (list->head == at_pos(list, i)){
                    list->head = at_pos(list, i)->next;
                }
                if (list->tail == at_pos(list, i)){
                    list->tail = at_pos(list, i)->prev;
                }
            }
            free(at_pos(list, i));
            list->tamanho--;
            printf("Aluno excluido!\n");
            break;
        } else if (i == list->tamanho - 1) {
            printf("Não existe esse aluno\n");
        }// END IF ELSE
    }// END FOR
}

void exclui_aluno(Lista_aluno *list){
    int indice, excluir;
    char elemento[20];
    if(!is_empty(list)){
        printf("Deseja remover por nome ou indice?\n<1>Nome\t<2>Indice\t<3>Email\n");		    
	scanf(" %d", &excluir);
        // confere se a resposta esta entre as possibilidades
        while (excluir <1 || excluir >3){
            printf("OPSS!!\nTente novamente\n");
            scanf(" %d", &excluir);
        }
	printf("Quem você deseja remover?\n");
        switch (excluir){
            case 1:
                scanf(" %s", elemento);
            break;
            case 2:
                scanf(" %d", &indice);
                strcpy(elemento, at_pos(list, indice)->Nome);
            break;
            case 3:
                scanf(" %s", elemento);
            break;
        }
        deleta_aluno(list, elemento);	    
    }else {
        printf("Não há alunos matriculados\n");
    } 
}

// Função para imprimir o Menu e retornar a resposta
int Menu(){
    int resposta;
    printf("Menu de opções\n");
    printf("1) Cadastrar aluno\n");
    printf("2) Listar alunos\n");
    printf("3) Visualizar aluno\n");
    printf("4) Editar aluno\n");
    printf("5) Excluir aluno\n");
    printf("6) Sair do programa\n");
    scanf(" %d", &resposta);
    // confere se a resposta esta entre as possibilidades
    while (resposta <1 || resposta >6){
        printf("OPSS!!\nTente novamente\n");
	resposta = Menu();
    }
    return resposta;
}

void escolha_Menu(int resposta, Lista_aluno * lista_aluno, Node * alunos){
    switch (resposta){
	    case 1:
                cadastra_aluno(alunos, lista_aluno);
	    break;
	    case 2:
                print_lista_aluno(lista_aluno);
	    break;
	    // Visualizar aluno
	    case 3:        
	    break;
	    case 4: 
                edita_aluno(lista_aluno);
	    break;
	    case 5: 
                exclui_aluno(lista_aluno);
	    break;
       } // END switch
}
