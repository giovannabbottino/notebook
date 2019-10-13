/*Giovanna Borges 170011267 trabalho1*/
// Include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20
// Cria a struct Funcionario
typedef struct {
    char *Nome;
    int Idade;
    char *Email;
} Funcionario;

// Imprime um funcionario f
void imprimeFuncionario(Funcionario f){
    printf("-------------------------------------\n");
    printf("%s\t -\t %s\t -\t %d\n", f.Nome, f.Email, f.Idade);
}

Funcionario alteraFuncionario(Funcionario f){
    int resposta;
    printf("O que deseja alterar?\n<1> Nome\t<2> Idade\t<3> Email\n");
    scanf(" %d", &resposta);
    while (resposta <1 || resposta >3){
            printf("OPSS!!\nTente novamente\n");
            scanf(" %d", &resposta);
    }
    printf("Qual o novo valor?\n");
    // escolhe uma acao de acordo com a resposta
    switch (resposta){
        // Nome
        case 1:
            scanf(" %s", f.Nome);
        break;
        // Idade
        case 2:
            scanf(" %d", &f.Idade);
        break;
        // Email
        case 3:
            scanf(" %s", f.Email);
        break;
    }
    return f;
}
// Função para criar um funcionario e retornar esse funcionario
Funcionario criaFuncionario(){
    Funcionario f;
    printf("Insira o nome:\n");
    f.Nome = (char*)malloc(TAM*sizeof(char*));
    scanf(" %s", f.Nome);

    printf("Insira a idade:\n");
    scanf(" %d", &f.Idade);
    
    printf("Insira o e-mail:\n");
    f.Email = (char*)malloc(TAM*sizeof(char*));
    scanf(" %s", f.Email);

    return f;
}

// Função para imprimir o Menu e retornar a resposta
int Menu(){
    int resposta;
    printf("--------------- Menu ---------------\n");
    printf("<1> Criar novo funcionario\n");
    printf("<2> Imprimir lista de funcionario\n");
    printf("<3> Excluir funcionario\n");
    printf("<4> Editar funcionario\n");
    printf("<5> Sair\n");
    scanf(" %d", &resposta);
    return resposta;
}

// Função main
int main(){
    // cria variavies usadas ao longo do codigo
    char elemento[20];
    int quantidade=0, i, j, resposta=0, aux, nova_quantidade, excluir, indice;
    // cria um vetor de funcionario
    Funcionario *funcionario;
    funcionario = (Funcionario*)malloc(sizeof(Funcionario*));
    // verifica se esta vazio
    if(funcionario == NULL){
        printf("Out of memory\n");
    }
    // loop para continuar entrando no menu
    while (resposta !=5){
	resposta = Menu();
        // confere se a resposta esta entre as possibilidades
	while (resposta <1 || resposta >5){
                printf("OPSS!!\nTente novamente\n");
		resposta = Menu();
	}
	// escolhe uma acao de acordo com a resposta
        switch (resposta){
            // criar novo funcionario
            case 1:
	        printf("Quantos novos funcionarios deseja adicionar?\n");
	        scanf(" %d", &nova_quantidade);
	        quantidade = quantidade + nova_quantidade;
	        funcionario = (Funcionario*) realloc(funcionario, quantidade * sizeof(Funcionario));
		for (i=quantidade-nova_quantidade; i<quantidade; i++){
                    funcionario[i] = criaFuncionario();
                }
            break;
            // imprimir lista de funcionarios
            case 2:
                printf("Imprimindo sua lista de funcionarios...\n");
                if (quantidade == 0){
		     printf("Não há funcionarios\n");
		} else {
		    for (i=0; i<quantidade;i++){
			imprimeFuncionario(funcionario[i]);
                    }
		}
            break;
            // excluir funcionario
	    case 3:
	        if (quantidade == 0){
		    printf("Não há funcionarios para remover\n");
		} else{
                    printf("Deseja remover por nome ou indice?\n<1>Nome\t<2>Indice\n");		    
		    scanf(" %d", &excluir);
                    // confere se a resposta esta entre as possibilidades
                    while (excluir <1 || excluir >2){
                            printf("OPSS!!\nTente novamente\n");
                            scanf(" %d", &excluir);
                    }
	            printf("Quem você deseja remover?\n");
         	    if (excluir == 1){
		        scanf(" %s", elemento);
		    } else if (excluir == 2){
			scanf(" %d", &indice);
			strcpy(elemento,funcionario[indice].Nome);
		    }	    
		    for (i=0; i<quantidade; i++){
                        if (strcmp(funcionario[i].Nome,elemento)==0){
                            for (j=i; j<quantidade-1; j++){
                               funcionario[j] = funcionario[j+1];
			       if ( j + 1 == quantidade){
			           free(funcionario[j+1].Nome);
			           free(funcionario[j+1].Email);
			       }
                            } // END FOR
                            quantidade -= 1;
                            funcionario = (Funcionario*) realloc(funcionario, (quantidade) * sizeof(Funcionario));
                            printf("Funcionario excluido!\n");
                            break;
                            } else if (i == quantidade - 1) {
                            printf("Não existe esse funcionario\n");
                        }// END IF ELSE
                    }// END FOR
		 }// END IF ELSE
	    break;
            case 4: 
                if (quantidade == 0){
		    printf("Não há funcionarios para alterar\n");
		} else{
	            printf("Quem você deseja alterar?\n");
		    scanf(" %s", elemento);
		    for (i=0; i<quantidade; i++){
		        if (strcmp(funcionario[i].Nome,elemento)==0 ||strcmp(funcionario[i].Email,elemento)==0){
			    funcionario[i] = alteraFuncionario(funcionario[i]);
                            break;
		        }else if (i == (quantidade - 1) ){
                            printf("Não existe esse funcionario\n");
                        }// END IF ELSE
		    }// END FOR 
		} // end if 
	    break;
        } // END switch
    }// END WHILE
    for (i=0; i<quantidade; i++){
        free(funcionario[i].Nome);
	free(funcionario[i].Email);
    } 
    free(funcionario); 
    return 0;
}
