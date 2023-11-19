#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H

// Definições de constantes para representar os jogadores e o estado do tabuleiro
#define X 1
#define O 2
#define VAZIO 0
#define TAMANHO_NOME 50  // Tamanho máximo dos nomes dos jogadores

// Declaração das variáveis globais que armazenam os nomes dos jogadores e o estado do tabuleiro
extern char jogador1_nome[TAMANHO_NOME];
extern char jogador2_nome[TAMANHO_NOME];
extern int tabuleiro[3][3];

// Declaração das funções que serão implementadas no código-fonte (arquivo .c) correspondente
void exibir_tabuleiro();
void inicializar_tabuleiro();
int realizar_jogada(int jogador);
int verificar_vencedor();
int tabuleiro_cheio();
void limpar_tela();

#endif