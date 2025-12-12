#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char nome[50];
    int vidaJogador = 30;
    int vidaInimigo = 20;
    int escolha;
    int danoJogador, danoInimigo;

    srand(time(NULL));

    printf("Digite seu nome heroi: ");
    scanf("%49s", nome);

    printf("\n  seja bem vindo ao C RPG \n");
    printf("%s, um monstro apareceu!\n", nome);

    while (vidaJogador > 0 && vidaInimigo > 0) {
        printf("\nVida de %s: %d | Vida do inimigo: %d\n", nome, vidaJogador, vidaInimigo);
        printf("1 - Atacar\n");
        printf("2 - Defender\n");
        printf("3 - Fugir\n");
        printf("-> ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                danoJogador = rand() % 10 + 1;
                danoInimigo = rand() % 8 + 1;
                printf("Você causou %d de dano!\n", danoJogador);
                vidaInimigo -= danoJogador;
                if (vidaInimigo > 0) {
                    printf("O inimigo causou %d de dano!\n", danoInimigo);
                    vidaJogador -= danoInimigo;
                }
                break;

            case 2:
                danoInimigo = (rand() % 8 + 1) / 2;
                printf("Você defendeu! Recebeu apenas %d de dano.\n", danoInimigo);
                vidaJogador -= danoInimigo;
                break;

            case 3:
                printf("%s fugiu da batalha!\n", nome);
                return 0;

            default:
                printf("Opção inválida!\n");
        }
    }

    if (vidaJogador <= 0)
        printf("\n%s foi derrotado...\n", nome);
    else
        printf("\n%s venceu o inimigo!\n", nome);

    return 0;
}
