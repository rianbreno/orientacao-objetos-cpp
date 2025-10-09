#include <iostream>
#include <string>

using namespace std;

const int maxFunc = 10;

class Funcionario {
private:
    string nome;
    string cargo;
    float salarioAtual;
    float novoSalario;

public:
    Funcionario() {
        // Construtor padrão para o array
        cout << "Objeto Funcionario construído (default)." << endl;
    }

    Funcionario(string nomeFunc, float salarioFunc) {
        nome = nomeFunc;
        salarioAtual = salarioFunc;
        novoSalario = 0.0;
        cout << "Objeto Funcionario construído: " << nome << endl;
    }

    ~Funcionario() {
        cout << "Objeto Funcionario destruído: " << nome << endl;
    }

    void calcularAumento(int opcaoCargo) {
        float aumento = 0.0;

        switch (opcaoCargo) {
            case 101:
                aumento = 0.10;
                cargo = "Gerente";
                break;
            case 102:
                aumento = 0.20;
                cargo = "Engenheiro";
                break;
            case 103:
                aumento = 0.40;
                cargo = "Outro Cargo";
                break;
            default:
                cout << "Opcao de cargo invalida!" << endl;
        }

        novoSalario = salarioAtual * (1.0 + aumento);
    }

    string getNome() { return nome; }
    string getCargo() { return cargo; }
    float getSalarioAtual() { return salarioAtual; }
    float getNovoSalario() { return novoSalario; }
};



class Empresa {
private:
    Funcionario funcionarios[maxFunc];
    int numFuncionarios = 0;

public:
    /*Empresa() {
        //cout << "Objeto Empresa construído" << endl;
    }

    ~Empresa() {
        // Quando o objeto Empresa é destruído, os objetos Funcionario no array são automaticamente destruídos também
        cout << "Objeto Empresa destruído." << endl;
    }
    */

    void novoFunc() {
        string nome;
        float salario;
        int opcaoCargo;

        cout << "Dados do funcionario " << numFuncionarios + 1 << endl;
        cout << "Informe o nome: ";
        cin >> nome;

        cout << "Informe o salario atual: R$ ";
        cin >> salario;

        cout << "Informe o cargo: " << endl;
        cout << "101 - Gerente" << endl;
        cout << "102 - Engenheiro" << endl;
        cout << "103 - Outro cargo" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcaoCargo;

        Funcionario novo(nome, salario);
        novo.calcularAumento(opcaoCargo);

        // Adiciona o novo objeto Funcionario no array
        funcionarios[numFuncionarios] = novo;
        numFuncionarios++;
    }

    void mostrarDadosFuncionarios() {
        if (numFuncionarios == 0) {
            cout << "\nNenhum funcionario foi cadastrado." << endl;
            return;
        }

        cout << "\n--- Dados dos Funcionarios Cadastrados ---" << endl;
        for (int i = 0; i < numFuncionarios; i++) {
            cout << "Nome: " << funcionarios[i].getNome() << endl;
            cout << "Cargo: " << funcionarios[i].getCargo() << endl;
            cout << "Salario Antigo: R$ " << funcionarios[i].getSalarioAtual() << endl;
            cout << "Novo Salario: R$ " << funcionarios[i].getNovoSalario() << endl;
        }
        cout << "------------------------------------------" << endl;
    }

    void mostrarEstatisticas() {
        int numGerentes = 0;
        int numEngenheiros = 0;
        float custoTotalAtual = 0.0;
        float custoTotalNovo = 0.0;

        for (int i = 0; i < numFuncionarios; i++) {
            if (funcionarios[i].getCargo() == "Gerente") {
                numGerentes++;
            } else if (funcionarios[i].getCargo() == "Engenheiro") {
                numEngenheiros++;
            }
            custoTotalAtual += funcionarios[i].getSalarioAtual();
            custoTotalNovo += funcionarios[i].getNovoSalario();
        }

        cout << "\n--- Estatisticas da Empresa ---" << endl;
        cout << "Numero de Gerentes: " << numGerentes << endl;
        cout << "Numero de Engenheiros: " << numEngenheiros << endl;
        cout << "Custo total atual com salarios: R$ " << custoTotalAtual << endl;
        cout << "Custo total apos o aumento: R$ " << custoTotalNovo << endl;
    }

    bool limiteAtingido() {
        return numFuncionarios >= maxFunc;
    }
};

int main() {
    Empresa minhaEmpresa;
    int continuar = 1;

    cout << ">>> CADASTRO DE FUNCIONARIOS E CALCULO DE AUMENTO SALARIAL <<<" << endl;

    do {
        if (minhaEmpresa.limiteAtingido()) {
            cout << "Limite de " << maxFunc << " funcionarios atingido. Encerrando o cadastro." << endl;
            break;
        }

        minhaEmpresa.novoFunc();

        if (!minhaEmpresa.limiteAtingido()) {
            cout << "\nDeseja cadastrar outro funcionario? " << endl;
            cout << "Digite 1 para CONTINUAR ou 0 para ENCERRAR: ";
            cin >> continuar;
        }

    } while (continuar == 1);

    minhaEmpresa.mostrarDadosFuncionarios();
    minhaEmpresa.mostrarEstatisticas();

    cout << "\n";
    return 0;
}