#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

void printTabuleiro(int Coluna, int Linha, char peca);
int conversorXadrez(char coluna, int linha, int *x, int *y);
int movimentoValidoCavalo(int colunaAtual, int LinhaAtual, int novaColuna, int novaLinha);
void recursivePrintBispo(char colunaBispo, int linhaBispo, int novaColuna, int novaLinha, int contador, char peca);
void recursivePrintRainha(char colunaRainha, int linhaRainha, int novaColuna, int novaLinha, int contador, char peca);
void recursivePrintTorre(char colunaTorre, int linhaTorre, int novaColuna, int novaLinha, int contador, char peca);

int main() {
    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

    const char posicaox[9] = {'A','B','C','D','E','F','G','H'};
    const int posicaoy[9] = {1,2,3,4,5,6,7,8};

    int contador = 5;
    int novaColuna; // guarda valor das cordenadas convertidas para matriz
    int novaLinha;
    char peca = 'B'; // Essa variável gurda o valor das letras representando cada peça (B = bispo, T = torre, R = rainha, C = cavalo)

    // Função para converte coordenadas do xadrez para coordenadas matriz
    conversorXadrez( posicaox[2], posicaoy[0], &novaColuna, &novaLinha);
    printf("Posição inicial de bispo %c%d: \n", posicaox[2], posicaoy[0]); // Exemplo de posição inicial C1
    recursivePrintBispo(posicaox[2], posicaoy[0], novaColuna, novaLinha, contador, peca);

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.

    // Reaprovei as variáveis anteriores para fazer a movimentação da torre e rainha 

    peca = 'T'; // atribuindo o valor da peça torre 'T'

    printf("\n"); // Espaçamento entre as peças
    printf("-------------------------------------\n");
    printf("\nPosição inicial da torre %c%d: \n", posicaox[0], posicaoy[0]); // Exemplo de posição inicial A1

    conversorXadrez( posicaox[0], posicaoy[0], &novaColuna, &novaLinha);
    recursivePrintTorre(posicaox[0], posicaoy[0], novaColuna, novaLinha, contador, peca);


    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.

    printf("\n"); // Espaçamento entre as peças
    printf("-------------------------------------\n");
    printf("Posição inicial da rainha %c%d: \n", posicaox[3], posicaoy[0]); // Exemplo de posição inicial D1

    peca = 'R'; // peca recebe R para representar a Rainha
    contador = 3;

    conversorXadrez( posicaox[3], posicaoy[0], &novaColuna, &novaLinha);
    recursivePrintRainha(posicaox[3], posicaoy[0], novaColuna, novaLinha, contador, peca);

    // Nível Aventureiro - Movimentação do Cavalo

    int cavaloColuna = 4, cavaloLinha = 4;
    char coluna;
    int linha;
    peca = 'C';
    printf("-------------------------------------\n");
    printf("\n");
    printf("\n Mova o cavalo: \n");
    printf("\n");
    printTabuleiro(cavaloColuna, cavaloLinha, peca); 

    printf("\n Digite uma posição para mover o cavalo (ex: F 6 ou C 3): ");

    // Coletando a entrada do usuário para mover o cavalo
    scanf(" %c %d", &coluna, &linha);

    if(!conversorXadrez(coluna, linha, &novaColuna, &novaLinha)) {
        printf("Coordenadas invalidas!");
        return 0;
    }

    printf("%d %d", novaColuna, novaLinha);

    // validando entrada do usuário
    if (movimentoValidoCavalo(cavaloColuna, cavaloLinha, novaColuna, novaLinha)) {
        cavaloColuna = novaColuna;
        cavaloLinha = novaLinha;
    } else {
        printf("Movimento invalido!\n");
    }

    printTabuleiro(cavaloColuna, cavaloLinha, peca);

    return 0;
}

// Area com as funções usadas no programa

// Função para imprimir um tabuleiro
void printTabuleiro(int Coluna, int Linha, char peca) {
    printf ("\n  A B C D E F G H\n");
    for (int i =0; i < 8; i++) {
        printf("%d ", 8 -i);
        for (int j =0; j < 8; j++) {
            if(i == Coluna && j == Linha) {
                printf("%c ", peca);  // 👈 'P' representa a peça no tabuleiro
            } else {
                printf ("- ");
            }
        }
        printf("\n");
    }
}

// Essa função converte a entrada do usuário no formato coordenadas de xadrez para cordenadas de matriz.
int conversorXadrez(char coluna, int linha, int *y, int *x) {
    if (coluna <'A' || coluna >'H' || linha <1 || linha > 8) {
        return 0;
    }
    *x = coluna - 'A';
    *y = 8 - linha;

    return 1;
}

// Verifica se a entrada do usuário é válida para a peça Cavalo
int movimentoValidoCavalo(int colunaAtual, int LinhaAtual, int novaColuna, int novaLinha) {
    int diferencaColuna = novaColuna - colunaAtual;
    if (diferencaColuna < 0) diferencaColuna = -diferencaColuna;

    int diferencaLinha = novaLinha - LinhaAtual;
    if (diferencaLinha < 0) diferencaLinha = - diferencaLinha;

    return (diferencaColuna == 2 && diferencaLinha == 1) || (diferencaColuna == 1 && diferencaLinha ==2 );
}

// função recursiva que move o Bispo na diagonal superior direita
void recursivePrintBispo(char colunaBispo, int linhaBispo, int novaColuna, int novaLinha, int contador, char peca) {
    if (contador > 0) {
        colunaBispo ++;
        linhaBispo ++;
        novaColuna --;
        novaLinha ++;
        contador --;
        printf("\n");
        printf("Bispo move-se na diagonal para casa %c%d\n", colunaBispo, linhaBispo);
        // reaproveitando a função printTabuleiro dentro da função recursivePrintBispo
        printTabuleiro(novaColuna, novaLinha, peca);
        // chamando a função dentro da própria função (função recursiva)
        recursivePrintBispo(colunaBispo, linhaBispo, novaColuna, novaLinha, contador, peca);
    }
}

// função recursiva que move a Torre para cima
void recursivePrintTorre(char colunaTorre, int linhaTorre, int novaColuna, int novaLinha, int contador, char peca) {
    if (contador > 0) {
        linhaTorre ++;
        novaColuna --;
        contador --;
        printf("\n");
        printf("Torre move-se para cima para casa %c%d\n", colunaTorre, linhaTorre);
        // reaproveitando a função printTabuleiro dentro da função recursivePrintTorre
        printTabuleiro(novaColuna, novaLinha, peca);
        // chamando a função dentro da própria função (função recursiva)
        recursivePrintTorre(colunaTorre, linhaTorre, novaColuna, novaLinha, contador, peca);
    }
}

// função recursiva que move a Rainha para cima
void recursivePrintRainha(char colunaRainha, int linhaRainha, int novaColuna, int novaLinha, int contador, char peca) {
    if (contador > 0) {
        linhaRainha ++;
        novaColuna --;
        contador --;
        printf("\n");
        printf("Rainha move-se para cima para casa %c%d\n", colunaRainha, linhaRainha);
        // reaproveitando a função printTabuleiro dentro da função recursivePrintRainha
        printTabuleiro(novaColuna, novaLinha, peca);
        // chamando a função dentro da própria função (função recursiva)
        recursivePrintRainha(colunaRainha, linhaRainha, novaColuna, novaLinha, contador, peca);
    }
}

// O uso das funções me permitiu ter um bom reaproveitamento de código deixando a manutenção mais eficiente


