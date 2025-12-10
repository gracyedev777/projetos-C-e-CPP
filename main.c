#include <stdio.h>
#include <math.h>


void calcularCubo() {
    float n;
    printf("\n CALCULAR CUBO \n");
    printf("Digite um número: ");
    scanf("%f", &n);

    printf("O cubo de %.2f é: %.2f\n", n, n*n*n);
}

void bhaskara() {
    float a, b, c;
    float delta, x1, x2;

    printf("\nBHASKARA \n");
    printf("Digite os valores de a, b e c: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0) {
        printf("Não é equação do 2° grau (a não pode ser 0).\n");
        return;
    }

    delta = b*b - 4*a*c;

    printf("Delta = %.2f\n", delta);

    if (delta < 0) {
        printf("Não existem raízes reais.\n");
    } 
    else if (delta == 0) {
        x1 = -b / (2*a);
        printf("Raiz única: x = %.2f\n", x1);
    } 
    else {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    }
}


void calculadora() {
    float a, b;
    char op;

    printf("\n CALCULADORA \n");
    printf("Digite: numero operador numero (ex: 5 * 3): ");
    scanf("%f %c %f", &a, &op, &b);

    switch (op) {
        case '+': printf("Resultado: %.2f\n", a + b); break;
        case '-': printf("Resultado: %.2f\n", a - b); break;
        case '*': printf("Resultado: %.2f\n", a * b); break;
        case '/':
            if (b == 0)
                printf("Erro: divisão por zero!\n");
            else
                printf("Resultado: %.2f\n", a / b);
            break;
        default: printf("Operador inválido!\n");
    }
}


void blocoDeNotas() {
    char texto[200];

    printf("\n BLOCO DE NOTAS \n");
    printf("Digite uma frase (sem espaços): ");
    scanf("%199s", texto);

    printf("Você escreveu: %s\n", texto);
}


int main() {

    char nome[50];
    int opcao;

    
    printf("Digite seu nome: ");
    scanf("%49s", nome);
    printf("Bem-vindo, %s!\n", nome);

    do {
        printf("\n MENU PRINCIPAL \n");
        printf("Usuário: %s\n", nome);
        printf("1 - Bloco de Notas\n");
        printf("2 - Calculadora\n");
        printf("3 - Calcular Cubo\n");
        printf("4 - Bhaskara\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1: blocoDeNotas(); break;
            case 2: calculadora(); break;
            case 3: calcularCubo(); break;
            case 4: bhaskara(); break;

            case 0:
                printf("\nTchau, %s! Encerrando o programa...\n", nome);
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
