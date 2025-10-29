#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Producto {
    string codigo;
    string nombre;
    double precio;
    int stock;
    string categoria;

    Producto(string c, string n, double p, int s, string cat)
        : codigo(c), nombre(n), precio(p), stock(s), categoria(cat) {}
};

struct Inventario {
    vector<Producto> productos;

    void agregar(Producto p) {
        productos.push_back(p);
    }

    bool vender(string codigo, int cantidad) {
        for(auto& p : productos) {
            if(p.codigo == codigo && p.stock >= cantidad) {
                p.stock -= cantidad;
                return true;
            }
        }
        return false;
    }

    void reponer(string codigo, int cantidad) {
        for(auto& p : productos) {
            if(p.codigo == codigo) {
                p.stock += cantidad;
                return;
            }
        }
    }

    void mostrar() const {
        for(const auto& p : productos) {
            cout << p.codigo << " " << p.nombre << " " << p.precio;
            cout << " " << p.stock << " " << p.categoria << endl;
        }
    }
};

int main() {
    Inventario inv;
    int opcion;

    do {
        cout << "1. Agregar 2. Vender 3. Reponer 4. Mostrar 5. Salir: ";
        cin >> opcion;

        if(opcion == 1) {
            string cod, nom, cat;
            double pre;
            int st;

            cout << "Codigo: ";
            cin >> cod;
            cout << "Nombre: ";
            cin >> nom;
            cout << "Precio: ";
            cin >> pre;
            cout << "Stock: ";
            cin >> st;
            cout << "Categoria: ";
            cin >> cat;

            inv.agregar(Producto(cod, nom, pre, st, cat));
        }
        else if(opcion == 2) {
            string cod;
            int cant;
            cout << "Codigo a vender: ";
            cin >> cod;
            cout << "Cantidad: ";
            cin >> cant;

            if(inv.vender(cod, cant)) {
                cout << "Venta exitosa" << endl;
            } else {
                cout << "Error en venta" << endl;
            }
        }
        else if(opcion == 3) {
            string cod;
            int cant;
            cout << "Codigo a reponer: ";
            cin >> cod;
            cout << "Cantidad: ";
            cin >> cant;

            inv.reponer(cod, cant);
            cout << "Reposicion completa" << endl;
        }
        else if(opcion == 4) {
            inv.mostrar();
        }
    } while(opcion != 5);

    return 0;
}
