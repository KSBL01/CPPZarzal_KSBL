#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

struct Producto {
    string nombre;
    double precio = 0.0;
    int stock = 0;

    Producto(string n, double p = 0.0, int s = 0) : nombre(n), precio(p), stock(s) {}

    bool operator==(const Producto& otro) const {
        string n1 = nombre;
        string n2 = otro.nombre;
        transform(n1.begin(), n1.end(), n1.begin(), ::tolower);
        transform(n2.begin(), n2.end(), n2.begin(), ::tolower);
        return n1 == n2;
    }

    bool operator<(const Producto& otro) const {
        if(precio != otro.precio) return precio < otro.precio;
        return nombre < otro.nombre;
    }
};

int main() {
    vector<Producto> productos = {
        Producto("Zapato", 50.0, 3),
        Producto("Camisa", 25.0, 5),
        Producto("Pantalon", 25.0, 2),
        Producto("Gorra", 15.0, 8)
    };

    sort(productos.begin(), productos.end());

    for(const auto& p : productos) {
        cout << p.nombre << " " << p.precio << endl;
    }

    Producto buscar("CAMISA", 0, 0);
    auto it = find(productos.begin(), productos.end(), buscar);
    if(it != productos.end()) {
        cout << "Encontrado: " << it->nombre << endl;
    }

    return 0;
}
