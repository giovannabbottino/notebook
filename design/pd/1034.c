#include <stdio.h>
#include <limits.h>

#define MAX_M 1000000
#define MAX_N 25

int dp[MAX_M + 1]; // Vetor para armazenar os resultados parciais - O(MAX_M)

// Função para resolver o problema usando Programação Dinâmica
void solveDP(int n, int m, int blocks[]) {
    // Inicializa o vetor dp com um valor muito alto (infinito)
    for (int i = 1; i <= m; i++) { // O(m)
        dp[i] = INT_MAX;          // Inicializa dp[i] com infinito
    }
    dp[0] = 0; // Caso base: 0 blocos para atingir comprimento 0 - O(1)

    // Preenchimento da tabela dp
    for (int i = 0; i < n; i++) {         // O(n) - Itera pelos tipos de blocos
        for (int j = blocks[i]; j <= m; j++) { // O(m) para cada bloco
            if (dp[j - blocks[i]] != INT_MAX) {  // O(1) - Verifica se é possível alcançar comprimento j
                dp[j] = dp[j] < dp[j - blocks[i]] + 1 ? dp[j] : dp[j - blocks[i]] + 1; // O(1) - Atualiza dp[j]
            }
        }
    }

    // Verifica a solução final
    if (dp[m] == INT_MAX) { // O(1)
        printf("-1\n");    // Impossível atingir o comprimento desejado - O(1)
    } else {
        printf("%d\n", dp[m]); // Imprime o número mínimo de blocos necessários - O(1)
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

        solveDP(n, m, blocks); // Chama a função de DP - O(n \cdot m)
    }

    return 0; // Fim do programa - O(1)
}

/* 
T(n,m)=O(n⋅m)
O(n): Para iterar sobre os tipos de blocos.
O(m): Para atualizar os possíveis comprimentos alcançáveis com cada tipo de bloco.
Complexidade Assintótica
Tempo: 
𝑂(𝑛⋅𝑚)=O(n⋅m)

n é o número de tipos de blocos.
m é o comprimento desejado.
Espaço: 
𝑂(𝑚)=O(m), pois usamos um vetor de tamanho m para armazenar os resultados parciais.
*/
