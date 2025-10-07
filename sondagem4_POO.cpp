#include <iostream>
#include <string>

using namespace std;

const int maxFunc = 50;

class Cliente {
private:
    string nome, cargo;
    int idade;

public:
    //constructor
    Cliente(string nomeCliente, string cargoCliente, int idadeCliente) {
        nome = nomeCliente;
        cargo = cargoCliente;
        idade = idadeCliente;
    }

    void exibir() {
        cout << "Nome: " << nome << endl;
        cout << "Cargo: " << cargo << endl;
        cout << "Idade: " << idade << endl;
    }
};

class GerenciadorClientes {
private:
    Cliente* clientes[maxFunc];
    int quantidadeClientes = 0;

public:
    ~GerenciadorClientes() {
        for (int i = 0; i < quantidadeClientes; ++i) {
            delete clientes[i];
        }
    }

    void adicionarCliente() {
        if (quantidadeClientes >= maxFunc) {
            cout << "\nCapacidade maxima de clientes atingida!" << endl;
            return;
        }

        string nome, cargo;
        int idade;

        cout << "\n--- Sistema de Cadastro de Clientes ---" << endl;
        cout << "Informe o nome: ";
        cin >> nome;
        cout << "Informe o cargo: ";
        cin >> cargo;
        cout << "Informe a idade: ";
        cin >> idade;

        clientes[quantidadeClientes] = new Cliente(nome, cargo, idade);
        quantidadeClientes++;
        cout << "Cliente cadastrado com sucesso!" << endl;
    }

    void exibirClientes() {
        if (quantidadeClientes == 0) {
            cout << "\nNenhum cliente cadastrado." << endl;
            return;
        }

        cout << "\n--- Exibicao do Cadastro de Clientes ---" << endl;
        for (int i = 0; i < quantidadeClientes; ++i) {
            cout << "\n   CODIGO: " << i + 1 << endl;
            clientes[i]->exibir();
        }
    }
};

int main() {
    GerenciadorClientes gerenciador;
    int opcao;

    do {
        cout << "\n--- SISTEMA DE CADASTRO ---\n" << endl;
        cout << "1 - CADASTRAR CLIENTE" << endl;
        cout << "2 - EXIBIR CLIENTES" << endl;
        cout << "3 - SAIR" << endl;
        cout << "\nDigite a opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                gerenciador.adicionarCliente();
                break;
            case 2:
                gerenciador.exibirClientes();
                break;
            case 3:
                cout << "\nEncerrando o sistema..." << endl;
                break;
            default:
                cout << "\nOpcao invalida. Tente novamente." << endl;
                break;
        }
    } while (opcao != 3);

    return 0;
}