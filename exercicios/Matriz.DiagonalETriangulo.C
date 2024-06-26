/* Faça um algoritmo que:

a) imprima os elementos da diagonal principal de uma matriz e a soma deles
b) imprima os elementos da diagonal secundária de uma matriz e a soma deles
c) imprima os elementos abaixo da diagonal principal de uma matriz e a soma deles
d) imprima os elementos abaixo da diagonal secundária de uma matriz e a soma deles
d) imprima a soma total
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int x, soma1 = 0, soma2 = 0, somaT1 = 0, somaT2 = 0, somaTotal;
    srand(time(NULL)); // Muda a semente dos números aleatórios

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &x);

    int m[x][x];

    // Prenche e imprime a matriz:
    printf("\nConteudo da matriz:\n");

    for(int i = 0; i < x; i++) {
        printf("\nLinha %d: ", i + 1);
        for(int j = 0; j < x; j++) {
            m[i][j] = rand() % 100; // Gera números aleatórios de 0 a 100
            printf("%d\t", m[i][j] );
        }
        printf("\n");
    }

    // Imprime os elementos da diagonal principal e a soma deles:
    printf("\nConteudo da diagonal principal: ");

    int j = 0;

    for(int i = 0; i < x; i++) {
        soma1 += m[i][j];
        printf("%d ", m[i][j]);
        j++; // J é acrescentado depois
    }
    printf("\nSoma: %d\n", soma1); 

    // Imprime os elementos da diagonal secundária e a soma deles:
    printf("\nConteudo da diagonal secundaria: ");

    for(int i = 0; i < x; i++) {
        j--; // J é acrescentado antes pois no for anterior ele terminou com x + 1
        soma2 += m[i][j];
        printf("%d ", m[i][j]);
    }
    printf("\nSoma: %d\n", soma2); 

    // Imprime os elementos abaixo da diagonal principal de uma matriz e a soma deles:
    printf("\nConteudo abaixo da diagonal principal: ");

    for(int i = 1; i < x; i++) {
        for(int j = 0; j < x; j++) {
            if(j == i) // A condicional vem antes
                break;
            somaT1 += m[i][j];
            printf("%d ", m[i][j]);
        }
    }
    printf("\nSoma: %d\n", somaT1); 

    // Imprime os elementos abaixo da diagonal secundária de uma matriz e a soma deles:
    printf("\nConteudo abaixo da diagonal secundaria: ");

    for(int i = 1; i < x; i++) {
        for(int j = x - 1; j >= 0; j--) {
            somaT2 += m[i][j];
            printf("%d ", m[i][j]);
            if(j == x - i)  // A condicional vem depois, pois o for precisa rodar pelo menos uma vez antes de sair
                break;
        }
    }
    printf("\nSoma: %d\n", somaT2); 

    somaTotal = soma1 + soma2 + somaT1 + somaT2;

    // Imprime a soma total:
    printf("\nSoma Total: %d\n", somaTotal); 
}
