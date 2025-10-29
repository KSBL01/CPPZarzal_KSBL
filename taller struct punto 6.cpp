#include <iostream>
using namespace std;

struct Fraccion {
    int numerador;
    int denominador;

    Fraccion(int num, int den) : numerador(num), denominador(den) {}

    Fraccion simplificar() const {
        int a = numerador;
        int b = denominador;
        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return Fraccion(numerador/a, denominador/a);
    }

    void imprimir() const {
        cout << numerador << "/" << denominador << endl;
    }

    Fraccion operator+(const Fraccion& otra) const {
        int num = numerador * otra.denominador + otra.numerador * denominador;
        int den = denominador * otra.denominador;
        return Fraccion(num, den).simplificar();
    }
};

int main() {
    int num1, den1, num2, den2;

    cout << "Fraccion 1 - Numerador: ";
    cin >> num1;
    cout << "Denominador: ";
    cin >> den1;

    cout << "Fraccion 2 - Numerador: ";
    cin >> num2;
    cout << "Denominador: ";
    cin >> den2;

    Fraccion f1(num1, den1);
    Fraccion f2(num2, den2);
    Fraccion f3 = f1 + f2;

    cout << "Suma: ";
    f3.imprimir();

    Fraccion f4 = f1.simplificar();
    cout << "Simplificada 1: ";
    f4.imprimir();

    Fraccion f5 = f2.simplificar();
    cout << "Simplificada 2: ";
    f5.imprimir();

    return 0;
}
