#include <iostream>
#include <math.h>
#include <stdexcept>
#include <algorithm>

using namespace std;

const int MAX_TRIANGULOS = 5;

class Triangulo {
private:
    float ladoA, ladoB, ladoC;

public:
    Triangulo() : ladoA(0), ladoB(0), ladoC(0) {}

    float getLadoA() const { return ladoA; }
    float getLadoB() const { return ladoB; }
    float getLadoC() const { return ladoC; }

    void setLadoA(float valor) { ladoA = (valor < 0) ? 0 : valor; }
    void setLadoB(float valor) { ladoB = (valor < 0) ? 0 : valor; }
    void setLadoC(float valor) { ladoC = (valor < 0) ? 0 : valor; }

    void lerLados() {
        float lado;
        cout << "\nLeitura dos lados:\n";
        do {
            for (int i = 0; i < 3; i++) {
                cin >> lado;
                if (i == 0) setLadoA(lado);
                else if (i == 1) setLadoB(lado);
                else setLadoC(lado);
            }
            if (!ehValido()) {
                cout << "\nNão é possível fazer um triângulo com os dados inseridos!\nTente novamente:\n";
            }
        } while (!ehValido());
    }

    bool ehValido() const {
        return (abs(ladoB - ladoC) < ladoA && ladoA < (ladoB + ladoC)) &&
               (abs(ladoA - ladoC) < ladoB && ladoB < (ladoA + ladoC)) &&
               (abs(ladoA - ladoB) < ladoC && ladoC < (ladoB + ladoA));
    }

    float calcularPerimetro() const {
        return ladoA + ladoB + ladoC;
    }

    int tipoDoTriangulo() const {
        if (ladoA == ladoB && ladoB == ladoC) return 1;
        else if (ladoA == ladoB || ladoB == ladoC || ladoA == ladoC) return 2;
        else return 3;
    }

    bool operator==(const Triangulo& outro) const {
        float lados1[] = {ladoA, ladoB, ladoC};
        float lados2[] = {outro.ladoA, outro.ladoB, outro.ladoC};
        sort(lados1, lados1 + 3);
        sort(lados2, lados2 + 3);
        return (lados1[0] == lados2[0] && lados1[1] == lados2[1] && lados1[2] == lados2[2]);
    }
};

int main() {
    Triangulo triangulos[MAX_TRIANGULOS];
    int opcao = 0, qtdTriangulos = 0;

    do {
        cout << "\nBem vindo ao Triângulo Maker 2019!\nPor favor escolha uma das opções abaixo:\n"
             << "0 - Sair do programa\n1 - Faça um triângulo\n2 - Verifique se dois triângulos são iguais\n";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "\nObrigado por usar o Triangulo Maker 2019!\n";
                break;
            case 1:
                if (qtdTriangulos < MAX_TRIANGULOS) {
                    triangulos[qtdTriangulos].lerLados();
                    cout << "\nParabéns!\nO seu triângulo foi feito, vamos conferir as informações do seu triângulo:\n";
                    cout << "Número do triângulo: " << qtdTriangulos + 1 << "\nValor dos lados:\n"
                         << triangulos[qtdTriangulos].getLadoA() << ", "
                         << triangulos[qtdTriangulos].getLadoB() << ", "
                         << triangulos[qtdTriangulos].getLadoC() << "\nPerímetro:\n"
                         << triangulos[qtdTriangulos].calcularPerimetro() << endl;
                    cout << "\nTipo de triângulo:\n";
                    switch (triangulos[qtdTriangulos].tipoDoTriangulo()) {
                        case 1: cout << "O triângulo lido é equilátero\n"; break;
                        case 2: cout << "O triângulo lido é isósceles\n"; break;
                        case 3: cout << "O triângulo lido é escaleno\n"; break;
                    }
                    qtdTriangulos++;
                } else {
                    cout << "Erro! Não é possível criar mais triângulos\n";
                }
                break;
            case 2:
                if (qtdTriangulos > 0) {
                    int triangulo1, triangulo2;
                    cout << "\nDigite o número dos dois triângulos na qual você gostaria de comparar:\n";
                    cin >> triangulo1 >> triangulo2;
                    triangulo1--; triangulo2--;
                    if (triangulos[triangulo1] == triangulos[triangulo2]) {
                        cout << "Os triângulos " << triangulo1 + 1 << " e " << triangulo2 + 1 << " são iguais!" << endl;
                    } else {
                        cout << "Os triângulos " << triangulo1 + 1 << " e " << triangulo2 + 1 << " não são iguais!" << endl;
                    }
                } else {
                    cout << "\nNenhum triângulo foi registrado no sistema\nVoltando ao menu...";
                }
                break;
            default:
                cout << "\nOpção inválida!Tente novamente:\n";
        }
    } while (opcao != 0);

    return 0;
}
