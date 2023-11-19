#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H

#define X 1
#define O 2
#define VAZIO 0
#define TAMANHO_NOME 50

extern char jogador1_nome[TAMANHO_NOME];
extern char jogador2_nome[TAMANHO_NOME];

extern int tabuleiro[3][3];

void exibir_tabuleiro();
void inicializar_tabuleiro();
int realizar_jogada(int jogador);
int verificar_vencedor();
int tabuleiro_cheio();
void limpar_tela();

#endif