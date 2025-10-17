#include <iostream>
#include <string>

using namespace std;

const int maxFunc = 10;

class Pessoa {
protected:
    string nome;
    float salarioAtual;

public:
    // Construtor
    Pessoa(const string& nomePessoa, float salario) : nome(nomePessoa), salarioAtual(salario) {}

    // Destrutor virtual
    virtual ~Pessoa() = default;

    virtual void exibirDados() const = 0;
    virtual float getNovoSalario() const = 0;
    virtual string getCargo() const = 0;

    string getNome() const { return nome; }
    float getSalarioAtual() const { return salarioAtual; }
};

class Funcionario : public Pessoa {
private:
    string cargo;
    float novoSalario;

public:
    Funcionario() : Pessoa("", 0.0), cargo(""), novoSalario(0.0) {}

    Funcionario(const string& nomeFunc, float salarioFunc, const string& cargoFunc) : Pessoa(nomeFunc, salarioFunc), cargo(cargoFunc), novoSalario(0.0f) {

        calcularAumento();
    }

    ~Funcionario() override = default;

    void exibirDados() const override {
        cout << "Nome: " << nome << endl;
        cout << "Cargo: " << cargo << endl;
        cout << "Salario Antigo: R$ " << salarioAtual << endl;
        cout << "Novo Salario: R$ " << novoSalario << endl;
    }

    void calcularAumento() {
        float aumento = 0.0;

        if (cargo == "Gerente") {
            aumento = 0.10;
        } else if (cargo == "Engenheiro") {
            aumento = 0.20;
        } else if (cargo == "Outro Cargo") {
            aumento = 0.40;
        } else {
            aumento = 0.0;
        }

        novoSalario = salarioAtual * (1.0 + aumento);
    }

    string getCargo() const override { return cargo; }
    float getNovoSalario() const override { return novoSalario; }
};

class Empresa {
private:
    Funcionario funcionarios[maxFunc];
    int numFuncionarios = 0;

    int lerOpcaoCargo() const {
        int opcaoCargo;
        cout << "Informe o cargo: " << endl;
        cout << "101 - Gerente" << endl;
        cout << "102 - Engenheiro" << endl;
        cout << "103 - Outro cargo" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcaoCargo;
        return opcaoCargo;
    }

    string converterOpcaoParaCargo(int opcao) const {
        switch (opcao) {
            case 101: return "Gerente";
            case 102: return "Engenheiro";
            case 103: return "Outro Cargo";
            default:
                cout << "Opcao de cargo invalida!" << endl;
                return "Não Definido";
        }
    }

public:
    const int maxFunc = maxFunc;

    void novoFunc() {
        if (limiteAtingido()) {
            return;
        }

        string nome;
        float salario;
        int opcaoCargo;

        cout << "Dados do funcionario " << numFuncionarios + 1 << endl;
        cout << "Informe o nome: ";
        getline(cin, nome);

        cout << "Informe o salario atual: R$ ";
        cin >> salario;

        opcaoCargo = lerOpcaoCargo();
        string cargoString = converterOpcaoParaCargo(opcaoCargo);

        Funcionario novo(nome, salario, cargoString);

        funcionarios[numFuncionarios] = novo;
        numFuncionarios++;
    }

    void mostrarDadosFuncionarios() const {
        if (numFuncionarios == 0) {
            cout << "\nNenhum funcionario foi cadastrado." << endl;
            return;
        }

        cout << "\n--- Dados dos Funcionarios Cadastrados ---" << endl;
        for (int i = 0; i < numFuncionarios; i++) {
            funcionarios[i].exibirDados();
            cout << "------------------------------------------" << endl;
        }
    }

    void mostrarEstatisticas() const {
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
        cout << "Número de Gerentes: " << numGerentes << endl;
        cout << "Número de Engenheiros: " << numEngenheiros << endl;
        cout << "Custo total atual com salários: R$ " << custoTotalAtual << endl;
        cout << "Custo total após o aumento: R$ " << custoTotalNovo << endl;
    }

    bool limiteAtingido() const {
        return numFuncionarios >= maxFunc;
    }
};

int main() {
    Empresa minhaEmpresa;
    int continuar = 1;

    cout << ">>> CADASTRO DE FUNCIONARIOS E CALCULO DE AUMENTO SALARIAL <<<" << endl;

    do {
        if (minhaEmpresa.limiteAtingido()) {
            cout << "Limite de " << minhaEmpresa.maxFunc << " funcionarios atingido. Encerrando o cadastro." << endl;
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