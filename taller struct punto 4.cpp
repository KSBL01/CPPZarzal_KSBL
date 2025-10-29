#include <iostream>
#include <vector>
using namespace std;

struct Polinomio {
    vector<double> coeficientes;

    Polinomio(vector<double> coefs) : coeficientes(coefs) {}

    double evaluar(double x) const {
        double resultado = 0;
        double potencia = 1;
        for(double coef : coeficientes) {
            resultado += coef * potencia;
            potencia *= x;
        }
        return resultado;
    }

    void imprimir() const {
        for(int i = 0; i < coeficientes.size(); i++) {
            cout << coeficientes[i];
            if(i > 0) cout << "x^" << i;
            if(i < coeficientes.size() - 1) cout << " + ";
        }
        cout << endl;
    }
};

int main() {
    Polinomio p({2.0, 3.0, 1.0});
    p.imprimir();
    cout << "P(2) = " << p.evaluar(2.0) << endl;
    return 0;
}
