#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int main() {
    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.

    char posicaox[9] = {'A','B','C','D','E','F','G','H'};
    char posicaoy[9] = {'1','2','3','4','5','6','7','8'};

    printf("Posição inicial de bispo %c%c: \n", posicaox[2], posicaoy[0]); // Exemplo de posição inicial C1
    
    for (int i=1; i<=5; i++) {
        printf("Bispo move-se na diagonal para casa %c%c\n", posicaox[2 + i], posicaoy[0 + i]); // Movimentação diagonal para a direita e para cima
    }

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.

    /* Reaproveitarei as variáveis anteriores para fazer a movimentação da torre e rainha */

    printf("\n"); // Espaçamento entre as peças

    printf("\nPosição inicial da torre %c%c: \n", posicaox[0], posicaoy[0]); // Exemplo de posição inicial A1

    int i = 1;
    while (i <= 5) {
        printf("Torre move-se para direita %c%c\n", posicaox[0 + i], posicaoy[0]); // Movimentação para a direita
        i++;
    }

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.

    printf("\n"); // Espaçamento entre as peças
    printf("Posição inicial da rainha %c%c: \n", posicaox[3], posicaoy[0]); // Exemplo de posição inicial D1

    int j = 1;
    do {
        printf("Rainha move-se para esquerda %c%c\n", posicaox[3 - j], posicaoy[0]); // Movimentação para a esquerda
        j++;
    } while (j <= 3);

    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    return 0;
}
