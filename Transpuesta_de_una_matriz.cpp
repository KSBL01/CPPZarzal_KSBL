#include <iostream>
using namespace std;

int main() {
    int filas, columnas;

    cout << "=== TRANSPUESTA DE UNA MATRIZ ===" << endl;
    cout << "Ingresa el numero de filas: ";
    cin >> filas;
    cout << "Ingresa el numero de columnas: ";
    cin >> columnas;

    int matriz[filas][columnas];
    int transpuesta[columnas][filas];

    // Leer la matriz
    cout << "\nIngresa los elementos de la matriz:" << endl;
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i+1 << "][" << j+1 << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Calcular transpuesta
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }

    // Mostrar matriz original
    cout << "\nMatriz original:" << endl;
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    // Mostrar matriz transpuesta
    cout << "\nMatriz transpuesta:" << endl;
    for(int i = 0; i < columnas; i++) {
        for(int j = 0; j < filas; j++) {
            cout << transpuesta[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
