#include <iostream>
#include <string>
using namespace std;

// ABSTRAÇÃO: A classe 'Veiculo' é uma abstração. Ela define o conceito geral de um veículo
class Veiculo {
public:
    // Construtor: Inicializa os atributos do objeto.
    Veiculo(const string& marca, const string& modelo, int ano) : marca(marca), modelo(modelo), ano(ano), velocidadeAtual(0) {
        cout << "Um novo veiculo foi criado: " << getDescricao() << endl;
    }

    // MÉTODOS: métodos públicos que definem o comportamento do veículo.
    void acelerar(int aumento) {
        if (aumento > 0) {
            velocidadeAtual += aumento;
            cout << getDescricao() << " acelerou para " << velocidadeAtual << " km/h." << endl;
        }
    }

    void frear(int diminuicao) {
        if (diminuicao > 0 && velocidadeAtual >= diminuicao) {
            velocidadeAtual -= diminuicao;
            cout << getDescricao() << " freou para " << velocidadeAtual << " km/h." << endl;
        }
    }

    // Método virtual puro: Torna 'Veiculo' uma classe abstrata e força as classes filhas a implementarem seu próprio método 'aceleracao()'.
    virtual void aceleracao() const = 0;

    string getDescricao() const {
        return to_string(ano) + " " + marca + " " + modelo; //to_string converte valor numerico para string
    }

    int getVelocidade() const {
        return velocidadeAtual;
    }

private:
    // Atributos privados: eles só podem ser acessados ou modificados através dos métodos da classe, garantindo o encapsulamento.
    std::string marca;
    std::string modelo;
    int ano;
    int velocidadeAtual;
};

// HERANÇA:  'Carro' herda de 'Veiculo', significando que 'Carro' é um tipo de 'Veiculo'.
// Ele herda todos os atributos e métodos da classe base.
class Carro : public Veiculo {
public:
    Carro(const std::string& marca, const std::string& modelo, int ano, int numeroPortas)
        : Veiculo(marca, modelo, ano), numeroPortas(numeroPortas) {}

    // POLIMORFISMO: Sobrescreve o método 'aceleracao()' da classe base, fornecendo uma implementação específica para Carros.
    void aceleracao() const {
        cout << getDescricao() << " Aceleracao de carro (vrum vrum!)." << endl;
    }

    // Atributo específico de Carro
    int getNumeroPortas() const {
        return numeroPortas;
    }

private:
    int numeroPortas;
};

// HERANÇA e POLIMORFISMO:  'Moto' também herda de 'Veiculo', com sua própria implementação.
class Moto : public Veiculo {
public:
    Moto(const string& marca, const string& modelo, int ano, bool escapamento): Veiculo(marca, modelo, ano), escapamento(escapamento) {}

    // Implementação polimórfica de 'aceleracao()' para Motos.
    void aceleracao() const override {
        cout << getDescricao() << " Aceleracao de moto (po-po-po!)." << endl;
    }

private:
    bool escapamento;
};

// FUNÇÃO QUE DEMONSTRA POLIMORFISMO
void testarVeiculo(Veiculo& veiculo) {
    cout << "\n--- Testando o veiculo ---" << endl;
    veiculo.acelerar(50);
    veiculo.frear(20);
    veiculo.aceleracao();
    cout << endl;
}

int main() {
    Carro meuCarro("Fiat", "Mobi", 2022, 4);
    Moto minhaMoto("Honda", "Titan", 2021, true);

    // Usando a função genérica que aceita qualquer 'Veiculo'
    testarVeiculo(meuCarro);
    testarVeiculo(minhaMoto);

    return 0;
}