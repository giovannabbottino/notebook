#include <stdio.h>

#define MAX_N 25

// Função para resolver o problema usando abordagem gulosa
void solveGreedy(int n, int m, int blocks[]) {
    int count = 0; // Inicializa o contador de blocos - O(1)

    // Tentar usar os blocos maiores primeiro
    for (int i = 0; i < n; i++) {      // O(n) - Itera sobre os tipos de blocos
        while (m >= blocks[i]) {       // O(m/blocks[i]) no pior caso
            m -= blocks[i];            // Subtrai o comprimento do bloco atual - O(1)
            count++;                   // Incrementa o contador de blocos - O(1)
        }
    }

    // Verifica se conseguimos atingir o comprimento desejado
    if (m == 0) {                      // O(1) - Checa se comprimento desejado foi atingido
        printf("%d\n", count);         // Imprime o número de blocos usados - O(1)
    } else {
        printf("-1\n");                // Impossível atingir o comprimento desejado - O(1)
    }
}

int main() {
    int t;
    scanf("%d", &t); // Lê o número de instâncias - O(1)

    while (t--) { // O(t) - Itera sobre as instâncias
        int n, m;
        scanf("%d %d", &n, &m); // Lê n e m - O(1)

        int blocks[MAX_N];
        for (int i = 0; i < n; i++) { // O(n) - Lê os tipos de blocos
            scanf("%d", &blocks[i]); // O(1)
        }

        // Ordena os blocos em ordem decrescente (necessário para a abordagem gulosa)
        for (int i = 0; i < n - 1; i++) {       // O(n^2) - Ordenação simples
            for (int j = i + 1; j < n; j++) {   // O(n)
                if (blocks[i] < blocks[j]) {    // O(1) - Comparação
                    int temp = blocks[i];
                    blocks[i] = blocks[j];
                    blocks[j] = temp;          // Troca de elementos - O(1)
                }
            }
        }

        solveGreedy(n, m, blocks); // Chama a função gulosa - O(n \cdot m/blocks[i])
    }

    return 0; // Fim do programa - O(1)
}

/*
T(n,m)=O(n^2+n⋅m/blocks[i])
*/
