#include <iostream>
#include <string>
using namespace std;

struct Producto {
    string nombre;
    double precio = 0.0;
    int stock = 0;

    Producto(string n, double p = 0.0, int s = 0) : nombre(n), precio(p), stock(s) {}
};

int main() {
    string nom;
    double pre;
    int st;

    cout << "Producto 1 - Nombre: ";
    cin >> nom;
    Producto p1(nom);

    cout << "Producto 2 - Nombre: ";
    cin >> nom;
    cout << "Precio: ";
    cin >> pre;
    Producto p2(nom, pre);

    cout << "Producto 3 - Nombre: ";
    cin >> nom;
    cout << "Precio: ";
    cin >> pre;
    cout << "Stock: ";
    cin >> st;
    Producto p3(nom, pre, st);


    cout << endl;
    cout << "PRODUCTOS REGISTRADOS" << endl;
    cout << "Producto 1: " << p1.nombre << ", Precio: $" << p1.precio << ", Stock: " << p1.stock << endl;
    cout << "Producto 2: " << p2.nombre << ", Precio: $" << p2.precio << ", Stock: " << p2.stock << endl;
    cout << "Producto 3: " << p3.nombre << ", Precio: $" << p3.precio << ", Stock: " << p3.stock << endl;

    return 0;
}
