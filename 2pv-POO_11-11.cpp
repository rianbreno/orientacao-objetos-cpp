#include <iostream>
#include <string>
#include <vector>

using namespace std;

// CLASSE ABSTRATA: sistemaAcademico
class sistemaAcademico {
public:
    virtual ~sistemaAcademico() {}

    virtual float calcularMedia() const = 0;

    virtual void exibirDados() const = 0;
};

// CLASSE CONCRETA: Aluno
class Aluno : public sistemaAcademico {
private:
    int matricula;
    string nome;
    float notas[3];

public:
    // Construtor Padrão
    Aluno() : matricula(0), nome(""), notas{0.0, 0.0, 0.0} {}

    // Construtor Parametrizado
    Aluno(int mat, const string& n, float n1, float n2, float n3)
        : matricula(mat), nome(n) {
        notas[0] = n1;
        notas[1] = n2;
        notas[2] = n3;
    }

    void lerDados() {
        cout << "Matricula: ";
        cin >> matricula;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);

        cout << "Digite as 3 notas:\n";
        for (int j = 0; j < 3; j++) {
            cout << "Nota " << (j + 1) << ": ";
            cin >> notas[j];
        }
    }

    float calcularMedia() const override {
        return (notas[0] + notas[1] + notas[2]) / 3;
    }

    // Implementação da função virtual para exibir dados
    void exibirDados() const override {
        cout << "Matricula: " << matricula
             << " | Nome: " << nome
             << " | Media: " << calcularMedia() << endl;
    }
};


int main() {
    int numAlunos;

    cout << "--- Gerenciamento de Notas de Alunos ---\n";
    cout << "Digite o numero de alunos: ";
    cin >> numAlunos;

    if (numAlunos <= 0) {
        cout << "Numero de alunos invalido. Encerrando." << endl;
        return 1;
    }

    // Alocação Dinâmica de Memória
    Aluno* alunos = new Aluno[numAlunos];
    float somaMedias = 0.0;
    const float MEDIA_SUFICIENTE = 7.0;

    // 1. Leitura dos dados dos alunos
    cout << "\n--- Insercao de Dados ---\n";
    for (int i = 0; i < numAlunos; i++) {
        cout << "\nAluno " << (i + 1) << ":\n";
        alunos[i].lerDados();
        somaMedias += alunos[i].calcularMedia();
    }

    // 2. Cálculo e exibição da media da turma
    float mediaTurma = somaMedias / numAlunos;
    cout << "\n--- Resultados ---\n";
    cout << "Media Geral da Turma: " << mediaTurma << endl;

    // 3. Exibição dos alunos que obtiveram notas acima da media 7
    cout << "\nAlunos APROVADOS (Media > " << MEDIA_SUFICIENTE << "):\n";
    bool encontrouAcimaMedia = false;
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].calcularMedia() > MEDIA_SUFICIENTE) {
            alunos[i].exibirDados();
            encontrouAcimaMedia = true;
        }
    }

    if (!encontrouAcimaMedia) {
        cout << "Nenhum aluno com media acima de " << MEDIA_SUFICIENTE << ".\n";
    }

    cout << "\nPrograma finalizado." << endl;
    return 0;
}