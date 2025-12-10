#include <iostream>
#include <cmath>
using namespace std;

void hackearCaixa() {
    cout << "Você está tentando hackear o caixa! Prepare-se para os desafios...\n" << endl;

    cout << "1. Qual a fórmula de Bhaskara para resolver ax² + bx + c = 0?" << endl;
    cout << "Resposta (digite a fórmula completa): ";
    string resposta1;
    getline(cin, resposta1);
    if (resposta1.find("x = (-b ± √(b² - 4ac)) / 2a") != string::npos) {
        cout << "Correto! Você é um gênio matemático.\n" << endl;
    } else {
        cout << "Incorreto! A fórmula correta é: x = (-b ± √(b² - 4ac)) / 2a\n" << endl;
    }

    cout << "2. Qual é a derivada da função f(x) = e^(x²) * ln(x)?" << endl;
    cout << "Resposta (digite a expressão): ";
    string resposta2;
    getline(cin, resposta2);
    if (resposta2.find("e^(x²) * (2x ln(x) + 1/x)") != string::npos) {
        cout << "INCRÍVEL! Você acertou!\n";
        cout << "PARABÉNS! Você ganhou 200 BILHÕES DE DÓLARES!\n";
        cout << "Mas: o FBI está vindo atrás de você. Fugir é a melhor opção!" << endl;
    } else {
        cout << "Incorreto! A derivada correta é: e^(x²) * (2x ln(x) + 1/x)\n" << endl;
    }
}

int main() {
    int saldo = 1000;
    int opcao;
    int valor;

    while (true) {
        cout << "Caixa Eletrônico" << endl;
        cout << "1. Ver saldo" << endl;
        cout << "2. Sacar dinheiro" << endl;
        cout << "3. Depositar dinheiro" << endl;
        cout << "4. Sair" << endl;
        cout << "5. Hackear" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                cout << "Seu saldo é: R$" << saldo << endl;
                break;
            case 2:
                cout << "Digite o valor para sacar: R$";
                cin >> valor;
                cin.ignore();
                if (valor > saldo) {
                    cout << "Saldo insuficiente!" << endl;
                } else if (valor <= 0) {
                    cout << "Valor inválido!" << endl;
                } else {
                    saldo -= valor;
                    cout << "Saque realizado com sucesso!" << endl;
                }
                break;
            case 3:
                cout << "Digite o valor para depositar: R$";
                cin >> valor;
                cin.ignore();
                if (valor <= 0) {
                    cout << "Valor inválido!" << endl;
                } else {
                    saldo += valor;
                    cout << "Depósito realizado com sucesso!" << endl;
                }
                break;
            case 4:
                cout << "Obrigado por usar o caixa eletrônico!" << endl;
                return 0;
            case 5:
                hackearCaixa();
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
        cout << endl;
    }

    return 0;
}