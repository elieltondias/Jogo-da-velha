#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo_da_velha.h"

// Definição do tamanho do nome dos jogadores
char jogador1_nome[TAMANHO_NOME];
char jogador2_nome[TAMANHO_NOME];

// Representação do tabuleiro do jogo
int tabuleiro[3][3];

// Implementações das funções do jogo

// Função para exibir o estado atual do tabuleiro
void exibir_tabuleiro() {
    limpar_tela();
    printf("  1 2 3\n");
    int i, j;
    for (i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == X) {
                printf("X|");
            } else if (tabuleiro[i][j] == O) {
                printf("O|");
            } else {
                printf("_|");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Função para inicializar o tabuleiro com espaços vazios
void inicializar_tabuleiro() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabuleiro[i][j] = VAZIO;
        }
    }
}

// Função para realizar uma jogada de um jogador específico
int realizar_jogada(int jogador) {
    int linha, coluna;

    printf("Vez do Jogador %c.\n", (jogador == X) ? 'X' : 'O');
    
    // Loop para garantir uma entrada válida
    while (1) {
        printf("Digite a linha e a coluna (por exemplo, 1 2): ");
        
        // Verificar se a leitura foi bem-sucedida
        if (scanf("%d %d", &linha, &coluna) == 2) {
            linha--;
            coluna--;

            // Verificar se a posição está dentro dos limites e vazia
            if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == VAZIO) {
                break;  // Jogada válida, sair do loop
            } else {
                printf("Posicao invalida ou ja ocupada. Tente novamente.\n");
            }
        } else {
            printf("Entrada invalida. Digite dois numeros separados por espaco.\n");

            // Limpar o buffer do teclado para evitar problemas com entradas inválidas
            while (getchar() != '\n');
        }
    }

    tabuleiro[linha][coluna] = jogador;

    return verificar_vencedor();
}

// Função para verificar se há um vencedor
int verificar_vencedor() {
    int i;
    for (i = 0; i < 3; i++) {
        // Verificar linhas e colunas
        if (tabuleiro[i][0] != VAZIO && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2]) {
            return tabuleiro[i][0];
        }
        if (tabuleiro[0][i] != VAZIO && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i]) {
            return tabuleiro[0][i];
        }
    }

    // Verificar diagonais
    if (tabuleiro[0][0] != VAZIO && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2]) {
        return tabuleiro[0][0];
    }
    if (tabuleiro[0][2] != VAZIO && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0]) {
        return tabuleiro[0][2];
    }

    return 0;  // Nenhum vencedor ainda
}

// Função para verificar se o tabuleiro está cheio (empate)
int tabuleiro_cheio() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == VAZIO) {
                return 0;  // Ainda há espaços vazios
            }
        }
    }
    return 1;  // Tabuleiro está cheio
}

// Função para limpar a tela (dependente do sistema operacional)
void limpar_tela() {
    system("cls || clear");
}
