
#include <iostream>
using namespace std;

int main() {
    int n, buscar;

    cout << "=== BUSQUEDA BINARIA ===" << endl;
    cout << "Cuantos numeros ordenados quieres ingresar? ";
    cin >> n;

    int numeros[n];

    // Pedir números ordenados
    cout << "Ingresa " << n << " numeros ORDENADOS de menor a mayor:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Numero " << (i+1) << ": ";
        cin >> numeros[i];
    }

    cout << "Que numero quieres buscar? ";
    cin >> buscar;

    // Búsqueda binaria
    int izquierda = 0;
    int derecha = n - 1;
    int encontrado = -1;

    while(izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if(numeros[medio] == buscar) {
            encontrado = medio;
            break;
        }

        if(numeros[medio] < buscar) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    // Mostrar resultado
    if(encontrado != -1) {
        cout << "El numero " << buscar << " esta en la posicion " << (encontrado + 1) << endl;
    } else {
        cout << "El numero " << buscar << " no se encontro en el array" << endl;
    }

    return 0;
}
