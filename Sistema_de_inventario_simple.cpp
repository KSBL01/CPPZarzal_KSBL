#include <iostream>
using namespace std;

int main() {
    const int MAX_PRODUCTOS = 100;
    string productos[MAX_PRODUCTOS];
    int cantidades[MAX_PRODUCTOS];
    int precios[MAX_PRODUCTOS];
    int totalProductos = 0;
    int opcion;

    cout << "=== SISTEMA DE INVENTARIO SIMPLE ===" << endl;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Mostrar inventario" << endl;
        cout << "3. Buscar producto" << endl;
        cout << "4. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                if(totalProductos < MAX_PRODUCTOS) {
                    cout << "Nombre del producto: ";
                    cin >> productos[totalProductos];
                    cout << "Cantidad: ";
                    cin >> cantidades[totalProductos];
                    cout << "Precio: ";
                    cin >> precios[totalProductos];
                    totalProductos++;
                    cout << "Producto agregado!" << endl;
                } else {
                    cout << "Inventario lleno!" << endl;
                }
                break;
            }

            case 2: {
                cout << "\n--- INVENTARIO ---" << endl;
                cout << "Producto\tCantidad\tPrecio" << endl;
                for(int i = 0; i < totalProductos; i++) {
                    cout << productos[i] << "\t\t" << cantidades[i] << "\t\t$" << precios[i] << endl;
                }
                break;
            }

            case 3: {
                string buscar;
                cout << "Nombre del producto a buscar: ";
                cin >> buscar;

                bool encontrado = false;
                for(int i = 0; i < totalProductos; i++) {
                    if(productos[i] == buscar) {
                        cout << "Producto: " << productos[i] << endl;
                        cout << "Cantidad: " << cantidades[i] << endl;
                        cout << "Precio: $" << precios[i] << endl;
                        encontrado = true;
                        break;
                    }
                }

                if(!encontrado) {
                    cout << "Producto no encontrado!" << endl;
                }
                break;
            }

            case 4:
                cout << "Saliendo del sistema..." << endl;
                break;

            default:
                cout << "Opcion invalida!" << endl;
        }

    } while(opcion != 4);

    return 0;
}
