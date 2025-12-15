#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Tarefa {
public:
    string descricao;
    bool concluida;

    Tarefa(const string& desc) : descricao(desc), concluida(false) {}
};

class GerenciadorDeTarefas {
private:
    vector<Tarefa> tarefas;

public:
    void adicionarTarefa() {
        string descricao;
        cout << "Digite a descricao da tarefa: ";
        cin.ignore();
        getline(cin, descricao);
        tarefas.push_back(Tarefa(descricao));
    }

    void removerTarefa() {
        int indice;
        cout << "Digite o numero da tarefa a remover: ";
        cin >> indice;

        if (indice > 0 && indice <= tarefas.size()) {
            tarefas.erase(tarefas.begin() + indice - 1);
        } else {
            cout << "Indice invalido\n";
        }
    }

    void marcarComoConcluida() {
        int indice;
        cout << "Digite o numero da tarefa: ";
        cin >> indice;

        if (indice > 0 && indice <= tarefas.size()) {
            tarefas[indice - 1].concluida = true;
        } else {
            cout << "Indice invalido\n";
        }
    }

    void exibirTarefas() {
        if (tarefas.empty()) {
            cout << "Nenhuma tarefa\n";
            return;
        }

        for (int i = 0; i < tarefas.size(); i++) {
            cout << i + 1 << " - " << tarefas[i].descricao
                 << (tarefas[i].concluida ? " [Concluida]" : " [Pendente]") << endl;
        }
    }

    void salvarEmArquivo() {
        string nomeArquivo;
        cout << "Nome do arquivo: ";
        cin >> nomeArquivo;

        ofstream arquivo(nomeArquivo);
        if (!arquivo) {
            cout << "Erro ao salvar\n";
            return;
        }

        for (auto& tarefa : tarefas) {
            arquivo << tarefa.descricao << ";" << tarefa.concluida << endl;
        }

        arquivo.close();
    }

    void carregarDeArquivo() {
        string nomeArquivo;
        cout << "Nome do arquivo: ";
        cin >> nomeArquivo;

        ifstream arquivo(nomeArquivo);
        if (!arquivo) {
            cout << "Erro ao carregar\n";
            return;
        }

        tarefas.clear();
        string linha;

        while (getline(arquivo, linha)) {
            size_t pos = linha.find(';');
            if (pos != string::npos) {
                string desc = linha.substr(0, pos);
                bool concluida = linha.substr(pos + 1) == "1";
                Tarefa t(desc);
                t.concluida = concluida;
                tarefas.push_back(t);
            }
        }

        arquivo.close();
    }
};

int main() {
    GerenciadorDeTarefas gerenciador;
    int opcao;

    do {
        cout << "\n1 Adicionar\n2 Remover\n3 Concluir\n4 Exibir\n5 Salvar\n6 Carregar\n7 Sair\nOpcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: gerenciador.adicionarTarefa(); break;
            case 2: gerenciador.removerTarefa(); break;
            case 3: gerenciador.marcarComoConcluida(); break;
            case 4: gerenciador.exibirTarefas(); break;
            case 5: gerenciador.salvarEmArquivo(); break;
            case 6: gerenciador.carregarDeArquivo(); break;
        }
    } while (opcao != 7);

    return 0;
}
