#include <stdio.h>
#include <string.h>

#define MAX 100000

char matriculas[MAX][11];
char temp[MAX][11];

// Função para mesclar duas metades e contar inversões
long long merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;   // O(1) - Inicialização de variáveis
    long long inversions = 0;             // O(1) - Inicialização de variável

    // Mesclar as duas metades ordenadas
    while (i <= mid && j <= right) {      // O(n) no pior caso
        if (strcmp(matriculas[i], matriculas[j]) <= 0) { // O(10) para comparar strings
            strcpy(temp[k++], matriculas[i++]);          // O(10) para copiar strings
        } else {
            strcpy(temp[k++], matriculas[j++]);          // O(10) para copiar strings
            inversions += (mid - i + 1);                 // O(1) para contar inversões
        }
    }

    // Copiar os elementos restantes da primeira metade
    while (i <= mid) {                    // O(n/2) no pior caso
        strcpy(temp[k++], matriculas[i++]); // O(10) para copiar strings
    }

    // Copiar os elementos restantes da segunda metade
    while (j <= right) {                  // O(n/2) no pior caso
        strcpy(temp[k++], matriculas[j++]); // O(10) para copiar strings
    }

    // Copiar de volta para o vetor original
    for (i = left; i <= right; i++) {     // O(n) no pior caso
        strcpy(matriculas[i], temp[i]);   // O(10) para copiar strings
    }

    return inversions;                    // O(1)
}

// Função principal do merge sort modificada para contar inversões
long long mergeSort(int left, int right) {
    if (left >= right) return 0;          // O(1) - Caso base da recursão

    int mid = (left + right) / 2;         // O(1) - Cálculo do meio
    long long inversions = 0;             // O(1) - Inicialização de variável

    // Ordenar e contar inversões nas duas metades
    inversions += mergeSort(left, mid);   // T(n/2) - Recursão na metade esquerda
    inversions += mergeSort(mid + 1, right); // T(n/2) - Recursão na metade direita

    // Mesclar as duas metades e contar inversões cruzadas
    inversions += merge(left, mid, right); // O(n) - Mesclagem das metades

    return inversions;                    // O(1)
}

int main() {
    int n;

    // Ler os casos de teste
    while (scanf("%d", &n) == 1 && n > 0) { // O(1) para ler n e condição de parada
        // Ler as matrículas
        for (int i = 0; i < n; i++) {      // O(n)
            scanf("%s", matriculas[i]);    // O(10) para ler cada string
        }

        // Contar as inversões usando merge sort
        long long inversions = mergeSort(0, n - 1); // T(n) - chamada inicial

        // Imprimir o resultado
        printf("%lld\n", inversions);      // O(1) para imprimir
    }

    return 0;
}

/*
* Função de Recorrência
A função de recorrência para o algoritmo é:

𝑇(𝑛) =2⋅𝑇(𝑛/2)+𝑂(𝑛)
Teorema Mestre:

𝑇(𝑛)=2⋅𝑇(𝑛/2)+𝑂(𝑛)
De acordo com o teorema mestre, sabemos que:
𝑎=2
𝑏=2
𝑑=1

Comparando 
log𝑏(𝑎)=d
log2(2)=1

tempo
𝑇(𝑛)=𝑂(𝑛log𝑛)
T(n)=O(nlogn)

Espaço:
𝑂(𝑛) = O(n), devido ao vetor auxiliar usado na mesclagem.
*/
