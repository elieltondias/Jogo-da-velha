#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo_da_velha.h"

char jogador1_nome[TAMANHO_NOME];
char jogador2_nome[TAMANHO_NOME];
int tabuleiro[3][3];

// Implementações das funções do jogo

void exibir_tabuleiro(){
    limpar_tela();
    printf("  1 2 3\n");
    for (int i = 0; i < 3; i++){
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++){
            if (tabuleiro[i][j] == X){
                printf("X|");
            } else if (tabuleiro[i][j] == O){
                printf("O|");
            } else{
                printf("_|");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void inicializar_tabuleiro(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = VAZIO;
        }
    }
}

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

            // Verificar se a posição está dentro dos limites
            if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == VAZIO) {
                break;  // Jogada válida, sair do loop
            } else {
                printf("Posicao invalida ou ja ocupada. Tente novamente.\n");
            }
        } else {
            printf("Entrada invalida. Digite dois numeros separados por espaço.\n");

            // Limpar o buffer do teclado para evitar problemas com entradas inválidas
            while (getchar() != '\n');
        }
    }

    tabuleiro[linha][coluna] = jogador;

    return verificar_vencedor();
}

int verificar_vencedor(){
    for (int i = 0; i < 3; i++){
        if (tabuleiro[i][0] != VAZIO && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2]){
            return tabuleiro[i][0];
        }
        if (tabuleiro[0][i] != VAZIO && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i]){
            return tabuleiro[0][i];
        }
    }

    if (tabuleiro[0][0] != VAZIO && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2]){
        return tabuleiro[0][0];
    }
    if (tabuleiro[0][2] != VAZIO && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0]){
        return tabuleiro[0][2];
    }

    return 0;
}

int tabuleiro_cheio(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tabuleiro[i][j] == VAZIO){
                return 0;
            }
        }
    }
    return 1;
}

void limpar_tela(){
    system("cls || clear");
}