#include <iostream>
#include <string>
using namespace std;

// A classe base 'Veiculo' é uma abstração. Ela define as características
// e comportamentos comuns a todos os veículos, como a marca, modelo e a velocidade.
class Veiculo {
public:
    // O construtor inicializa os atributos de um objeto Veiculo.
    Veiculo(string marca, string modelo, int velocidadeMaxima) : marca(marca), modelo(modelo), velocidadeMaxima(velocidadeMaxima), velocidadeAtual(0) {}

    // ENCAPSULAMENTO: Métodos públicos (getters e setters) que controlam o acesso aos atributos internos
    string getMarca() const {
        return marca;
    }

    string getModelo() const {
        return modelo;
    }

    int getVelocidadeAtual() const {
        return velocidadeAtual;
    }

    // MÉTODOS
    void acelerar() {
        velocidadeAtual += 10;
        if (velocidadeAtual > velocidadeMaxima) { //para que o carro não ultrapasse a vel max
            velocidadeAtual = velocidadeMaxima;
        }
        cout << marca << " " << modelo << " Acelerando. Velocidade atual: " << velocidadeAtual << " km/h." << endl;
    }

    void frear() {
        velocidadeAtual -= 5; // para que a velocidade não se torne negativa
        if (velocidadeAtual < 0) {
            velocidadeAtual = 0;
        }
        cout << marca << modelo << " freando. Velocidade atual: " << velocidadeAtual << " km/h." << endl;
    }

    void buzinar() const {
        cout << "Som generico de buzina." << endl;
    }

protected:
    string marca;
    string modelo;
    int velocidadeMaxima;
    int velocidadeAtual;
};

// HERANÇA: 'Carro' herda de 'Veiculo'
// 'Carro' é um tipo específico de 'Veiculo'. Ele herda os atributos e métodos da classe base e pode adicionar os seus próprios
class Carro : public Veiculo {
public:
    // O construtor de 'Carro' chama o construtor de 'Veiculo' para inicializar
    Carro(string marca, string modelo) : Veiculo(marca, modelo, 200) {}

    // POLIMORFISMO: Implementação específica do método 'buzinar', obrigatória para a classe 'Carro'.
    void buzinar() const {
        cout << "Som de buzina de carro: Bi-bi!" << endl;
    }
};

// HERANÇA: 'Moto' herda de 'Veiculo'
// 'Moto' é outro tipo de 'Veiculo' com suas próprias características.
class Moto : public Veiculo {
public:
    Moto(string marca, string modelo) : Veiculo(marca, modelo, 160) {}

    // POLIMORFISMO: Implementação específica do método 'buzinar()' para a 'Moto'.
    void buzinar() const {
        cout << "Som de buzina de moto: Fom-fom!" << endl;
    }
};


int main() {
    //OBJETO: criação de objetos (instâncias) das classes 'Carro' e 'Moto'.

    Carro meuCarro("Toyota ", "Hilux" );
    Moto minhaMoto("Honda ", "Fan 160");

    cout << "Simulacao com o veiculo " << meuCarro.getMarca() << meuCarro.getModelo() << endl;
    meuCarro.acelerar();
    meuCarro.acelerar();
    meuCarro.buzinar();
    meuCarro.frear();

    cout << endl;

    cout << "Simulacao com o veiculo " << minhaMoto.getMarca() << minhaMoto.getModelo() << endl;
    minhaMoto.acelerar();
    minhaMoto.acelerar();
    minhaMoto.buzinar();
    minhaMoto.frear();

    return 0;
}