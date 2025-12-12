#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dificuldade, limite, numeroSecreto, palpite, tentativas = 0;

int main() {
    printf("jogo de adivinhar numero\n");
    printf("qual dificuldade tu quer?\n");
    printf("1/facil 2/medio 3/dificil\n");
    printf("facil(1 ate 20) medio(1 ate 50) dificil(1 ate 100)\n");
    scanf("%d", &dificuldade);

    if (dificuldade == 1)
        limite = 20;
    else if (dificuldade == 2)
        limite = 50;
    else if (dificuldade == 3)
        limite = 100;
    else {
        printf("Opcao invalida!\n");
        return 0;
    }

    srand(time(NULL));
    numeroSecreto = rand() % limite + 1;

    printf("\nTente adivinhar o numero entre 1 e %d!\n\n", limite);

    do {
        printf("Seu palpite: ");
        scanf("%d", &palpite);
        tentativas++;

        if (palpite > numeroSecreto)
            printf("Muito alto!\n\n");
        else if (palpite < numeroSecreto)
            printf("Muito baixo!\n\n");
        else
            printf("\nParabens! Voce acertou em %d tentativas!\n", tentativas);

    } while (palpite != numeroSecreto);

    return 0;
}
