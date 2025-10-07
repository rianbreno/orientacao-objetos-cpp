#include <iostream>
#include <string>
using namespace std;

class contaBancaria {
    public:
        contaBancaria(string titular, double saldoInicial) : titular(titular), saldo(saldoInicial) {}
    string getTitular() const{
            return titular;
        }
    double getSaldo() const {
            return saldo;
        }

    void setTitular(const string& novoTitular) {
            if (!novoTitular.empty()) { // (!) not, para evitar nomes vazios
                titular = novoTitular;
                cout << "Nome do titular alterado para: " << titular << endl;
            } else {
                cout << "Erro: titular não pode ser vazio." << endl;
            }
        }

    void depositar(double valor) {
            if (valor > 0) {
                saldo += valor;
                cout << "Deposito de R$" << valor << " realizado." << endl;
            } else {
                cout << "Valor de deposito invalido." << endl;
            }
        }

    void sacar(double valor) {
            if (valor > 0 && valor <= saldo) {
                saldo -= valor;
                cout << "Saque de R$" << valor << " realizado." << endl;
            } else {
                cout << "Saldo insuficiente ou valor invalido." << endl;
            }
        }

    protected: //só podem ser acessados pela propria classe e por classe que herdam dela
        string titular;
        double saldo;
};

class ContaCorrente : public contaBancaria { //herda contaBancaria, contaCorrente é um tipo de contaBancaria e herda todos membros publicos e protegidos
    private:
        double limiteChequeEspecial;
    public:
        ContaCorrente(string titular, double saldoInicial, double limite) : contaBancaria(titular, saldoInicial), limiteChequeEspecial(limite) {}

    void sacar(double valor) {
            if (valor > 0 && valor <= (saldo + limiteChequeEspecial)) {
                saldo -= valor;
                cout << "Saque de R$" << valor << " realizado. Saldo atual: R$" << saldo << " (com cheque especial)." << endl;
            } else {
                cout << "Saldo e limite de cheque especial insuficientes." << endl;
            }
        }
};

class ContaPoupanca : public contaBancaria { //contaPoupanca herda contaBancaria
private:
    double taxaRendimento;

public:
    ContaPoupanca(string titular, double saldoInicial, double taxa) : contaBancaria(titular, saldoInicial), taxaRendimento(taxa) {}

    void aplicarRendimento() {
        saldo += saldo * taxaRendimento;
        cout << "Rendimento aplicado. Novo saldo: R$" << getSaldo() << endl;
    }
};

int main() {
    //cria um ponteiro para classe contaBancaria
    //que pode apontar p/ objetos de classes que herde contaBancaria
    contaBancaria* contaJoao = new contaBancaria("Joao", 1000);

    cout << "Dados do cliente " << contaJoao->getTitular() << endl;
    cout << "Saldo: R$ " << contaJoao->getSaldo() << endl;

    contaJoao->sacar(600);
    cout << "Novo saldo: R$ " << contaJoao->getSaldo() << endl;

    contaJoao->setTitular("Joao dos Santos");



    /*
    contaBancaria contaJoao("Joao", 500);

    // Usa o operador de ponto (.) para acessar os membros do objeto.
    cout << "Informacoes: " << contaJoao.getTitular() << endl;
    cout << "Saldo: R$" << contaJoao.getSaldo() << endl;

    contaJoao.sacar(600);
    cout << "Novo saldo: R$" << contaJoao.getSaldo() << endl;

    contaJoao.setTitular("Joao dos Santos");

    return 0;
    */

    return 0;
}