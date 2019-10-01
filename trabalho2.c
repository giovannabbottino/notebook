/*Giovanna Borges 170011267 trabalho2 gibottino@gmail.com*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20

// Cria a struct Aluno
typedef struct {
    char *Nome; 
    int Mencao;
    struct Disciplina *proximo;
} Disciplina;

// Cria a struct Aluno
typedef struct {
    char *Nome;
    int Matricula;
    char *Email;
    Disciplina *historico; 
    struct Aluno *proximo;
} Aluno;

void validacao_Mencao(char *resposta){
    //https://www.linuxquestions.org/questions/programming-9/c-returning-char-array-pointer-4175490314/
    scanf(" %s", resposta);
    while (resposta != "TR" && resposta != "SR" && resposta != "II" && resposta != "MI" && resposta != "MM" && resposta != "MS" && resposta != "SS"){
        printf("OPSS!!\nTente novamente\n");
	scanf("%s", resposta);
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
// Função para criar um aluno
void cria_aluno(Aluno * a){
//http://linguagemc.com.br/funcao-com-passagem-por-referencia/
    printf("Insira o nome:\n");
    a->Nome = (char*)malloc(TAM*sizeof(char*));
    scanf(" %s", a->Nome);

    printf("Insira a idade:\n");
    scanf(" %d", &a->Matricula);
    
    printf("Insira o e-mail:\n");
    a->Email = (char*)malloc(TAM*sizeof(char*));
    scanf(" %s", a->Email);
}

void cadastra_aluno(Aluno **alunos, int * quantidade){
    int nova_quantidade, i, qtd;
    printf("Quantos novos alunos deseja adicionar?\n");
    scanf(" %d", &nova_quantidade);
    qtd = *quantidade + nova_quantidade;
    printf("%ls", &qtd);
    alunos = (Aluno*) realloc(alunos, qtd * sizeof(Aluno));
    for (i=*quantidade-nova_quantidade; i<qtd; i++){
        cria_aluno(&alunos[i]);
    }
}

// Função main
int main(){
    int resposta, quantidade=0;
    Aluno *alunos;
    alunos = (Aluno*)malloc(sizeof(Aluno*));
    // verifica se esta vazio
    if(alunos == NULL){
        printf("Out of memory\n");
    }
    // loop para continuar entrando no menu
    while (resposta !=6){
	resposta = Menu();
	// escolhe uma acao de acordo com a resposta
	switch (resposta){
	    // Cadastrar aluno
	    case 1:
                cadastra_aluno(&alunos, &quantidade);
	    break;
	    // Listar alunos
	    case 2:
	    break;
	    // Visualizar aluno
	    case 3:        
	    break;
	    // Editar aluno
	    case 4: 
	    break;
	    // Excluir aluno
	    case 5: 
	    break;
       } // END switch

    }
    return 0;
}
