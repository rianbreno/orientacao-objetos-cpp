/*
 CLASSES

1. Defina o conceito de classe em C++ e explique o papel do encapsulamento.
Classe é como se fosse um molde que define a estrutura, cria-se um novo tipo de dado personalizado. Um objeto é uma instância (uma cópia concreta) dessa classe.
O encapsulamento é agrupar os dados e as funções que manipulam esses dados em uma única unidade (a classe). Ele também protege a integridade dos dados, restringindo o acesso direto aos atributos e permitindo que eles sejam modificados apenas por meio dos métodos da classe. Isso evita que os dados sejam corrompidos por acessos externos não autorizados.

2. Explique a diferença entre membros públicos, privados e protegidos em uma classe.
Públicos (public): Membros acessíveis de qualquer lugar, tanto dentro da classe quanto fora dela.
Privados (private): Membros acessíveis apenas de dentro da própria classe. Geralmente, os atributos são declarados como privados para garantir o encapsulamento.
Protegidos (protected): Membros acessíveis de dentro da classe e por classes que herdam dela (classes derivadas). Eles não podem ser acessados diretamente de fora da classe.


3. O que é uma função construtora? Por que ela é importante em uma classe?
Uma  é um método especial qufunção construtora é chamada automaticamente quando um objeto de uma classe é criado. Seu principal objetivo é inicializar os atributos do objeto.
Ela tem o mesmo nome da classe.
Não tem tipo de retorno, nem mesmo void.
Pode ter parâmetros para inicializar o objeto com valores específicos.
É importante porque garante que um objeto seja sempre criado em um estado válido, evitando a necessidade de inicializações manuais e propensas a erros.


4. O que é um destrutor e quando ele é chamado?
Um destrutor é um método que é chamado automaticamente quando um objeto é destruído (por exemplo, quando ele sai de escopo ou é explicitamente deletado).
Seu nome é o da classe precedido por um til (~). Ex: ~MinhaClasse().
Não aceita parâmetros e não tem tipo de retorno.
O destrutor é usado para liberar recursos que o objeto possa ter alocado, como memória dinâmica, descritores de arquivos ou conexões de rede. Isso evita vazamentos de memória e outros recursos.


5. Diferencie um objeto alocado na pilha de um alocado no heap.
A forma como um objeto é alocado determina quando ele é destruído.
Pilha (stack): A alocação é feita de forma automática e rápida. O objeto é criado e destruído automaticamente quando a função ou bloco de código onde ele foi declarado termina. A alocação na pilha é ideal para objetos pequenos e de curta duração.
Heap (heap): A alocação é feita dinamicamente em tempo de execução, usando os operadores new e delete. Isso permite criar objetos cujo tempo de vida não está restrito ao escopo de uma função. O programador é responsável por liberar a memória com delete quando o objeto não é mais necessário. A não liberação resulta em vazamento de memória.


6. Explique o funcionamento do operador this em C++ e sua utilidade.
O operador this é um ponteiro que aponta para o próprio objeto no qual a função-membro está sendo chamada. Ele permite que uma função-membro acesse o objeto que a chamou.
Sua utilidade principal é:
Diferenciar o nome de um atributo de um parâmetro de função, como em this->nome = nome;.
Permitir que um método retorne uma referência ou ponteiro para o próprio objeto, o que é útil para encadear chamadas de método.


7. Qual a diferença entre uma função-membro estática e uma não estática?
Função-membro não estática: É associada a uma instância específica da classe. Para chamá-la, você precisa de um objeto dessa classe. Ela tem acesso aos atributos e métodos não estáticos da classe.
Função-membro estática (static): Pertence à classe como um todo, e não a um objeto específico. Pode ser chamada mesmo sem a criação de nenhum objeto da classe. Ela não tem acesso direto aos atributos não estáticos da classe, apenas aos atributos estáticos e outras funções estáticas.


8. Discuta os benefícios da declaração inline de funções em C++.
A palavra-chave inline é uma sugestão para o compilador substituir a chamada de uma função pelo corpo da própria função. Isso pode otimizar o código, eliminando a sobrecarga de uma chamada de função, o que é especialmente útil para funções pequenas e frequentemente chamadas. O compilador pode ignorar a sugestão inline se a função for muito grande.


9. O que caracteriza uma função-membro constante em C++?
Uma função-membro constante é aquela que não modifica o estado do objeto (seus atributos). Ela é declarada com a palavra-chave const após a lista de parâmetros.
void metodoConstante() const;
É importante para garantir a segurança do código, pois o compilador impede que essa função altere qualquer atributo da classe. Você pode chamar uma função constante em um objeto const.


10.Como uma classe friend pode acessar membros privados de outra classe?
Uma classe friend (amiga) é uma classe que tem permissão para acessar os membros privados e protegidos de outra classe. A amizade não é mútua, a menos que seja explicitamente declarada. Para isso, você precisa declarar a classe amiga dentro da classe que concede a permissão.

class MinhaClasse {
    private:
  	int atributoPrivado;
  	friend class ClasseAmiga; // ClasseAmiga pode acessar atributoPrivado
};


11. Explique como as classes aninhadas podem ser usadas em C++.
Uma classe aninhada é uma classe declarada dentro do escopo de outra classe. A classe aninhada é um membro da classe que a contém, e seu nome está restrito ao escopo da classe externa.
A classe aninhada pode ser usada para agrupar classes que estão intimamente relacionadas, melhorando a organização do código.
A classe aninhada não tem acesso automático aos membros privados da classe externa. Para isso, ela precisaria ser declarada como uma classe friend da classe externa.


QUESTÕES PRATICAS DE CLASSES
1. Implemente uma classe chamada Rectangle com atributos de largura e altura, incluindo métodos para calcular área e perímetro.

#include <iostream>
using namespace std;


class Retangulo {
private:
   double largura;
   double altura;

public:
   Retangulo(double l, double h) : largura(l), altura(h) {}

   double calcularArea() {
       return largura * altura;
   }

   double calcularPerimetro() {
       return 2 * (largura + altura);
   }
};


int main() {
   Retangulo newRetangulo(10.0, 5.0);
   cout << "Area: " << newRetangulo.calcularArea() << endl;
   cout << "Perimetro: " << newRetangulo.calcularPerimetro() << endl;

   return 0;
}


2. Crie uma classe que utilize o operador this para diferenciar entre membros da classe e parâmetros de função.

#include <iostream>
#include <string>
using namespace std;

class Pessoa {
private:
   string nome;

public:
   void definirNome(string nome) { //set
       this->nome = nome;
   }
   string printNome() { //get
       return this->nome;
   }
};

int main() {
   Pessoa p;

   p.definirNome("Maria");

   cout << "Nome: " << p.printNome() << endl;

   return 0;
}


3. Escreva um programa que demonstre o uso de uma função construtora com parâmetros padrão.

#include <iostream>
using namespace std;

class Caixa {
private:
    double comprimento;
    double largura;

public:
 Caixa(double c = 10.0, double l = 5.0) : comprimento(c), largura(l) {

cout << "Caixa criada com comprimento " << comprimento << " e largura " << largura << endl;
    }
};

int main() {
    Caixa c1(20.0, 15.0);
    Caixa c2; // cria com o padrao do construtor
    return 0;
}


4. Implemente uma classe que aloque memória dinamicamente no heap e libere-a na função destrutora.

#include <iostream>

class ArrayDinamico {
private:
    int* dados;
    size_t tamanho;

public:
    ArrayDinamico(size_t t) : tamanho(t) {
        dados = new int[tamanho];
        std::cout << "Array de tamanho " << tamanho << " alocado." << std::endl;
    }

    ~ArrayDinamico() {
        delete[] dados;
        std::cout << "Array desalocado." << std::endl;
    }
};

int main() {
    ArrayDinamico* meuArray = new ArrayDinamico(5);

    delete meuArray;
    return 0;
}

5. Utilize funções inline para definir métodos de cálculo rápido, como a soma de dois números em uma classe Math.

#include <iostream>
using namespace std;

class Matematica {
public:
    inline int somar(int n1, int n2) {
        return n1 + n2;
    }
};

int main() {
    Matematica m;

    cout << "Soma: " << m.somar(10, 25) << endl;

    return 0;
}


6. Crie uma função-membro estática para contar quantos objetos de uma classe foram criados.

#include <iostream>
using namespace std;

class MinhaClasse {
private:
    static int contadorObj;

public:
    MinhaClasse() {
        contadorObj++;
    }

    ~MinhaClasse() {
        contadorObj--;
    }

    static int obterContadorObj() {
        return contadorObj;
    }
};

int MinhaClasse::contadorObj = 0;

int main() {
    MinhaClasse obj1;
    MinhaClasse obj2;

cout << "Objetos criados: " << MinhaClasse::obterContadorObj() << endl;

    MinhaClasse obj3;

cout << "Objetos criados: " << MinhaClasse::obterContadorObj() << endl;

    return 0;
}


7. Implemente uma função constante em uma classe que apenas leia e retorne valores de atributos.

#include <iostream>
using namespace std;

class Coordenadas {
private:
    int x;
    int y;
public:
    Coordenadas(int x, int y) : x(x), y(y) {}

    void imprimirCoordenadas() const {
        cout << "Coordenadas: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Coordenadas c(50, 75);
    c.imprimirCoordenadas();
    return 0;
}

8. Declare uma classe com um método friend que calcule o dobro do atributo privado de outra classe.

#include <iostream>
using namespace std;

class NumeroSecreto {
private:
    int numero;
public:
    NumeroSecreto(int n) : numero(n) {}
    friend class DobradorAmigo;
};

class DobradorAmigo {
public:
    int dobrarNumero(NumeroSecreto ns) {
        return ns.numero * 2;
    }
};

int main() {
    NumeroSecreto secreto(8);
    DobradorAmigo dobrador;
    cout << "O dobro do numero secreto e: " << dobrador.dobrarNumero(secreto) << endl;
    return 0;
}


9. Implemente uma classe aninhada com um método que interage com sua classe externa.

#include <iostream>
using namespace std;

class Externa {
private:
    int dadoExterno;

    public:
    Externa(int d) : dadoExterno(d) {}


    class Interna {
    private:
        Externa* ponteiroExterna;
    public:
        Interna(Externa* e) : ponteiroExterna(e) {}
        void imprimirDadoExterno() {
            cout << "Dados da classe externa: " << ponteiroExterna->dadoExterno << endl;
        }
    };
};


int main() {
    Externa objetoExterno(200);
    Externa::Interna objetoInterno(&objetoExterno);
    objetoInterno.imprimirDadoExterno();
    return 0;
}

10. Implemente uma classe Circle que calcule a área usando uma função-membro inline

#include <iostream>
using namespace std;


class Circulo {
private:
    double raio;
    const double PI = 3.14159;


public:
    Circulo(double r) : raio(r) {}


    inline double calcularArea() {
        return PI * raio * raio;
    }
};


int main() {
    Circulo c(7.5);
    cout << "Area do circulo: " << c.calcularArea() << endl;
    return 0;
}

*/