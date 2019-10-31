/*Giovanna Borges Bottino 170011267 trabalho2 gibottino@gmail.com*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM 20

// declara structs Disciplina
typedef struct Disciplina{
    char *Nome;
    char *Mencao; 
    struct Disciplina * next;
    struct Disciplina * prev;
} Disciplina;

// declara structs para a lista de Disciplina
typedef struct lista_disciplina {
    Disciplina *head; 
    Disciplina *tail;
    int tamanho;
} Lista_disciplina;

// declara structs para aluno
typedef struct node{
    char *Nome;
    int Matricula;
    char *Email; 
    struct node * next;
    struct node * prev;
    Lista_disciplina * Historico;
} Node;

// declara structs para a lista de aluno
typedef struct lista_aluno {
    Node *head; 
    Node *tail;
    int tamanho;
} Lista_aluno;

// inicializacao de funcao 
Lista_disciplina * cria_lista_disciplina();
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
bool confere_Mencao(char * mencao);
bool is_empty_disciplina(Lista_disciplina * list);
void push_disciplina(Lista_disciplina * l, Disciplina * i);
Disciplina * at_posicao_disciplina(Lista_disciplina * list, int indice);
Disciplina * cria_disciplina();
void cadastra_disciplina(Disciplina *d, Lista_disciplina *list);
void print_lista_disciplina(Lista_disciplina *list);
void altera_disciplina(Disciplina* a);
void edita_disciplina(Lista_disciplina *list);
void deleta_disciplina(Lista_disciplina *list, char* elemento);
void exclui_disciplina(Lista_disciplina *list);
int Menu_aluno(Node * aluno);
void escolha_aluno(int resposta, Node * aluno);
void visualiza_aluno(Node * alunos, Lista_aluno * lista_aluno);

// Main
int main(){
    int resposta;
    // cria lista de alunos e aluno
    Lista_aluno *lista_aluno = cria_lista_aluno();
    Node *alunos;
    // inicializa menu
    do{
        resposta = Menu();
        escolha_Menu(resposta, lista_aluno, alunos);
    }while(resposta != 6);
}

// Funcao para inicializar a lista de disciplina 
Lista_disciplina * cria_lista_disciplina(){
    Lista_disciplina * list = (Lista_disciplina *) malloc(sizeof(Lista_disciplina));
    list->head = NULL;
    list->tail = NULL;
    list->tamanho = 0;
    return list;
}

// Funcao para inicializar a lista de aluno 
Lista_aluno * cria_lista_aluno(){
    Lista_aluno * list = (Lista_aluno *) malloc(sizeof(Lista_aluno));
    list->head = NULL;
    list->tail = NULL;
    list->tamanho = 0;
    return list;
}

// Funcao para criar aluno
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

    a->Historico = cria_lista_disciplina();

    return a;
}

// Funcao para conferir se a lista de alunos esta vazia
bool is_empty(Lista_aluno * list){
    if(list->tamanho == 0){
        return true;
    }else{
        return false;
    }
}

// Funcao para adicionar aluno (node) a lista de alunos
void push_aluno(Lista_aluno * list, Node * aluno){
    if (aluno){
        // confere se a lista tem um inicio
        if (list->head){
            aluno->next = NULL;
            aluno->prev = list->tail;
            list->tail->next = aluno;
            list->tail = aluno;
        } else{
            aluno->next = NULL;
            aluno->prev = NULL;
            list->head = aluno;
            list->tail = aluno;
        }
        list->tamanho++;
    }
}

// Funcao para retornar o aluno (node) de dentro da lista de aluno
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

// Funcao para cadastrar o aluno a quantidade n de alunos e adicionar na lista de alunos
void cadastra_aluno(Node *alunos, Lista_aluno *list){
    int nova_quantidade, quantidade, i;

    printf("Quantos novos alunos deseja adicionar?\n");
    scanf("%d", &quantidade); 

    nova_quantidade = list->tamanho + nova_quantidade;
    for (i=nova_quantidade- quantidade; i<nova_quantidade; i++){
        alunos = cria_node();
        push_aluno(list, alunos);
    }
}

// Funcao para imprimir a lista de alunos
void print_lista_aluno(Lista_aluno *list){
    if(!is_empty(list)){
        Node * aux = list->head;

        printf("Nome\t|Matri\t|Email\t|Historico\n");
        printf("____\t|_____\t|_____\t|_________\n");

        while (aux){
            printf("%s\t|%d\t|%s\t|", aux->Nome, aux->Matricula, aux->Email);
            // procura se ha ou nao disciplina vinculada ao aluno
            if (aux->Historico->tamanho == 0){
                printf("Não há disciplina vinculada\n");
            } else {
                printf("%d\n", aux->Historico->tamanho);
            }
            aux = aux->next;
        }
    } else {
        printf("Não há alunos matriculados\n");
    }
}

// Funcao para alterar aluno selecionado
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

// Funcao para selecionar aluno da lista de alunos e o editar
void edita_aluno(Lista_aluno *list){
    char elemento[20];

    if(!is_empty(list)){  
        printf("Quem você deseja alterar?\n");
        scanf(" %s", elemento);

        Node * aux = list->head;

        for (int i=0; i< list->tamanho; i++){
            // confere se ha algum aluno de acordo com o elemento selecionado
            if (strcmp(at_pos(list, i)->Nome, elemento)==0 ||strcmp( at_pos(list, i)->Email, elemento)==0){
	        altera_aluno(at_pos(list, i));
                break;
            }else if (i == (list->tamanho - 1) ){
                printf("Não existe esse aluno\n");
            }
        }// END FOR
    } else {
        printf("Não há alunos matriculados\n");
    } 
}

// Funcao para deletar aluno escolhido
void deleta_aluno(Lista_aluno *list, char* elemento){
    int i, j;
    Node *remov_elemento,*aux;

    for (i=0; i<list->tamanho; i++){
        // elemento encontrado
        if (strcmp(at_pos(list, i)->Nome, elemento)==0 || (strcmp(at_pos(list, i)->Email, elemento)==0)){
            // se for o primerio item da lista
            if (i == 0){
                // salva o elento a ser removido como o primeiro item da lista
                remov_elemento = list->head;
                list->head = list->head->next;

                if(list->head == NULL)
                    list->tail = NULL;
                else
                    list->head->prev == NULL;
            // se for o ultimo item da lista
            }else if(i == list->tamanho-1){
                remov_elemento = list->tail;
                list->tail = list->tail->prev;
		list->tail->next = NULL;
            // se for qualquer outro item
            }else {
                aux = list->head;

                for(j=1;j<i+1;++j){
                    aux = aux->next;
                }
                    remov_elemento = aux;
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
            }

            free(remov_elemento);
            list->tamanho--;
            printf("Aluno excluido!\n");
            break;
        } else if (i == list->tamanho - 1) {
            printf("Não existe esse aluno\n");
        }// END IF ELSE
    }// END FOR
}

// Funcao para escolher qual aluno vai ser escolhido
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
               	strcpy(elemento, at_pos(list, indice-1)->Nome);
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
    printf("_____________________________________________________________\n");
    printf("Menu de opções\n");
    printf("1) Cadastrar aluno\n");
    printf("2) Listar alunos\n");
    printf("3) Visualizar aluno\n");
    printf("4) Editar aluno\n");
    printf("5) Excluir aluno\n");
    printf("6) Sair do programa\n");
    printf("_____________________________________________________________\n");
    scanf(" %d", &resposta);
    // confere se a resposta esta entre as possibilidades
    while (resposta <1 || resposta >6){
        printf("OPSS!!\nTente novamente\n");
	resposta = Menu();
    }
    return resposta;
}

// Funcao que recebe o Menu() e aciona o selecionado
void escolha_Menu(int resposta, Lista_aluno * lista_aluno, Node * alunos){
    switch (resposta){
	    case 1:
                cadastra_aluno(alunos, lista_aluno);
	    break;
	    case 2:
                print_lista_aluno(lista_aluno);
	    break;
	    case 3:     
                visualiza_aluno( alunos, lista_aluno);
	    break;
	    case 4: 
                edita_aluno(lista_aluno);
	    break;
	    case 5: 
                exclui_aluno(lista_aluno);
	    break;
       } // END switch
}

// Funcoes para tratar as materias

// Funcao para conferir se a mencao esta de acordo com o padrao
bool confere_Mencao(char * mencao){
    if ( strcmp(mencao, "tr")==0 || strcmp(mencao, "sr")==0 || strcmp(mencao, "ii")==0 || strcmp(mencao, "mi")==0 || strcmp(mencao, "mm")==0 || strcmp(mencao, "ms")==0 || strcmp(mencao, "ss")==0){
        return true;
    } else{
        return false;
    }
}

// Funcao para conferir se a lista de disciplina esta vazia
bool is_empty_disciplina(Lista_disciplina * list){
    if(list->tamanho == 0){
        return true;
    }else{
        return false;
    }
}

// Funcao para retornar a disciplina de dentro da lista de disciplina
Disciplina * at_posicao_disciplina(Lista_disciplina * list, int indice){
    if(is_empty_disciplina(list) || indice >= list->tamanho){
        printf("Entrada invalida!\n");
    }else{
        int i=0;
        Disciplina * aux = list->head;

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

// Funcao para adicionar disciplina a lista de disciplinas
void push_disciplina(Lista_disciplina * l, Disciplina * i){
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

// Funcao para criar disciplina 
Disciplina * cria_disciplina(){
    Disciplina * a = (Disciplina *) malloc(sizeof(Disciplina));

    a->Nome = (char*)malloc(TAM*sizeof(char*));
    printf("Insira o nome:\n");
    scanf(" %s", a->Nome);

    a->Mencao = (char*)malloc(TAM*sizeof(char*));
    // espera a entrada correta do usuario
    while (!confere_Mencao(a->Mencao)) {
         printf("Insira a mencao:\n");
         scanf(" %s", a->Mencao);
    }
    return a;
}

// Funcao para cadastrar a quantidade n de disciplinas e adicionar na lista de disciplina 
void cadastra_disciplina(Disciplina *d, Lista_disciplina *list){
    int nova_quantidade, quantidade, i;

    printf("Quantas disciplinas deseja adicionar?\n");
    scanf(" %d", &quantidade); 
    nova_quantidade = list->tamanho + nova_quantidade;

    for (i=nova_quantidade- quantidade; i<nova_quantidade; i++){
        d = cria_disciplina();
        push_disciplina(list, d);
    }
}

// Funcao para imprimir todas as disciplinas na lista de disciplina
void print_lista_disciplina(Lista_disciplina *list){
    if(!is_empty_disciplina(list)){

        Disciplina * aux = list->head;

        printf("Nome\t|Mencao\n");
        printf("____\t|______\n");

        while (aux){
            printf("%s\t|%s\n", aux->Nome, aux->Mencao);
            aux = aux->next;
        }
    } else {
        printf("Não há matricula vinculada\n");
    }
}

// Funcao para alterar a disciplina selecionada
void altera_disciplina(Disciplina* a){
    int resposta;

    printf("O que deseja alterar?\n<1> Nome\t<2> Mencao\n");
    scanf(" %d", &resposta);

    while (resposta <1 || resposta >2){
            printf("OPSS!!\nTente novamente\n");
            scanf(" %d", &resposta);
    }

    switch (resposta){
        case 1:
            printf("Qual o novo valor?\n");
            scanf(" %s", a->Nome);
        break;
        case 2:
            while (!confere_Mencao(a->Mencao)) {
                printf("Insira a mencao:\n");
                scanf(" %s", a->Mencao);
            }

        break;
    }
}

// Funcao para selecionar disciplina que vai ser editada de dentro da lista de disciplina
void edita_disciplina(Lista_disciplina *list){
    char elemento[20];

    if(!is_empty_disciplina(list)){  
        printf("Quem você deseja alterar?\n");
        scanf(" %s", elemento);

        Disciplina * aux = list->head;

        for (int i=0; i< list->tamanho; i++){
            if (strcmp(at_posicao_disciplina(list, i)->Nome, elemento)==0 ){
	        altera_disciplina(at_posicao_disciplina(list, i));
                break;
            }else if (i == (list->tamanho - 1) ){
                printf("Não existe essa materia\n");
            }
        }// END FOR
    } else {
        printf("Não há disciplina vinculada\n");
    } 
}

// Funcao para contar a quantidade de materias cursadas
int materias_cursadas(Lista_disciplina *list){
    int copia=0, i, j;
    Disciplina * d, *a;

    // roda toda a lista
    d = list->head;
    for (i=0; i<list->tamanho; i++){
        // entra em loop para cada i, comparando o Nome com o restante
        for (j=i+1; j<list->tamanho; j++){
            if (j != i && strcmp(d->Nome, at_posicao_disciplina(list, j)->Nome) == 0){  
                 copia++;
                 break;
            }
        }
        d = d->next;
    }
    return (list->tamanho - copia);
}

// Funcao para contar a quantidade de materias aprovadas
int materias_aprovadas(Lista_disciplina *list){
    int n=0, i;

    Disciplina * d;
    d = list->head;

    for (i=0; i<list->tamanho; i++){
        if (strcmp(d->Mencao, "mm")==0 || strcmp(d->Mencao, "ms")==0 || strcmp(d->Mencao, "ss")==0){  
            n++;
        }
        d = d->next;
    }

    return n;
}

// Funcao para contar a quantidade de materias reprovadas
int materias_reprovadas(Lista_disciplina *list){
    int n=0, i;

    Disciplina * d;
    d = list->head;

    for (i=0; i<list->tamanho; i++){
        if (strcmp(d->Mencao, "sr")==0 ||  strcmp(d->Mencao, "ii")==0  || strcmp(d->Mencao, "mi")==0){  
            n++;
        }
        d = d->next;
    }

    return n;
}

// Funcao para contar a quantidade de materias trancadas
int materias_trancadas(Lista_disciplina *list){
    int n=0, i;

    Disciplina * d;
    d = list->head;

    for (i=0; i<list->tamanho; i++){
        if (strcmp(d->Mencao, "tr")==0 ){      
            n++;
        }
        d = d->next;
    }

    return n;
}

// Funcao para imprimir relatorio geral do aluno
void relatorio_geral(Node * a){
    printf("Nome do aluno: %s\nMatricula: %d\nEmail: %s\n" ,a->Nome, a->Matricula, a->Email);
    printf("Materias cursadas: %d\nAprovadas: %d\tReprovadas: %d\tTrancadas: %d\n", materias_cursadas(a->Historico), materias_aprovadas(a->Historico), materias_reprovadas(a->Historico), materias_trancadas(a->Historico) );
    
}

// Funcao para deletar disciplina escolhida
void deleta_disciplina(Lista_disciplina *list, char* elemento){
    int i, j;

    Disciplina *remov_elemento,*aux;
    for (i=0; i<list->tamanho; i++){
        // elemento encontrado
        if (strcmp(at_posicao_disciplina(list, i)->Nome, elemento)==0){
            // se for o primerio item da lista
            if (i == 0){
                // salva o elemento a ser removido como o primeiro item da lista
                remov_elemento = list->head;
                list->head = list->head->next;
                // confere se a lista possui so um item
                if(list->head == NULL)
                    list->tail = NULL;
                else
                    list->head->prev == NULL;
            // se for o ultimo item da lista
            }else if(i == list->tamanho-1){
                remov_elemento = list->tail;
                list->tail = list->tail->prev;
		list->tail->next = NULL;
            // se for qualquer outro item
            }else {
                aux = list->head;
                for(j=1;j<i+1;++j){
                    aux = aux->next;
                }
                    remov_elemento = aux;
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
            }
            free(remov_elemento);
            list->tamanho--;

            printf("Disciplina excluida!\n");
            break;
        } else if (i == list->tamanho - 1) {
            printf("Não existe essa\n");
        }// END IF ELSE
    }// END FOR
}

// Funcao para escolher qual disciplina sera excluida 
void exclui_disciplina(Lista_disciplina *list){
    int indice, excluir;
    char elemento[20];

    if(!is_empty_disciplina(list)){		    
	printf("Qual você deseja remover?\n");
        scanf(" %s", elemento);

        deleta_disciplina(list, elemento);	    
    }else {
        printf("Não há disciplina vinculada\n");
    } 
}

// Função para imprimir o Menu de visualizacao do aluno e retornar a resposta
int Menu_aluno(Node * aluno){
    int resposta;
    printf("_____________________________________________________________\n");
    printf("%s\n", aluno->Nome);
    printf("Menu de opções\n");
    printf("1) Cadastrar disciplina\n");
    printf("2) Listar disciplinas do aluno\n");
    printf("3) Editar disciplina do aluno\n");
    printf("4) Excluir disciplina do aluno\n");
    printf("5) Apresentar relatório geral do aluno\n");
    printf("6) Voltar para o menu principal\n");
    printf("_____________________________________________________________\n");
    scanf(" %d", &resposta);
    // confere se a resposta esta entre as possibilidades
    while (resposta <1 || resposta >7){
        printf("OPSS!!\nTente novamente\n");
	resposta = Menu();
    }
    return resposta;
}

// Funcao que recebe o Menu_aluno() e aciona o selecionado
void escolha_aluno(int resposta, Node * aluno){
    int r;
    Disciplina * d;

    switch (resposta){
	    case 1:
                cadastra_disciplina(d, aluno->Historico);
	    break;
	    case 2:
                print_lista_disciplina(aluno->Historico);
	    break;
	    case 3:
                edita_disciplina(aluno->Historico);        
	    break;
	    case 4: 
                exclui_disciplina(aluno->Historico);
	    break;
	    case 5: 
                relatorio_geral(aluno);
	    break;
       } // END switch
}

// Funcao para selecionar qual aluno sera visualizado
void visualiza_aluno(Node * alunos, Lista_aluno * list){
    char elemento[20]; 
    int resposta, indice;

    if (!is_empty(list)){
        printf("Deseja visualizar por nome ou email ou indice?\n<1>Nome\t<2>Indice\t<3>Email\n");		    
	scanf(" %d", &resposta);
        // confere se a resposta esta entre as possibilidades
        while (resposta <1 || resposta >3){
            printf("OPSS!!\nTente novamente\n");
            scanf(" %d", &resposta);
        }

	printf("Quem você deseja visualizar?\n");
        switch (resposta){
            case 1:
                scanf(" %s", elemento);
            break;
            case 2:
                scanf(" %d", &indice);
                strcpy(elemento, at_pos(list, indice-1)->Nome);
            break;
            case 3:
                scanf(" %s", elemento);
            break;
        }
    
        for (int i=0; i< list->tamanho; i++){
            if (strcmp(at_pos(list, i)->Nome, elemento)==0 ||strcmp( at_pos(list, i)->Email, elemento)==0){
                Node * aux;
                aux = at_pos(list, i);
                
                // apos selecionar o aluno entra em loop para o menu de visualizacao
                do{
                    resposta = Menu_aluno(aux);
                    escolha_aluno(resposta, aux);
                }while(resposta != 6);
                break;
            }else if (i == (list->tamanho - 1) ){
                printf("Não existe esse aluno\n");
            }
        }
    } else {
        printf("Não há alunos matriculados\n");
    }
}

