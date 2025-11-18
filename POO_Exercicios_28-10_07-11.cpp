/*

// Classe Base
class Pessoa // [1] ABSTRAÇÃO
{
protected:
    string nome;      // [2] ENCAPSULAMENTO
    int matricula;    // [3] ENCAPSULAMENTO

public:
    // Construtor
    Pessoa(string nome, int matricula) // [4] CONSTRUTOR
        : nome(nome), matricula(matricula)
};

// Classe Derivada
class Aluno : public Pessoa // [5] HERANÇA
{
private:
    vector<float> notas;
    float media;    // [6] ENCAPSULAMENTO
};

*/

#include <iostream>
using namespace std;


class Calculadora {
public:
    int soma(int x, int y) {
        return x + y;
    }
};

int main() {
    int a, b;
    cout << "Digite dois números inteiros: ";
    cin >> a >> b;

    Calculadora minhaCalculadora;

    // Chamada do método encapsulado através do objeto.
    cout << "Resultado: " << minhaCalculadora.soma(a, b) << endl;
    return 0;
}


/*
1. Um programador de sistemas criou a classe XYZ abaixo, utilizando a linguagem C++
class XYZ{
             private:
                  int H;
                   void G();
              protected:
                    float N;
                    void P();
              public:
                    int R;
                    int T();
         };
Ele vai construir uma outra classe que vai herdar as características da classe XYZ.
Neste caso, essa nova classe pode ter acesso a quais componentes da Classe XYZ?

Resposta: A nova classe terá acesso direto aos membros declarados como public (R e T()) e
protected (N e P()) da classe XYZ. Ela não terá acesso direto aos membros private (H e G()).


2. Observe o seguinte trecho de código de um programa em C++:
class Quadrilatero {
public:
    // Área do quadrado
    // 1. Sobrecarga de 'CalcularArea': Recebe um parâmetro (para a área do quadrado)
    double CalcularArea(double lado) {
        return lado * lado;
    }

    // Área do retângulo
    // 2. Sobrecarga de 'CalcularArea': Recebe dois parâmetros (para a área do retângulo)
    double CalcularArea(double baseMaior, double altura) {
        return baseMaior * altura;
    }
};
Este trecho de código exemplifica o uso de:
a) polimorfismo;
b) herança;
c) sobrecarga; Resposta
d) construtor;
e) classe abstrata.

*/