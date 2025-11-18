#include <iostream>
#include <string>

using namespace std;

// A validação de CPF não é responsabilidade da classe Cliente, mas sim uma utilidade.
string solicitarEValidarCpf();

class Pessoa { //Classe base
    // PRINCÍPIO DE OO: ENCAPSULAMENTO - membros protegidos não podem ser acessados diretamente de fora da classe, mas estão disponíveis para classes derivadas (herança).
protected:
    string nomeCompleto;
    string numeroCpf;

public:
    // Construtor Padrão
    Pessoa() : nomeCompleto("Indefinido"), numeroCpf("Indefinido") {
        //cout << "Pessoa criada (padrao).\n";
    }

    // Construtor com Parametros
    Pessoa(string nomeInicial, string cpfInicial) : nomeCompleto(nomeInicial), numeroCpf(cpfInicial) {
        //cout << "Pessoa criada: " << nomeCompleto << endl;
    }

    // Destrutor Virtual
    // PRINCÍPIO DE OO: POLIMORFISMO/HERANÇA - O destrutor virtual garante a correta destruição de objetos de classes derivadas (ex: Cliente) quando manipulados por um ponteiro ou referência da classe base (Pessoa).
    virtual ~Pessoa() {
        //cout << "Pessoa deletada: " << nomeCompleto << endl;
    }

    // Metodos set
    // PRINCÍPIO DE OO: ENCAPSULAMENTO - Os métodos 'set' fornecem uma interface controlada para modificar os atributos privados/protegidos.
    void setNome(string novoNome) { nomeCompleto = novoNome; }
    void setCpf(string novoCpf) { numeroCpf = novoCpf; }

    // Métodos get
    // PRINCÍPIO DE OO: ENCAPSULAMENTO - Os métodos 'get' fornecem acesso de leitura controlado aos atributos privados/protegidos.
    string getNome() const { return nomeCompleto; }
    string getCpf() const { return numeroCpf; }

    // Metodo virtual para exibir informações
    // PRINCÍPIO DE OO: POLIMORFISMO - O método 'virtual' permite que classes derivadas forneçam sua própria implementação (sobrescrita) desse método.
    virtual void exibirInformacoes() const;
};

// Implementação do metodo exibirInformacoes para Pessoa
void Pessoa::exibirInformacoes() const {
    cout << "\n--- PESSOA ---";
    cout << "\nNome: " << getNome();
    cout << "\nCPF: " << getCpf() << endl;
}


// Classe Cliente (Derivada)
// PRINCÍPIO DE OO: HERANÇA - Cliente herda as características (atributos e métodos) da classe Pessoa.
class Cliente : public Pessoa {
    // PRINCÍPIO DE OO: ENCAPSULAMENTO - membros privados não podem ser acessados diretamente de fora da classe.
private:
    string enderecoEmail;
    int codigoCliente;

public:

    // Construtor Padrão
    Cliente() : Pessoa(), enderecoEmail("Indefinido"), codigoCliente(0) {
        // PRINCÍPIO DE OO: HERANÇA - O construtor da classe base (Pessoa::Pessoa()) é chamado implicitamente (ou explicitamente, como está).
        //cout << "Cliente criado (padrao).\n";
    }

    // Construtor com Parâmetros
    Cliente(string nomeInicial, string cpfInicial, string emailInicial, int codigoInicial)
        // PRINCÍPIO DE OO: HERANÇA - Chamada explícita ao construtor da classe base (Pessoa) para inicializar os atributos herdados.
        : Pessoa(nomeInicial, cpfInicial), enderecoEmail(emailInicial), codigoCliente(codigoInicial)
    {
        cout << "Cliente cadastrado: " << nomeCompleto << endl;
    }

    // Destrutor (com override)
    // PRINCÍPIO DE OO: POLIMORFISMO/HERANÇA - Sobrescreve o destrutor da classe base (Pessoa::~Pessoa()) para garantir o comportamento correto.
    ~Cliente() override {
        //cout << "Cliente deletado: " << nomeCompleto << endl;
    }

    // Métodos set
    // PRINCÍPIO DE OO: ENCAPSULAMENTO - Métodos 'set' para modificar atributos privados.
    void setEmail(string novoEmail) { enderecoEmail = novoEmail; }
    void setCodigo(int novoCodigo) { codigoCliente = novoCodigo; }

    // Métodos get (agora const)
    // PRINCÍPIO DE OO: ENCAPSULAMENTO - Métodos 'get' para acessar atributos privados.
    string getEmail() const { return enderecoEmail; }
    int getCodigo() const { return codigoCliente; }

    // Cadastro separado da responsabilidade da classe
    void lerDadosDeEntrada();

    // Sobrescrita do método virtual para exibir informações
    // PRINCÍPIO DE OO: POLIMORFISMO/SOBRESCRITA (OVERRIDE) - Fornece uma implementação específica para a classe Cliente do método virtual da classe base.
    void exibirInformacoes() const override;
};



