#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "=== ORDENAMIENTO POR SELECCION ===" << endl;
    cout << "Cuantos numeros quieres ordenar? ";
    cin >> n;

    int numeros[n];

    // Leer números
    cout << "Ingresa " << n << " numeros:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Numero " << (i+1) << ": ";
        cin >> numeros[i];
    }

    // Mostrar array original
    cout << "\nArray original: ";
    for(int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    // Ordenamiento por selección
    for(int i = 0; i < n-1; i++) {
        int min_idx = i;

        // Encontrar el mínimo en el resto del array
        for(int j = i+1; j < n; j++) {
            if(numeros[j] < numeros[min_idx]) {
                min_idx = j;
            }
        }

        // Intercambiar el mínimo con la posición actual
        if(min_idx != i) {
            int temp = numeros[i];
            numeros[i] = numeros[min_idx];
            numeros[min_idx] = temp;
        }

        // Mostrar progreso
        cout << "Paso " << i+1 << ": ";
        for(int k = 0; k < n; k++) {
            cout << numeros[k] << " ";
        }
        cout << endl;
    }

    // Mostrar resultado final
    cout << "\nArray ordenado: ";
    for(int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}
