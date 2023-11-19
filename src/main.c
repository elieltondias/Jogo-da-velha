#include <stdio.h>
#include "jogo_da_velha.h"

int main() {
    int jogar_novamente = 1;  // Variável para controlar se quer jogar novamente

    limpar_tela();

    while (jogar_novamente) {
        printf("\tBEM-VINDO AO JOGO DA VELHA\n\n");

        printf("Digite o nome do Jogador 1: ");
        scanf("%s", jogador1_nome);

        printf("Digite o nome do Jogador 2: ");
        scanf("%s", jogador2_nome);

        int jogador_atual = X;
        int vencedor = 0;

        while (!vencedor && !tabuleiro_cheio()) {
            exibir_tabuleiro();
            vencedor = realizar_jogada(jogador_atual);

            if (!vencedor) {
                jogador_atual = (jogador_atual == X) ? O : X;
            }
        }

        exibir_tabuleiro();

        if (vencedor) {
            printf("Parabens, %s! Voce venceu!\n", (vencedor == X) ? jogador1_nome : jogador2_nome);
        } else {
            printf("O jogo empatou. VELHA!\n");
        }

        // Pergunta aos jogadores se querem jogar novamente
        printf("Deseja jogar novamente? (1 para sim, 0 para não): ");
        scanf("%d", &jogar_novamente);

        limpar_tela();

        // Reinicia o estado do jogo se estiver jogando novamente
        if (jogar_novamente) {
            inicializar_tabuleiro();
        }
    }

    printf("Obrigado por jogar! Adeus!\n");

    return 0;
}