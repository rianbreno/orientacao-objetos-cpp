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
    cout << "Área do círculo: " << c.calcularArea() << endl;
    return 0;
}