// Funções de Utilidade (fora das classes)

string solicitarEValidarCpf() {
    string cpfParaValidar;
    cout << "\nCPF (11 digitos): ";
    cin >> cpfParaValidar;

    // Loop de validação de tamanho
    while (cpfParaValidar.size() != 11) {
        cout << "CPF invalido! O CPF deve ter 11 digitos. Digite novamente: ";
        cin >> cpfParaValidar;
    }
    return cpfParaValidar;
}


void buscarCpfNaLista(const Cliente listaClientes[], int quantidadeClientes) {

    string cpfBusca;
    cout << "\nDigite o CPF para busca: ";
    cin >> cpfBusca;

    bool encontrado = false;
    for (int i = 0; i < quantidadeClientes; i++) {
        if (listaClientes[i].getCpf() == cpfBusca) {
            cout << "\nCPF encontrado para o cliente: " << listaClientes[i].getNome() << ".\n";
            // PRINCÍPIO DE OO: ENCAPSULAMENTO - Utiliza o método público para acessar e exibir a informação.
            listaClientes[i].exibirInformacoes(); // Exibe os dados
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "CPF nao encontrado na lista de clientes!\n";
    }
}


// Implementações da Classe Cliente
void Cliente::lerDadosDeEntrada() {

    int novoCodigo;
    string novoNome, novoCpf, novoEmail;

    cout << "\nCodigo de Perfil do Cliente: ";
    cin >> novoCodigo;
    setCodigo(novoCodigo); // PRINCÍPIO DE OO: ENCAPSULAMENTO - Uso do 'set' para modificação.

    cout << "\nNome Completo: ";
    cin.ignore();
    getline(cin, novoNome);
    setNome(novoNome); // PRINCÍPIO DE OO: ENCAPSULAMENTO/HERANÇA - Uso do 'set' herdado da classe Pessoa.

    novoCpf = solicitarEValidarCpf(); // Chama a função utilitária
    setCpf(novoCpf); // PRINCÍPIO DE OO: ENCAPSULAMENTO/HERANÇA - Uso do 'set' herdado da classe Pessoa.

    cout << "\nEmail: ";
    cin >> novoEmail;
    setEmail(novoEmail); // PRINCÍPIO DE OO: ENCAPSULAMENTO - Uso do 'set' para modificação.
}

// Implementação do método exibirInformacoes para Cliente
void Cliente::exibirInformacoes() const {

    cout << "\n--- CLIENTE CADASTRADO ---\n";
    // PRINCÍPIO DE OO: ENCAPSULAMENTO - Acessa atributos através dos métodos 'get' públicos e 'get' herdados.
    cout << "Codigo: " << getCodigo();
    cout << "\nNome: " << getNome();
    cout << "\nCPF: " << getCpf();
    cout << "\nEmail: " << getEmail() << endl;
}


int main() {

    Cliente listaClientes[100]; // PRINCÍPIO DE OO: ABSTRAÇÃO - O array manipula objetos do tipo Cliente.
    int opcaoMenu;
    int contadorClientesCadastrados = 0;

    do {
        cout << "\n\n======== MENU ========";
        cout << "\n1 - Cadastrar Novo Cliente";
        cout << "\n2 - Buscar Cliente por CPF";
        cout << "\n3 - Exibir Todos os Clientes";
        cout << "\n4 - Sair do Programa";

        cout << "\n\nOpcao Desejada: ";

        if (!(cin >> opcaoMenu)) {
            cout << "Entrada invalida. Saindo...\n";
            break;
        }

        switch (opcaoMenu) {

            case 1:
                if (contadorClientesCadastrados < 100) {
                    // PRINCÍPIO DE OO: ENCAPSULAMENTO - O objeto Cliente é responsável por ler e armazenar seus próprios dados.
                    listaClientes[contadorClientesCadastrados].lerDadosDeEntrada();
                    contadorClientesCadastrados++;
                } else {
                    cout << "Limite de clientes cadastrados atingido (100).\n";
                }
                break;

            case 2:
                if (contadorClientesCadastrados > 0) {
                    buscarCpfNaLista(listaClientes, contadorClientesCadastrados);
                } else {
                    cout << "Nenhum cliente cadastrado ainda.\n";
                }
                break;

            case 3:
                if (contadorClientesCadastrados > 0) {
                    cout << "\n--- LISTA DE CLIENTES ---\n";
                    for (int i = 0; i < contadorClientesCadastrados; i++) {
                        // PRINCÍPIO DE OO: POLIMORFISMO/SOBRESCRITA (IMPLÍCITO) - O método exibido é o específico de Cliente.
                        listaClientes[i].exibirInformacoes();
                    }
                } else {
                    cout << "Nenhum cliente cadastrado para exibir.\n";
                }
                break;

            case 4:
                cout << "Encerrando o programa...\n";
                break;

            default:
                cout << "Opcao invalida! Tente novamente.\n";
        }

    } while (opcaoMenu != 4);

    return 0;
}