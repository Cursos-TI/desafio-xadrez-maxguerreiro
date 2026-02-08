#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

// Função para imprimir um tabuleiro para a peça Cavalo

void printTabuleiro(int cavaloColuna, int cavaloLinha) {
    printf ("\n  A B C D E F G H\n");
    for (int i =0; i < 8; i++) {
        printf("%d ", 8 -i);
        for (int j =0; j < 8; j++) {
            if(i == cavaloColuna && j == cavaloLinha) {
                printf("C ");  // 👈 'C' representa a peça cavalo no tabuleiro
            } else {
                printf ("- ");
            }
        }
        printf("\n");
    }
}

/* Essa função converte a entrada do usuário no formato 
 * coordenadas de xadrez para cordenadas de matriz. 
*/
int conversorXadrez(char coluna, int linha, int *x, int *y) {
    if (coluna <'A' || coluna >'H' || linha <1 || linha > 8) {
        return 0;
    }
    *y = coluna - 'A';
    *x = 8 - linha;

    return 1;
}

// Verifica se a entrada do usuário é valida para a peça Cavalo
int movimentoValidoCavalo(int colunaAtual, int LinhaAtual, int novaColuna, int novaLinha) {
    int diferencaColuna = novaColuna - colunaAtual;
    if (diferencaColuna < 0) diferencaColuna = -diferencaColuna;

    int diferencaLinha = novaLinha - LinhaAtual;
    if (diferencaLinha < 0) diferencaLinha = - diferencaLinha;

    return (diferencaColuna == 2 && diferencaLinha == 1) || (diferencaColuna == 1 && diferencaLinha ==2 );
}

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

    int cavaloColuna = 4, cavaloLinha = 4;
    char coluna;
    int linha;
    int novaColuna, novaLinha;

    printTabuleiro(cavaloColuna, cavaloLinha);

    // Coletando a entrada do usuário para mover o cavalo
    printf("\n Digite a posição para mover o cavalo (ex: F 6): ");
    scanf(" %c %d", &coluna, &linha);

    if(!conversorXadrez(coluna, linha, &novaColuna, &novaLinha)) {
        printf("Coordenadas invalidas!");
        return 0;
    }

    // validando entrada do usuário
    if (movimentoValidoCavalo(cavaloColuna, cavaloLinha, novaColuna, novaLinha)) {
        cavaloColuna = novaColuna;
        cavaloLinha = novaLinha;
    } else {
        printf("Movimento invalido!\n");
    }

    printTabuleiro(cavaloColuna, cavaloLinha);


    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    return 0;
}
