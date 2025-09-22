#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "=== ENCONTRAR LA MEDIANA DE UN ARRAY ===" << endl;
    cout << "Cuantos numeros quieres ingresar? ";
    cin >> n;

    float numeros[n];

    // Pedir los números al usuario
    cout << "Ingresa " << n << " numeros:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Numero " << (i+1) << ": ";
        cin >> numeros[i];
    }

    // Ordenar el array (método burbuja simple)
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(numeros[j] > numeros[j+1]) {
                float temp = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = temp;
            }
        }
    }

    // Calcular la mediana
    float mediana;
    if(n % 2 == 0) {
        // Si es par, promedio de los dos del medio
        mediana = (numeros[n/2 - 1] + numeros[n/2]) / 2.0;
    } else {
        // Si es impar, el del medio
        mediana = numeros[n/2];
    }

    // Mostrar resultados
    cout << "\nArray ordenado: ";
    for(int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }
    cout << "\nLa mediana es: " << mediana << endl;

    return 0;
}
