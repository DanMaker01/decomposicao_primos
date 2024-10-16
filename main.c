#include <stdio.h>
#include <stdlib.h>

#define MAX 21

typedef struct {
    int number;
    int *factors;
    int count;
} Factorization;

// Função para decompor um número em fatores primos
Factorization decompor_em_primos(int n) {
    Factorization result;
    result.number = n;
    result.count = 0;
    result.factors = (int *)malloc(sizeof(int) * MAX); // Alocando espaço para os fatores

    if (n < 2) {
        result.count = 0;
        return result;
    }

    int i = 2;
    while (n > 1) {
        if (n % i == 0) {
            result.factors[result.count++] = i; // Armazenando o fator
            n /= i;
        } else {
            i++;
        }
    }

    return result;
}

// Função para comparar o número de fatores (para ordenar)
int compare(const void *a, const void *b) {
    return ((Factorization *)a)->count - ((Factorization *)b)->count;
}

// Função principal
int main() {
    Factorization factorizations[MAX];

    // Decompondo números de 0 a 20
    for (int i = 0; i < MAX; i++) {
        factorizations[i] = decompor_em_primos(i);
    }

    // // Ordenando pela quantidade de fatores
    // qsort(factorizations, MAX, sizeof(Factorization), compare);

    // Imprimindo os resultados
    for (int i = 0; i < MAX; i++) {
        printf("%d\t", factorizations[i].number);
        for (int j = 0; j < factorizations[i].count; j++) {
            printf("%d ", factorizations[i].factors[j]);
        }
        printf("\n");
        free(factorizations[i].factors); // Liberando a memória alocada
    }

    return 0;
}
