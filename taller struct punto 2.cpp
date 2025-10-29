
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Producto {
    string nombre;
    double precio = 0.0;
    int stock = 0;

    Producto(string n, double p = 0.0, int s = 0) : nombre(n), precio(p), stock(s) {}

    bool disponible() const {
        return stock > 0;
    }

    bool esValido() const {
        return precio >= 0 && !nombre.empty();
    }
};

int main() {
    vector<Producto> productos = {
        Producto("", 2.5, 3),
        Producto("Libro", -1.0, 5),
        Producto("Goma", 1.0, 0),
        Producto("Boligrafo", 2.0, 10)
    };

    productos.erase(
        remove_if(productos.begin(), productos.end(),
            [](const Producto& p) { return !p.esValido(); }),
        productos.end()
    );

    for(const auto& p : productos) {
        cout << p.nombre << " " << p.precio << " " << p.stock;
        cout << " Disponible: " << p.disponible() << endl;
    }

    return 0;
}
